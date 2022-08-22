#include "ft_printf.h"
int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);}

int	ft_putstr_len(char *s)
{
	int i = 0;

	if (!(s))
		return (ft_putstr_len("(null)"));
	while (s[i])
	{
		ft_putchar_len(s[i]);
		i++;
	}
	return (i);
}

int ft_putnbr_len(long n)
{
	int len = 0;
	
	if (n < 0)
	{
		len += ft_putchar_len('-');
		n = -n;
	}
	if (n / 10 != 0)
		len += ft_putnbr_len(n / 10);
	len += ft_putchar_len(n % 10 + '0');
	return (len);
}

int	ft_puthexa_len(long n)
{
	char	*dico = "0123456789abcdefg";
	int		len = 0;

	if (n / 16 != 0)
		len += ft_puthexa_len(n /16);
	len += ft_putchar_len(dico[n%16]);
	return (len);	
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len = 0;
	int		i = 0;

	if (!(str))
		return (0);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				len += ft_putstr_len(va_arg(arg, char *));
			if (str[i] == 'd')
				len += ft_putnbr_len(va_arg(arg, int));
			if (str[i] == 'x')
				len += ft_puthexa_len(va_arg(arg, unsigned int));
		}
		else
			len += ft_putchar_len(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

// int main(void)
// {
// 	ft_printf("jesuis\n");
// 	return (0);
// }