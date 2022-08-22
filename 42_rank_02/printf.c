#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = ("(null)");
	while (s[i])
	{
		ft_putchar_len(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar_len('-');
		n = -n;
	}
	if (n / 10 != 0)
	{
		len += ft_putnbr_len(n / 10);
	}
	len += ft_putchar_len(n % 10 + '0');
	return (len);
}

int	ft_puthexa_len(unsigned int n)
{
	char *dico = "0123456789abcdefg";
	int	len;

	len = 0;
	if (n / 16 != 0)
	{
		len += ft_puthexa_len(n / 16);
	}
	len += ft_putchar_len(dico[n % 16]);
	return (len);
}

int ft_printf(char *str, ...)
{
	int i;
	int count;
	va_list args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if ((!str))
			break ;
		if (str[i] == '%' && str[++i])
		{
			if (str[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd')
				count += ft_putnbr_len(va_arg(args, int));
			else if (str[i] == 'x')
				count += ft_puthexa_len(va_arg(args, unsigned int));		
		}
		else
			count += ft_putchar_len(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int main(void)
{

	ft_printf("%s\n", "toto");
	ft_printf("fft_printf = %d\n", +-99954555574);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);	

	return (0);
}
