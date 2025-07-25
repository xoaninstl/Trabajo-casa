/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:12:00 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/17 20:12:02 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	write(1, str, len);
}

/*void	ft_putstr(char *str);

int	main(void)
{
	ft_putstr("Hola, mundo!");
	ft_putstr("\n");
	ft_putstr("Esta es una prueba.");
	ft_putstr("\n");
	ft_putstr("");
	ft_putstr("Esta linea va despues de una cadena vacia.");
	ft_putstr("\n");
	return (0);
}*/
