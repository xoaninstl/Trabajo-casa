/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:01:48 by dcasan-a          #+#    #+#             */
/*   Updated: 2025/07/26 23:15:15 by dcasan-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	put_strchar(char *str)
{
	int	s;

	s = 0;
	while (str[s])
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
	while (str[s])
	{
		if (str[s] < '0' || str[s] > '9')
			return (0);
		s++;
	}
	return (1);
}

int	ft_is_error(int a, char *b, char *c)
{
	if ((a == 3 && ft_is_numeric(c) == 0)
		|| (a == 2 && ft_is_numeric(b) == 0)
		|| a < 2 || a > 3)
	{
		put_strchar("Error\n");
		return (0);
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
