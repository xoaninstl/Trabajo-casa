/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:58:21 by dcasan-a          #+#    #+#             */
/*   Updated: 2025/07/27 19:14:33 by dcasan-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	d_num[50];
	char	d_name[50];
}	t_dict;

void	put_strchar(char *str);

int		ft_is_numeric(char *str);

int		ft_is_error(int a, char *b, char *c);

int		ft_blocks_number(int nbr);

char	*ft_read_file(char *filename);

void	ft_fill_dict(char *buffer, t_dict *dict, int max_reg);

char	*ft_search(char *nbr_src, t_dict *dict);

int		ft_blocks_number(int nbr);

#endif
