/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:13:55 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/20 13:21:33 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main()
{
	char	str[] = "hello";
	int	digits;

	digits = ft_printf("This : %s", str);
	printf("\n%d", digits);
}
