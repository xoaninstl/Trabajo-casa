/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 22:06:58 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/27 22:06:59 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	put_strchar(char *str)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		write(1, &str[s], 1);
		s++;
	}
}

int	ft_is_numeric(char *str)
{
	int	s;

	s = 0;
	if (str[s] == '\0')
		return (0);
	while (str[s] != '\0')
	{
		if (str[s] >= '0' && str[s] <= '9')
			s++;
		else
			return (0);
	}
	return (1);
}

int	ft_is_error(int a, char *b, char *c)
{
	if ((a == 3 && (ft_is_numeric(c) == 0))
		|| (a == 2 && (ft_is_numeric(b) == 0))
		|| (a > 3 || a < 2))
	{
		put_strchar("Error\n");
		return (0);
	}
	else
		return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
