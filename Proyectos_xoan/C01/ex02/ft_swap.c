/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:39:52 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/17 19:42:45 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)

{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* 
#include<stdio.h>


int	main(void)
{
	int	v1 = 15;
	int	v2 = 35;
	int	*a = &v1;
	int	*b = &v2;
	
	printf("Before ft_swap: \n");
	printf("Pointer 'a'\n", a, *a);
	printf("Pointer 'b'\n", b, *b);
	ft_swap(a, b);
	printf("\n");
	printf("After ft_swap: \n");
	printf("Pointer 'a'\n", a, *a);
	printf("Pointer 'b'\n", b, *b);
} */
