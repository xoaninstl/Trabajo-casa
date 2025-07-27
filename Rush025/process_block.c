/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:08:04 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/27 21:36:00 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	find_and_print(char *num_str, t_dict *dict, int add_space)
{
	int	i;

	i = 0;
	while (i < 41)
	{
		if (ft_strcmp(dict[i].d_num, num_str) == 0)
		{
			put_strchar(dict[i].d_name);
			if (add_space)
				put_strchar(" ");
			return ;
		}
		i++;
	}
}

void	process_tens(char *block, t_dict *dict)
{
	char	temp[3];

	if (block[0] >= '2')
	{
		temp[0] = block[0];
		temp[1] = '0';
		temp[2] = '\0';
		find_and_print(temp, dict, (block[1] != '0'));
		if (block[1] != '0')
			process_three_digits(block + 1, dict);
	}
	else if (block[0] == '1')
		find_and_print(block, dict, 0);
	else if (block[0] == '0' && block[1] != '0')
		process_three_digits(block + 1, dict);
}

void	process_three_digits(char *block, t_dict *dict)
{
	int		len;
	char	temp[2];

	len = ft_strlen(block);
	if (len == 3)
	{
		if (block[0] != '0')
		{
			temp[0] = block[0];
			temp[1] = '\0';
			find_and_print(temp, dict, 1);
			find_and_print("100", dict, 1);
		}
		process_three_digits(block + 1, dict);
	}
	else if (len == 2)
		process_tens(block, dict);
	else if (len == 1 && block[0] != '0')
		find_and_print(block, dict, 0);
}
