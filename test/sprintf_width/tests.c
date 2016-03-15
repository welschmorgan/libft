#include "common.h"
#include "main.h"

int		test_strings()
{
	TEST("%10s", "6chars", "6chars    ");
	TEST("%2x", 10, "0a");
	TEST("%2x", 255, "ff");
	TEST("%10c", '-', "----------");
	return (0);
}
