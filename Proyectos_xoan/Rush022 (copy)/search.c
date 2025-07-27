/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:07:27 by dcasan-a          #+#    #+#             */
/*   Updated: 2025/07/27 19:22:59 by dcasan-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "functions.h"

/* ft_search arcv-number as *src in dict*/
/* ft_div divide number *src in blocks of tree numbers*/
/* ft_strlen search numbers of digits, for divide*/

int	ft_strlen(char *str)
{
	int	s;

	s = 0;
	while (str[s] != '\0')
	{
		s++;
	}
	return (s);
}

int	ft_reverse_number(char *src)
{
	char	swap;
	int		a;
	int		final;

	a = 0;
	final = ft_strlen(src);
	while (a > (final - 1))
	{
		swap = src[a];
		src[a] = src[final];
		src [final] = src[a];
		a++;
		final--;
	}

}

char	*ft_find_name(int blocks, char *nbr_src, t_dict *entry)
{
	char	*name;
	int		b;
	int		atoi_num;

	atoi_num = atoi(nbr_src);
	b = 0;
	if (blocks == 1 && atoi_num < 20)
	{
		b = atoi_num;
		name = entry[b].d_name;
	}
	return (name);
}

char	*ft_search(char *nbr_src, t_dict *dict)
{
	unsigned int	blocks;
	unsigned int	number;
	char			*r_number;
	char			*name;

	number = atoi(nbr_src);
	blocks = ft_blocks_number(number);
	name = ft_find_name(blocks, nbr_src, dict);

}
