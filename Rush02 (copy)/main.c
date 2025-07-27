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

int main(int argc, char *argv[])
{
    char            *dict_path;
    char            *num_to_convert;
    t_dict_entry    *dictionary;
    int             dict_size;

    if (ft_is_error(argc, argv[1], argv[2]) == 0)
        return (1);
    if (argc == 2)
    {
        dict_path = "numbers.dict";
        num_to_convert = argv[1];
    }
    else
    {
        dict_path = argv[1];
        num_to_convert = argv[2];
    }
    dictionary = parse_dictionary(dict_path, &dict_size);
    if (!dictionary)
    {
        put_strchar("Dict Error\n");
        return (1);
    }
    start_conversion(num_to_convert, dictionary, dict_size);
    free_dictionary(dictionary, dict_size);
    return (0);
}
