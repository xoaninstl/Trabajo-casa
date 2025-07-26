/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:35:36 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/26 23:35:37 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	print_magnitude(int num_len, t_dict_entry *dict, int d_size, int *is_first)
{
	char	*magnitude_key;
	int		i;

	if (num_len < 3)
		return ;
	magnitude_key = malloc(num_len + 2);
	if (!magnitude_key)
		exit(1);
	magnitude_key[0] = '1';
	i = 1;
	while (i <= num_len)
	{
		magnitude_key[i] = '0';
		i++;
	}
	magnitude_key[i] = '\0';
	print_word(magnitude_key, dict, d_size, is_first);
	free(magnitude_key);
}

void	start_conversion(char *num_str, t_dict_entry *dict, int dict_size)
{
	int		len;
	int		first_group_len;
	int		i;
	int		is_first;
	char	*current_group;

	len = ft_strlen(num_str);
	is_first = 1;
	if (len == 1 && num_str[0] == '0')
	{
		print_word("0", dict, dict_size, &is_first);
		put_strchar("\n");
		return ;
	}
	first_group_len = len % 3;
	if (first_group_len == 0 && len > 0)
		first_group_len = 3;
	current_group = ft_strndup(num_str, first_group_len);
	if (ft_strcmp(current_group, "000") != 0 && ft_strcmp(current_group, "00") != 0 && ft_strcmp(current_group, "0") != 0)
		process_trio(current_group, dict, dict_size, &is_first);
	free(current_group);
	i = first_group_len;
	while (i < len)
	{
		current_group = ft_strndup(num_str + i, 3);
		if (ft_strcmp(current_group, "000") != 0)
		{
			print_magnitude(len - i, dict, dict_size, &is_first);
			process_trio(current_group, dict, dict_size, &is_first);
		}
		free(current_group);
		i += 3;
	}
	put_strchar("\n");
}
