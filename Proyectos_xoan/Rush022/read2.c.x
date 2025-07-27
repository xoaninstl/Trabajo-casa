/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcasan-a <dcasan-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:06:48 by ngarcia-          #+#    #+#             */
/*   Updated: 2025/07/27 17:24:33 by dcasan-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*fcntl.h is for open, stdlib.h is for malloc and free, 
and unsitd.h is for read and close*/
#include "functions.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
/*Reads the entire content of a file and returns it in a buffer.
The buffer size is 1024: 1023 for data and 1 for '\0'.
fd = file descriptor system provide
buffer = malloc(....) -> allocate memory
fd = open() -> Open file in read-only mode
free(buffer) -> releases the memory previously allocated with malloc
Add '\0' at the end to terminate the string*/
/*char	*ft_read_file(char *filename)
{
	int		fd;
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
	{
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		put_strchar("Dict Error\n");
		return (NULL);
	}
	bytes_read = read(fd, buffer, 1023);
	close(fd);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}*/
/*Extracts a number (0-9...) from a string at position *index.
Advances the index until no more digits are found.
Works like atoi but manually implemented.
number = number * 10 + (str[*index] - '0'); ->  Convert char to int
(*index)++ -> Move position forward */
/*
int	extract_number(char *str, int *index)
{
	int		number;

	number = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		number = number * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (number);
}*/
/*Extracts a word from a string starting at *index.
Skips spaces and ':' until printable characters are found.
Copies everything until '\n' or end of string into dest.
while (str[*index] == ' ' || str[*index] == ':')
(*index)++ -> Skip spaces and ':'
while (str[*index] != '\n' && str[*index] != '\0') Copy until newline 
or end of string 
dest[i] = '\0' -> Terminate string with '\0' */
/*
void	extract_word(char *str, int *index, char *dest)
{
	int		i;

	i = 0;
	while (str[*index] == ' ' || str[*index] == ':')
		(*index)++;
	while (str[*index] != '\n' && str[*index] != '\0')
	{
		dest[i] = str[index];
		i++;
		(*index)++;
	}
	dest[i] = '\0';
}*/