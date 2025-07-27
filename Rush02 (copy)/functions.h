/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:58:21 by dcasan-a          #+#    #+#             */
/*   Updated: 2025/07/26 23:11:47 by dcasan-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict_entry
{
	char	*key;
	char	*value;
}	t_dict_entry;

void			put_strchar(char *str);
int				ft_is_numeric(char *str);
int				ft_is_error(int a, char *b, char *c);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *src);
char			*ft_strndup(char *src, int n);

t_dict_entry	*parse_dictionary(char *path, int *size);
char			*find_value(t_dict_entry *dict, int dict_size, char *key);
void			free_dictionary(t_dict_entry *dict, int dict_size);

void			start_conversion(char *num_str, t_dict_entry *dict, int dict_size);
void			process_trio(char *trio, t_dict_entry *dict, int d_size, int *is_first);
void			print_word(char *key, t_dict_entry *dict, int dict_size, int *is_first);
void			process_tens(char *digits, t_dict_entry *dict, int d_size, int *is_first);
void			print_magnitude(int num_len, t_dict_entry *dict, int d_size, int *is_first);

#endif
