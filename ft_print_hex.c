/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:30:37 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/22 19:23:23 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dig_hex(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16);
		ft_put_hex(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb + 'a' - 10);
	}
}

int	ft_print_hex(unsigned int nb)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(nb);
	return (ft_dig_hex(nb));
}
