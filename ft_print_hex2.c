/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:30:37 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/24 18:48:15 by mdiez-as         ###   ########.fr       */
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

static int	ft_put_hex2(unsigned int nb)
{
	int	i;
	int	ret;

	i = 0;
	if (nb >= 16)
	{
		ret = ft_put_hex2(nb / 16);
		if (ret == -1)
			return (-1);
		i++;
		ret = ft_put_hex2(nb % 16);
		if (ret == -1)
			return (-1);
		i++;
	}
	else
	{
		if (nb <= 9)
		{
			ret = ft_putchar(nb + '0');
			if (ret == -1)
				return (-1);
			i++;
		}
		else
		{
			ret = ft_putchar(nb + 'A' - 10);
			if (ret == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}

int	ft_print_hex2(unsigned int nb)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		if (ft_put_hex2(nb) == -1)
			return (-1);
	return (ft_dig_hex(nb));
}
