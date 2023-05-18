#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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

void	int_to_hex()

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
				va_arg(args, void *);
			else if (*(str + 1) == 'd')
				ft_putnbr(va_arg(args, int), len);
			else if (*(str + 1) == 'i')
				ft_putnbr(va_arg(args, int), len);
			else if (*(str + 1) == 'u')
				va_arg(args, unsigned int);
			else if (*(str + 1) == 'x')
				va_arg(args, char *);
			else if (*str == 'X')
				va_arg(args, char *);
			else if (*(str + 1) == '%')
			{
				write(1, "a", 1);
				va_arg(args, char);
			}
			else
				return (-1);
		}
	}
	str++;
}

int	main()
{

printf("%x", 0x1e8480);

}