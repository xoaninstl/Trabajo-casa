/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:40:00 by dcasan-a          #+#    #+#             */
/*   Updated: 2025/07/26 23:15:49 by dcasan-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char *argv[])
{
	int		archivo_dict;
	char	*nombre_dict;

	if (ft_is_error(argc, argv[1], argv[2]) == 0)
		return (0);
	if (argc == 2)
		nombre_dict = "numbers.dict";
	else
		nombre_dict = argv[1];
	archivo_dict = open(nombre_dict, O_RDONLY);
	if (archivo_dict == -1)
	{
		put_strchar("Dict Error\n");
		return (0);
	}
	return (0);
}
