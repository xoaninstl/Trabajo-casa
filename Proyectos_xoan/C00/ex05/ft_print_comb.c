/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:13:31 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/15 15:41:38 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 * Esta es la función "ayudante".
 */
void	ft_comb_helper(char d1)
{
	char	d2;
	char	d3;

	d2 = d1 + 1;
	while (d2 <= '8')
	{
		d3 = d2 + 1;
		while (d3 <= '9')
		{
			write(1, &d1, 1);
			write(1, &d2, 1);
			write(1, &d3, 1);
			if (!(d1 == '7' && d2 == '8' && d3 == '9'))
			{
				write(1, ", ", 2);
			}
			d3++;
		}
		d2++;
	}
}

/*
 * Esta es la función principal que entregas.
 */
void	ft_print_comb(void)
{
	char	d1;

	d1 = '0';
	while (d1 <= '7')
	{
		ft_comb_helper(d1);
		d1++;
	}
}
