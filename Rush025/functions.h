/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:28:30 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/27 22:00:28 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	d_num[50];
	char	d_name[50];
}	t_dict;

// Prototipos de functions.c
void	put_strchar(char *str);
int		ft_is_numeric(char *str);
int		ft_is_error(int a, char *b, char *c);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

// Prototipos de read.c
char	*ft_read_file(char *filename);
void	ft_fill_dict(char *buffer, t_dict *dict, int max_reg);

// Prototipos de process_block.c
void	find_and_print(char *num_str, t_dict *dict, int add_space);
void	process_three_digits(char *block, t_dict *dict);

// Prototipos de search.c
void	print_scale(int num_blocks, t_dict *dict);
void	ft_search(char *nbr_str, t_dict *dict);

#endif
