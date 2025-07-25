/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:20:40 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/24 00:30:22 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize_next;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	capitalize_next = 1;
	while (str[i])
	{
		if (capitalize_next && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		if (is_alphanum(str[i]))
			capitalize_next = 0;
		else
			capitalize_next = 1;
		i++;
	}
	return (str);
}
