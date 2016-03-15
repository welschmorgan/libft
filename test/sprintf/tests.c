#include "common.h"
#include "main.h"

int		test_strings()
{
	TEST("%s", "I'm a string!", "I'm a string!");
	TEST("%s", "", "");
	TEST("%s", NULL, NULL);
	return (0);
}

int		test_strings_w()
{
	TEST("%10s", "6chars", "6chars    ");
	return (0);
}

int		test_numbers()
{
	TEST("%d", 0, "0");
	TEST("%d", 123456, "123456");
	TEST("%d", 1234567, "1234567");
	TEST("%d", 12345678, "12345678");
	TEST("%d", 123456789, "123456789");
	TEST("%i", 0, "0");
	TEST("%i", 123456, "123456");
	TEST("%i", 1234567, "1234567");
	TEST("%i", 12345678, "12345678");
	TEST("%i", 123456789, "123456789");
	TEST("%i", 0, "0");
	TEST("%f", 0.0f, "0.000000");
	TEST("%f", 3.14f, "3.140000");
	return (0);
}

int		test_pointers()
{
	TEST("%p", NULL, "0x0");
	TEST("%p", 0xdeadbeef, "0xdeadbeef");
	return (0);
}

int		test_booleans()
{
	TEST("%t", 1, "true");
	TEST("%t", 0, "false");
	return (0);
}

int		test_hexadecs()
{
	int	n[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		16, 255, -0xff
	};
	char	buf[32];
	unsigned char	id;

	id = 0;
	while (id < (sizeof(n) / sizeof(int)))
	{
		snprintf(buf, 32, "%x", n[id]);
		ft_row_set(&g_row, 1, "%x");
		snprintf((char*)buffer, 255, "%i", n[id]);
		ft_row_set(&g_row, 2, buffer);
		ft_snprintf((char*)buffer, 255, "%x", n[id]);
		ret = ft_strncmp(buffer, buf, 255);
		ft_row_set(&g_row, 3, buf);
		ft_row_set(&g_row, 4, buffer);
		ft_row_set(&g_row, 5, "");
		print_result(ret);
		if (ret)
			return (ret);
		id++;
	}
	return (0);
}
