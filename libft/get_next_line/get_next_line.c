/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:30:22 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 23:29:39 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
new_line_found
----------------------------------
This little but powerful function will try to find a new line in the buffer, if it finds one it will
copy up until the next_line and concatenate whatever is copied to *line using ft_strjoin.
Any remainder is saved on the static buffer and the new line will be the first characted so our function
can verify this in the very beginning of get_next_line on the next call.
If mallocation goes wrong 0 is returned, which should trigger the other functions to tell get_next_line to return -1. 
*/
static size_t	new_line_found(char **line, char *buffer, size_t size)
{
	char	*newline;

	newline = buffer;
	while (*newline != '\0' && size != 42)
	{
		if (*newline == '\n')
			size = 42;
		newline++;
	}
	if (size == 42)
		newline--;
	if (*newline != '\n')
		newline = NULL;
	if (newline == NULL)
		return (0);
	*newline = '\0';
	*line = ft_strjoin_mod(*line, buffer, 0, 0);
	if (*line == NULL)
		return (2);
	*newline = '\n';
	size = ft_strlen(newline);
	ft_memmove(buffer, newline, size);
	buffer[size] = '\0';
	return (1);
}
/*
read_cycle(fd, line, buffer)
----------------------------------
This is the function where the read() function is executed in a loop until it finds a new line.
The call on new_line_found will try to find a new line and if it does it will set the remainder on the static buffer to where it left off and concatenate to *line until new line.
If a new line isn't found it will loop until it fills *line until the next line or until we've reached end of file, in which case it will return 0.
*/
static int	read_cycle(int fd, char **line, char *buffer)
{
	int		read_result;
	size_t		is_line;

	read_result = 1;
	while (read_result > 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result < 0)
			return (-1);
		buffer[read_result] = '\0';
		is_line = new_line_found(line, buffer, 0);
		if (is_line)
			if (is_line == 2)
				return (-1);
			else
				return (1);
		else
		{
			*line = ft_strjoin_mod(*line, buffer, 0, 0);
			if (!(*line))
				return (-1);
		}
	}
	return (read_result > 0 ? 1 : 0);
}
/*
check_remainder(line, buffer, read_result, i);
----------------------------------
This function will move buffer one space to the right using ft_memmove to access the first character after the new line on the static buffer,
which is where the remainder is stored when there is any. 
It will then check if there's a new line within the stored remainder using new_line_found()
In case there is, the call to new_line_found will also set the remainder on buffer to it's new value
and concatenate to *line up until the new line.
The function continues and sets the read_result to it's corresponding state, if anything fails -1 is returned.
In case a new line isn't found then the remainder is concatenated to *line and it returns 0, which will let get_next_line know that another read_cycle is needed.
*/

static int	check_buffer(char **line, char *buffer, int *read_result, size_t i)
{
	char *temp;

	temp = buffer;
	temp++;
	i = ft_strlen(temp);
	ft_memmove(buffer, temp, i);
	buffer[i] = '\0';
	i = new_line_found(line, buffer, 0);
	if (i)
	{
		if (i == 2)
			*read_result = -1;
		else
			*read_result = 1;
		return (1);
	}
	else
	{
		*line = ft_strjoin_mod(*line, buffer, 0, 0);
		if (!(*line))
			return (-1);
		return (0);
	}
	*read_result = 1;
	return (1);
}
/*
get_next_line(int fd, char **line);
----------------------------------
The following function is the where all the calls are made to assemble get next line and obtain the results desired.
get_next_line checks for the rights conditions to execute, in case the requirements aren't met -1 is returned.
Then it mallocs *line using ft_strdup in order to concatenate the corresponding text later on.
We then check if the first char in buffer is '\n' in case it is, we know we have a remainder from the last call and is_buffer is activated.
If a remainder exists check_remainder will execute and it will return INT trigger, which will trigger or not,
depending on another line being found or not, another read_cycle where it performs the read() loop.
*/
int			get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_result;
	int			trigger;
	int			is_buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0 ||\
	line == NULL || fd > FOPEN_MAX)
		return (-1);
	*line = ft_strdup("");
	if (*line == NULL)
		return (-1);
	if (buffer[0] == '\n')
		is_buffer = 1;
	else
	{
		trigger = 0;
		is_buffer = 0;
	}
	if (is_buffer)
		trigger = check_buffer(line, buffer, &read_result, 0);
	if (!trigger)
		read_result = read_cycle(fd, line, buffer);
	return (read_result);
}
