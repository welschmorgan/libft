#ifndef COMMON_MAIN_HH
# define COMMON_MAIN_HH

# include <libft.h>


# define CELL_LENGTH_MAX		50


typedef enum		e_row_cell
{
	GROUP_CELL,
	NAME_CELL,
	INPUT_CELL,
	LIBC_CELL,
	LIBFT_CELL,
	STATUS_CELL,
	CELL_COUNT,
}					t_row_cell;

typedef struct		s_row
{
	int				ncols;
	char			**buffer;
	int				*sizes;
	char			**names;
	char			*sep;
}					t_row;

typedef struct		s_test
{
	char			name[CELL_LENGTH_MAX];
	t_dlist			rows;
	int				(*func)();
}					t_test;

extern t_dlist		g_tests;
extern t_test const	*g_test;

extern t_row		g_row;
extern int const	g_row_sizes[CELL_COUNT];
extern char	const	*g_row_names[CELL_COUNT][CELL_LENGTH_MAX];

t_row				*add_test_row(t_test *t, t_row const *r);
t_test				*new_test(char const *name, int (*func)());
t_test const		*current_test();
int					start_test(t_test const *test);
t_test				*add_test(char const *name, int (*func)());

int					init();
int					cleanup();

void				print_separator();

size_t				ft_row_length(t_row *row);
char				*ft_row_cell(t_row *row, int const col);
char				*ft_row_cell_name(t_row *row, int const col);
t_row				*ft_row_init(t_row *row, int const ncols,
								 int const *sizes, char const **names);
t_row				*ft_row_reset(t_row *row);
t_row				*ft_row_clear(t_row *row);
t_row				*ft_row_set(t_row *row, int const col, char const *val);
t_row				*ft_row_setf(t_row *row, int const col, char const *fmt, ...);
void				ft_row_print_header(t_row const *row, int const endl);
void				ft_row_print(t_row const *row, int const endl);

void				print_result(int res);


# define TEST(name, val, match)											\
	ft_row_set(&g_row, 1, name);										\
	ft_row_set(&g_row, 2, #val);										\
	ft_snprintf((char*)buffer, 255, name, val);							\
	ret = ft_strncmp(buffer, match, 255);								\
	ft_row_setf(&g_row, 3, "'%s'", match);								\
	ft_row_setf(&g_row, 4, "'%s'", buffer);								\
	ft_row_set(&g_row, 5, "");											\
	print_result(ret);													\
	if (ret)															\
		return (ret);


#endif
