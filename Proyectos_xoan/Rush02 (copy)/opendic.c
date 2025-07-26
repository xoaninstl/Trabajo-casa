/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:59:38 by dcasan-a          #+#    #+#             */
/*   Updated: 2025/07/26 22:15:39 by dcasan-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#define BUFFER_SIZE 4096

static void	process_dict_line(char *line, t_dict_entry *entry)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	entry->key = ft_strndup(line, i);
	j = i;
	while (line[j] == ' ' || line[j] == ':')
		j++;
	i = j;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	while (i > j && line[i - 1] == ' ')
		i--;
	entry->value = ft_strndup(&line[j], i - j);
}

static int	fill_dictionary(char *buffer, t_dict_entry *dict)
{
	int	i;
	int	line_start;
	int	size;

	i = 0;
	line_start = 0;
	size = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if (i > line_start)
			{
				process_dict_line(&buffer[line_start], &dict[size]);
				size++;
			}
			line_start = i + 1;
		}
		i++;
	}
	return (size);
}

t_dict_entry	*parse_dictionary(char *path, int *dict_size)
{
	int				fd;
	int				bytes_read;
	char			buffer[BUFFER_SIZE];
	t_dict_entry	*dict;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	close(fd);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	dict = malloc(sizeof(t_dict_entry) * 100);
	if (!dict)
		return (NULL);
	*dict_size = fill_dictionary(buffer, dict);
	return (dict);
}

char	*find_value(t_dict_entry *dict, int dict_size, char *key)
{
	int	i;

	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

void	free_dictionary(t_dict_entry *dict, int dict_size)
{
	int	i;

	i = 0;
	while (i < dict_size)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}
