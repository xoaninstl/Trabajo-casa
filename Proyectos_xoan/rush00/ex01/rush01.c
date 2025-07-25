/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaatif-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:27:57 by jaatif-a          #+#    #+#             */
/*   Updated: 2025/07/12 15:49:41 by jaatif-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	columna;
	int	fila;

	if (x < 0 || y < 0)
		return ;
	columna = 1;
	fila = 1;
	while (fila <= y)
	{
		while (columna <= x)
		{
			if ((fila == 1 && columna == 1) || (fila == y && columna == x))
				ft_putchar('/');
			else if ((fila == 1 && columna == x) || (fila == y && columna == 1))
				ft_putchar('\\');
			else if ((fila == 1 || fila == y) || (columna == 1 || columna == x))
				ft_putchar('*');
			else
				ft_putchar(' ');
			columna++;
		}
		fila++;
		columna = 1;
		ft_putchar('\n');
	}
}
