/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepnum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:36:58 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/26 23:37:00 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPNUM_H
# define PREPNUM_H

# include "dictionary.h"
# include "utils.h"

void	start_conversion(char *num_str, t_dict_entry *dict, int dict_size);

void	process_trio(char *trio, t_dict_entry *dict, int d_size, int *is_first);
void	print_word(char *key, t_dict_entry *dict, int dict_size, int *is_first);

#endif

