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
# include <stdio.h>
# include <fcntl.h>

void	put_strchar(char *str);

int		ft_is_numeric(char *str);

int		ft_is_error(int a, char *b, char *c);

struct s_dict
{
	char	a_num[50];
	char	a_name[50];
};

#endif
