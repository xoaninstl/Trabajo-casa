/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:40:00 by dcasan-a          #+#    #+#             */
/*   Updated: 2025/07/27 19:08:19 by dcasan-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char *argv[])
{
	int			archive_dict;
	char		*name_dict;
	char		*read_buffer;
	char		*search_number;
	t_dict		entry[41];
	int			regs;

	regs = 41;
	if (ft_is_error(argc, argv[1], argv[2]) == 0)
		return (0);
	if (argc == 2)
	{
		search_number = argv[1];
		name_dict = "numbers.dict";
	}
	else
	{
		name_dict = argv[1];
		search_number = argv[2];
	}
	read_buffer = ft_read_file(name_dict);
	ft_fill_dict(read_buffer, entry, regs);
	put_strchar(ft_search(search_number, entry));
	return (0);
}
/*
	archive_dict = open(name_dict, O_RDONLY);
	if (archive_dict == -1)
	{
		put_strchar("Dict Error\n");
		return (0);
	}
*/