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
#include <unistd.h>
#include <stdio.h>

void	put_strchar(char *str)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		write (1, &str[s], 1);
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
		|| (a > 3))
	{
		put_strchar("Error\n");
		return (0);
	}
	else
		return (1);
}
