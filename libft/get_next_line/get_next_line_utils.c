/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:31:10 by idonado       #+#    #+#                 */
/*   Updated: 2021/08/05 23:30:00 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
free_and_return_null
----------------------------------
This function is basically only to be used on this project within the customized version of ft_strjoin()
*/
char	*free_and_return_null(char *s)
{
	free(s);
	return (NULL);
}

/*
ft_strjoin
----------------------------------
This standard library function is commented because it is not the same ft_strjoin used on my library in the libft repo.
It is less safe yet and optimized and customized for this function's purpose and should not be copied exactly as is onto any other function.
*/
char	*ft_strjoin_mod(char *s1, char *s2, size_t i, size_t j)
{
	char	*temp;

	if (!s1)
		return (NULL);
	if (!s2)
		return (free_and_return_null(s1));
	temp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!temp)
		return (free_and_return_null(s1));
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = 0;
	free(s1);
	return (temp);
}
