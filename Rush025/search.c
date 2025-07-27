/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 22:07:16 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/27 22:07:35 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	print_scale(int num_blocks, t_dict *dict)
{
	char	scale_num[38];
	int		i;

	if (num_blocks > 1)
	{
		scale_num[0] = '1';
		i = 1;
		while (i < (num_blocks - 1) * 3 + 1)
		{
			scale_num[i] = '0';
			i++;
		}
		scale_num[i] = '\0';
		find_and_print(scale_num, dict, 1);
	}
}

void	ft_search(char *nbr_str, t_dict *dict)
{
	int		len;
	int		first_block_len;
	int		num_blocks;
	char	current_block[4];

	len = ft_strlen(nbr_str);
	if (len == 1 && nbr_str[0] == '0')
	{
		find_and_print("0", dict, 0);
		return;
	}
	first_block_len = len % 3;
	if (first_block_len == 0)
		first_block_len = 3;
	num_blocks = (len + 2) / 3;
	ft_strncpy(current_block, nbr_str, first_block_len);
	process_three_digits(current_block, dict);
	if (num_blocks > 1)
		put_strchar(" ");
	print_scale(num_blocks, dict);
	nbr_str += first_block_len;
	while (--num_blocks > 0)
	{
		ft_strncpy(current_block, nbr_str, 3);
		process_three_digits(current_block, dict);
		if (num_blocks > 1)
		{
			put_strchar(" ");
			print_scale(num_blocks, dict);
		}
		nbr_str += 3;
	}
}
