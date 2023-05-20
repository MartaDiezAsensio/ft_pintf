/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:44:04 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/20 13:40:30 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
#include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int	ft_putnbr(int n);

int	ft_int_to_hex(unsigned int nb);
int	ft_int_to_hexM(unsigned int nb);
int	ft_printf(const char *str, ...);
int	ft_putnbr_u(int n);

int	ft_print_pointer(unsigned long num);

#endif