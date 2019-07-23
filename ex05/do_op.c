/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:35:08 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/23 20:32:44 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include <unistd.h>
#include "ft.h"

void		ft_putnbr(long int nb)
{
	char	c;

	if(nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

long int	ft_atoi(char *str)
{
	long int	result;
	long int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

long int	do_op(long int val_a, char op, long int val_b)
{
	long int	(*array[5])(long int, long int); 

	array[0] = ft_add;
	array[1] = ft_substract;
	array[2] = ft_divide;
	array[3] = ft_multiply;
	array[4] = ft_modulo;
	if (op == '+')
		return (array[0](val_a, val_b));
	else if (op == '-')
		return (array[1](val_a, val_b));
	else if (op == '/')
		return (array[2](val_a, val_b));
	else if (op == '*')
		return (array[3](val_a, val_b));
	else
		return (array[4](val_a, val_b));
}

int			check_params(int argc, char **argv)
{
	char		op;
	int			length;

	length = 0;
	while(argv[2][length])
		length++;
	op = *(argv[2]);
	if (argc != 4)
		return(1);
	if (((op != '+') && (op != '-') && (op != '/') && (op != '*') && (op != '%')) || (length != 1))
		return (2);
	if (*(argv[2]) == '/' && ft_atoi(argv[3]) == 0)
		return (3);
	if (*(argv[2]) == '%' && ft_atoi(argv[3]) == 0)
		return (4);
	return (0);
}

int			main(int argc, char **argv)
{
	int			error_case;
	long int	result;

	error_case = check_params(argc, argv);
	if (error_case == 1)
		return(0);
	else if (error_case == 2)
		write(1, "0", 1);
	else if (error_case == 3)
		write(1, "Stop : division by zero", 23);
	else if (error_case == 4)
		write(1, "Stop : modulo by zero", 21);
	else
	{
		result = do_op(ft_atoi(argv[1]), *(argv[2]), ft_atoi(argv[3]));
		ft_putnbr(result);
	}
	write(1, "\n", 1);
	return(0);
}
