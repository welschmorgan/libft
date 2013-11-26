#ifndef TESTS_COMMON_H
# define TESTS_COMMON_H

# include "libft.h"
# include <stdio.h>


# define					ERR_CODE_MAXLEN 15

typedef enum			e_error_code
{
	ERR_SUCCESS,
	ERR_LIBC_DIFF,
	ERR_ASSERT
}						t_error_code;


typedef struct			s_error
{
	char				*msg;
	t_error_code		code;
}						t_error;

typedef t_error			*(*t_test_func)(void);
typedef t_bool			(*t_single_test_func)();
extern size_t			g_err_count;

char					*tr_error_code(t_error_code c, char *buf);
t_error					*ft_errnew(char const *msg, t_error_code c);
t_error					*ft_success(void);
void					ft_errdel(t_error **err);
void					ft_errprint(t_error *err);
void					ft_errprint_fd(FILE *stream, t_error *err);
void					print_hr(void);
t_bool					test_func(char const *name, t_test_func func);

t_bool					ptr_range_test(void *ptr, void *start, void *end);
t_bool					ptr_test(void *a, void *b);
t_bool					int_test(int a, int b);
t_bool					char_test(char a, char b);
t_bool					bool_test(t_bool a, t_bool b);
t_bool					int_ar_test(int *a, int *b, size_t n);
t_bool					str_test(char *a, char *b);

# define TEST(a, b, test_func) if (!test_func(a, b)) \
		return (ft_errnew("Mismatch detected libft/libc", ERR_LIBC_DIFF))
# define SUCCESS() return (ft_success())
# define TEST_FUNC(NAME,FUNC_PTR) test_func(NAME, FUNC_PTR)

#endif
