#include "common.h"
#include <stdlib.h>

# define TEST_ASSERT(a,b, type_c) \
	if (a != b)\
		fprintf(stderr, "[ASSERT] Failed: %" #type_c " != %" #type_c "\n", a, b);

size_t					g_err_count = 0;


t_bool					ptr_range_test(void *ptr, void *start, void *end)
{
	return (ptr >= start && ptr <= end);
}
t_bool					ptr_test(void *a, void *b)
{
	TEST_ASSERT(a,b,p);
	return (a == b);
}
t_bool					int_test(int a, int b)
{
	TEST_ASSERT(a,b, i);
	return (a == b);
}
t_bool					char_test(char a, char b)
{
	TEST_ASSERT(a,b, c);
	return (a == b);
}
t_bool					bool_test(t_bool a, t_bool b)
{
	TEST_ASSERT(a,b,i);
	return (a == b);
}
t_bool					int_ar_test(int *a, int *b, size_t n)
{
	while (a && b && n--)
	{
		TEST_ASSERT(*a,*b, i);
		if (*(a++) != *(b++))
		{
			return (FALSE);
		}
	}
	return (TRUE);
}
t_bool					str_test(char *a, char *b)
{
	int	cmp = strcmp(a,b);
	if (cmp)
		fprintf(stderr, "[ASSERT] Failed: %s != %s (%i)\n", a, b, cmp);
	return (cmp == 0);
}


char					*tr_error_code(t_error_code c, char *ptr)
{
	switch(c)
	{
	case ERR_ASSERT:
		ft_strncpy(ptr, "ERR_ASSERT", ERR_CODE_MAXLEN);
		break;
	case ERR_LIBC_DIFF:
		ft_strncpy(ptr, "ERR_LIBC_DIFF", ERR_CODE_MAXLEN);
		break;
	default:
		ft_strncpy(ptr, "ERR_SUCCESS", ERR_CODE_MAXLEN);
	}
	return (ptr);
}

t_error					*ft_success()
{
	t_error *ret = (t_error*)ft_memalloc(sizeof(t_error));

	ret->msg = NULL;
	ret->code = ERR_SUCCESS;

	return (ret);
}

t_error					*ft_errnew(char const *msg, t_error_code c)
{
	t_error *ret = (t_error*)malloc(sizeof(t_error));

	ret->msg = ft_strdup(msg ? msg : "");
	ret->code = c;

	return (ret);
}

void					ft_errdel(t_error **err)
{
	if (!err || !*err)
		return ;
	if ((*err)->msg)
		ft_strdel(&(*err)->msg);
	ft_memdel((void**)err);
}

void					ft_errprint(t_error *err)
{
	char		ret[ERR_CODE_MAXLEN];
	if (!err)
	{
		printf("\n");
		return ;
	}
	printf("Error[%s]: %s\n", tr_error_code(err->code, ret), err->msg);
}
void					ft_errprint_fd(FILE *stream, t_error *err)
{
	char		ret[ERR_CODE_MAXLEN];
	if (!err)
	{
		fprintf(stream, "\n");
		return ;
	}
	fprintf(stream, "Error[%s]: %s\n", tr_error_code(err->code,ret), err->msg);
}

void					print_hr(void)
{
	fprintf(stdout, "----------------------------\n");
}

t_bool					test_func(char const *name, t_test_func func)
{
	t_error		*err;
	t_bool		ret;

	ret = TRUE;;
	err = NULL;
	print_hr();
	fprintf(stdout, "\tTesting '%s'\n", name);
	print_hr();
	if ((err=func())->code != ERR_SUCCESS)
	{
		fprintf(stderr, "[FAIL: %s] -> ", name);
		ft_errprint_fd(stderr, err);
		ret = (FALSE);
	}
	else
		fprintf(stdout, "[SUCCESS: %s]\n", name);
	ft_errdel(&err);
	return (ret);
}
