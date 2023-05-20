/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:13:06 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/20 20:11:09 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (0);
	}
	else
	{
		write(1, s, len);
		return ((int)ft_strlen(s));
	}
}
