/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:28:54 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/27 21:28:55 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*ft_read_file(char *filename)
{
	char		*buffer;
	int			file;
	int			file_leng;

	buffer = malloc (1024);
	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		free(buffer);
		put_strchar("Dict error\n");
		return (NULL);
	}
	file_leng = read(file, buffer, 1023);
	close(file);
	if (file_leng <= 0)
	{
		free(buffer);
		put_strchar("Dict error\n");
		return (NULL);
	}
	buffer[file_leng] = '\0';
	return (buffer);
}

void	ft_fill_dict(char *buffer, t_dict *dict, int max_reg)
{
	int	i;
	int	dict_reg;
	int	j;

	i = 0;
	dict_reg = 0;
	while (buffer[i] && dict_reg < max_reg)
	{
		j = 0;
		while (buffer[i] == ' ')
			i++;
		while (buffer[i] >= '0' && buffer[i] <= '9')
			dict[dict_reg].d_num[j++] = buffer[i++];
		dict[dict_reg].d_num[j] = '\0';
		while (buffer[i] == ' ' || buffer[i] == ':')
			i++;
		j = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0')
			dict[dict_reg].d_name[j++] = buffer[i++];
		dict[dict_reg].d_name[j] = '\0';
		while (buffer[i] == '\n')
			i++;
		dict_reg++;
	}
}
