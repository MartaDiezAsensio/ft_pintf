/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:13:55 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/20 20:04:06 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char	str[] = "hello";
	int	digits;
	char	*s;

	s = NULL;
	printf(" NULL %s NULL \n", NULL);
	ft_printf(" NULL %s NULL \n", s);
}
