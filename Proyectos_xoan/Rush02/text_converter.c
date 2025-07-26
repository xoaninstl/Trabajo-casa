/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:36:19 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/26 23:36:22 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prepnum.h"

void	print_word(char *key, t_dict_entry *dict, int dict_size, int *is_first)
{
	char	*value;

	value = find_value(dict, dict_size, key);
	if (value)
	{
		if (!(*is_first))
			ft_putstr(" ");
		ft_putstr(value);
		*is_first = 0;
	}
	else
	{
		ft_putstr("Dict Error\n");
		exit(1);
	}
}

void	process_tens(char *digits, t_dict_entry *dict, int d_size, int *is_first)
{
	char	buffer[3];

	if (digits[0] == '1')
	{
		print_word(digits, dict, d_size, is_first);
		return ;
	}
	if (digits[0] != '0')
	{
		buffer[0] = digits[0];
		buffer[1] = '0';
		buffer[2] = '\0';
		print_word(buffer, dict, d_size, is_first);
	}
	if (digits[1] != '0')
	{
		buffer[0] = digits[1];
		buffer[1] = '\0';
		print_word(buffer, dict, d_size, is_first);
	}
}

void	process_trio(char *trio, t_dict_entry *dict, int d_size, int *is_first)
{
	char	*trio_copy;

	trio_copy = ft_strdup(trio);
	if (ft_strlen(trio_copy) == 3 && trio_copy[0] != '0')
	{
		print_word(ft_strndup(trio_copy, 1), dict, d_size, is_first);
		print_word("100", dict, d_size, is_first);
		process_tens(trio_copy + 1, dict, d_size, is_first);
	}
	else if (ft_strlen(trio_copy) == 2)
		process_tens(trio_copy, dict, d_size, is_first);
	else if (ft_strlen(trio_copy) == 1 && trio_copy[0] != '0')
		print_word(trio_copy, dict, d_size, is_first);
	free(trio_copy);
}
