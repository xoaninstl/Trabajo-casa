/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:50:53 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/17 19:50:55 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include<stdio.h>

int	main(void)
{
	int a = 45;
	int b = 5;
	int	v1 = 0;
	int	v2 = 0;
	int	*div = &v1;
	int	*mod = &v2;

	printf("Before ft_div_mod: \n");
	printf("Pointer 'div'\n", div, *div);
	printf("Pointer 'mod'\n", mod, *mod);
	ft_div_mod(a, b, div, mod);
	printf("\n");
	printf("After ft_div_mod: \n");
	printf("Pointer 'div'\n", div, *div);
	printf("Pointer 'mod'\n", mod, *mod);
} */
