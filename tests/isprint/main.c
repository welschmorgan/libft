#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "isprint"



# define DO_TEST(c) TEST(ft_isprint(c), isprint(c), int_test)

t_error	*do_tests(void)
{
	DO_TEST('a');
	SUCCESS();
}

int		main(void)
{
	TEST_FUNC(FUNC_NAME, do_tests);
	return (0);
}
