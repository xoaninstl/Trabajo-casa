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

#include "functions.h"

void	process_tens(char *digits, t_dict_entry *dict, int d_size, int *is_first)
{
	char	buffer[3];
	char	*key_temp;

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
		key_temp = ft_strndup(&digits[1], 1);
		print_word(key_temp, dict, d_size, is_first);
		free(key_temp);
	}
}

void	process_trio(char *trio, t_dict_entry *dict, int d_size, int *is_first)
{
	char	*trio_copy;
	char	*key_h;

	trio_copy = ft_strdup(trio);
	if (ft_strlen(trio_copy) == 3 && trio_copy[0] != '0')
	{
		key_h = ft_strndup(trio_copy, 1);
		print_word(key_h, dict, d_size, is_first);
		free(key_h);
		print_word("100", dict, d_size, is_first);
		if (trio_copy[1] != '0' || trio_copy[2] != '0')
			process_tens(trio_copy + 1, dict, d_size, is_first);
	}
	else if (ft_strlen(trio_copy) == 2)
		process_tens(trio_copy, dict, d_size, is_first);
	else if (ft_strlen(trio_copy) == 1 && trio_copy[0] != '0')
		print_word(trio_copy, dict, d_size, is_first);
	free(trio_copy);
}

void	print_word(char *key, t_dict_entry *dict, int dict_size, int *is_first)
{
	char	*value;

	value = find_value(dict, dict_size, key);
	if (value)
	{
		if (!(*is_first))
			put_strchar(" ");
		put_strchar(value);
		*is_first = 0;
	}
	else
	{
		put_strchar("Dict Error\n");
		exit(1);
	}
}
