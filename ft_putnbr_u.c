/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:21:15 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/20 22:53:47 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n / 10)
	{
		i += ft_putnbr_u(n / 10);
		i += ft_putnbr_u(n % 10);
	}
	else
		i += ft_putchar('0' + n);
	return (i);
}