/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:30:37 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/20 13:38:13 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_count_dig_hex(unsigned int nb)
{
	int				i;
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
	int					alloc;
	unsigned int		temp;
	char				*hex;
	int					i;

	i = 0;
	alloc = ft_count_dig_hex(nb);
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
