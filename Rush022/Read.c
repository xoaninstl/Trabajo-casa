/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:43:16 by dcasan-a          #+#    #+#             */
/*   Updated: 2025/07/27 17:52:48 by dcasan-a         ###   ########.fr       */
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
		while (buffer[i] > '0' && buffer[i] < '9')
			dict[dict_reg].d_num[j++] = buffer [i++];
		if (buffer[i] == ':')
			i++;
		if (buffer[i] == ' ')
			i++;
		j = 0;
		while (buffer[i] != '\n')
			dict[dict_reg].d_name[j++] = buffer[i++];
		while (buffer[i] == '\n')
			i++;
		dict_reg++;
	}

}
