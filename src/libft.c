/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/06 10:54:51 by ibulak        #+#    #+#                 */
/*   Updated: 2022/07/06 10:54:52 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/tokenizer.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (!(s[n] == '\0'))
		n++;
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	x;
	size_t	len_s;

	if (!s)
		return (NULL);
	if ((ft_strlen((char *)s) < len))
		len = ft_strlen((char *)s);
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!substr)
		return (NULL);
	x = 0;
	len_s = ft_strlen((char *)s);
	if (start + x < len_s)
	{
		while (*(s + start) != '\0' && x < len)
		{
			*(substr + x) = *(s + start + x);
			x++;
		}
	}
	*(substr + x) = '\0';
	return (substr);
}
