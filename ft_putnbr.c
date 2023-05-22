/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:21:15 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/22 21:35:59 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digs(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	printf("Estoy contando los digitos y hay %d", i);
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ret = ft_putstr("-2147483648");
			if (ret == -1)
				return (-1);
			return (i += ret);
		}
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		i += ret;
		n *= -1;
	}
	if (n / 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar('0' + n);
	if (i <= ft_digs(n))
		return (-1);
	return (i);
}
