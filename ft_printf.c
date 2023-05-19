#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c, int len)
{
	len++;
	write(1, &c, 1);
}

void	ft_putstr(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		len++;
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb, int len)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			ft_putstr("-2147483648", len);
			return ;
		}
		ft_putchar('-', len);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0', len);
	}
}

void	ft_putnbr_u(int nb, int len)
{
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10, len);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0', len);
	}
}

int	count_dig_hex(int nb)
{
	int	i;
	int	temp;

	i = 0;
	while (nb != 0)
	{
		temp = nb % 16;
		nb /= 16;
		i++;
	}
	return (i);
}
void	int_to_hex(int nb, int len)
{
	int		alloc;
	int		temp;
	char	*hex;

	alloc = count_dig_hex(nb);
	hex = (char *)malloc(sizeof(char) * alloc);
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
	ft_putstr(hex, len);
	free(hex);
}

void	int_to_hex2(int nb, int len)
{
	int		alloc;
	int		temp;
	char	*hex;

	alloc = count_dig_hex(nb);
	hex = (char *)malloc(sizeof(char) * alloc);
	while (nb != 0)
	{
		temp = nb % 16;
		if (temp < 10)
			temp = temp + '0';
		else
			temp = temp + 'A' - 10;
		hex[--alloc] = temp;
		nb /= 16;
	}
	ft_putstr(hex, len);
	free(hex);
}

// void	ft_print_pointer(void *ptr, int len)
// {
// 	ft_putstr()
// }

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int	len = 0;
	va_start(args, str);

	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c')
				ft_putchar(va_arg(args, char), len);
			else if (*(str + 1) == 's')
				ft_putstr(va_arg(args, char *), len);
			else if (*(str + 1) == 'p')
				int_to_hex(va_arg(args, char *), len);
			else if (*(str + 1) == 'd')
				ft_putnbr(va_arg(args, int), len);
			else if (*(str + 1) == 'i')
				ft_putnbr(va_arg(args, int), len);
			else if (*(str + 1) == 'u')
				ft_putnbr_u(va_arg(args, int), len);
			else if (*(str + 1) == 'x')
				int_to_hex(va_arg(args, char *), len);
			else if (*(str + 1) == 'X')
				int_to_hex2(va_arg(args, char *), len);
			else if (*(str + 1) == '%')
			{
				write(1, "%", 1);
				va_arg(args, char);
			}
			else
				return (-1);
		}
		str++;
	}
	return (len);
}

int	main()
{
	int		num = 1234;
	char			c = 'a';
	char			str[] = "Hello";
	int				len = 0;
	void			*ptr;
	unsigned int	n = 234567890;

	//ft_printf("Char = %c \n", c);
	//ft_printf("String = %s \n", str);
	//ft_printf("Pointer = %p \n", ptr);
	//ft_printf("Number_10 = %d \n", num);
	//ft_printf("Number_10 = %i \n", num);
	ft_printf("Number_u = %u \n", n);
	//ft_printf("Number_hex_min = %x \n", num);
	//ft_printf("Number_hex_may = %X", num);
	//ft_printf("%% test \n");

}