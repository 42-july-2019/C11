/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:54:00 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/25 00:39:51 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int			i;
	long int	prev_comp;
	long int	curr_comp;

	if (length < 0)
		return (0);
	if (length < 3)
		return (1);
	prev_comp = (long)(*f)(tab[0], tab[1]);
	curr_comp = (long)(*f)(tab[1], tab[2]);
	i = 2;
	while (i < length - 1 && prev_comp * curr_comp >= 0)
	{
		prev_comp = curr_comp;
		curr_comp = (long)(*f)(tab[i], tab[i + 1]);
		i++;
	}
	return ((i == length - 1 && prev_comp * curr_comp >= 0) ? 1 : 0);
}
