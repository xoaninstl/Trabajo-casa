/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaatif-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:04:09 by jaatif-a          #+#    #+#             */
/*   Updated: 2025/07/12 17:11:37 by jaatif-a         ###   ########.fr       */
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
			if (columna == 1 && (fila == 1 || fila == y))
				ft_putchar('A');
			else if (columna == x && (fila == 1 || fila == y))
				ft_putchar('C');
			else if ((fila == 1 || fila == y) || (columna == 1 || columna == x))
				ft_putchar('B');
			else
				ft_putchar(' ');
			columna++;
		}
		fila++;
		columna = 1;
		ft_putchar('\n');
	}
}
