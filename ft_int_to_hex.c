/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:30:37 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/20 22:58:37 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_count_dig_hex(unsigned int nb)
{
	unsigned int	i;
	unsigned int	temp;

	i = 0;
	while (nb != 0)
	{
		temp = nb % 16;
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_int_to_hex(unsigned int nb)
{
	unsigned int		alloc;
	unsigned int		temp;
	char				*hex;
	int					i;

	i = 0;
	alloc = ft_count_dig_hex(nb);
	if (nb == 0)
		write(1, "0", 1);
	hex = (char *)malloc(sizeof(char) * (alloc + 1));
	if (!hex)
		return (0);
	hex[alloc + 1] = '\0';
	while (nb != 0)
	{
		temp = nb % 16;
		if (temp < 10)
			temp = temp + '0';
		else
			temp = temp + 'a' - 10;
		hex[--alloc] = temp;
		nb /= 16;
	}
	 i += ft_putstr(hex);
	free(hex);
	return (i);
}
