/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:45:10 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/23 18:45:22 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*array;

	if (!(array = (int *)malloc(sizeof(int) * length)))
		return (0);
	i = 0;
	while (i < length)
	{
		array[i] = (*f)(tab[i]);
		i++;
	}
	return (array);
}
