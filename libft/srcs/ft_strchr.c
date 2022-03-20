/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:23:25 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/13 09:52:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The ft_strchr() function locates the first occurrence of c 
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered to be part of the string ;
 * therefore if c is ‘\0’, the functions locate the terminating ‘\0’.*/

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (!(char)c)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && (char)c == '\0')
		return (&str[i]);
	return (NULL);
}
