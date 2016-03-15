#include "libft.h"

int		test_strings()
{
	ft_putendl("test<%s>:");
	ft_printf("%s\n", "I'm a string!");
	return (0);
}

int		test_numbers()
{
	ft_putendl("test<%d>: 0");
	ft_printf("%d\n", (int)0);
	ft_putendl("test<%d>: 1234");
	ft_printf("%d\n", (int)1234);
	ft_putendl("test<%i>: 1234");
	ft_printf("%d\n", (int)1234);
	ft_putendl("test<%u>: 1234567");
	ft_printf("%d\n", (unsigned int)1234567);
	ft_putendl("test<%l>: 12345678");
	ft_printf("%l\n", (long int)12345678);
	ft_putendl("test<%f>: 12345678");
	ft_printf("%f\n", 0.0);
	return (0);
}

int		test_pointers()
{
	ft_putendl("test<%p>: 0x0");
	ft_printf("%p\n", NULL);
	ft_putendl("test<%p>: 0xdeadbeef");
	ft_printf("%p\n", 0xdeadbeef);
	return (0);
}

int		test_booleans()
{
	ft_putendl("test<%b>: true");
	ft_printf("%b\n", 1);
	ft_putendl("test<%b>: false");
	ft_printf("%b\n", 0);
	return (0);
}

int		test_hexadecs()
{
	ft_putendl("test<%x>: 0xa");
	ft_printf("%x\n", 0xa);
	return (0);
}
