#include "libft.h"
#include "common.h"
#include <ctype.h>

#define FUNC_NAME "strcat"

void	do_copy(char **buffer, size_t buffer_size, char const *str)
{
	FILE	*stream;
	char	*verif_buf;

	buffer_size = buffer_size > ft_strlen(str) ? buffer_size : ft_strlen(str);
	verif_buf = ft_strnew(buffer_size);
	ft_strcpy(*buffer, str);
	strcpy(verif_buf, str);
	stream = strcmp(verif_buf, *buffer) == 0 ? stdout : stderr;
	fprintf(stream,
			"Copied %s to %s: %s - %s\n",
			str,
			*buffer,
			verif_buf,
			strcmp(*buffer, verif_buf) ? "false" : "true");
	ft_strdel(&verif_buf);
}

void	do_cat(char **buffer, size_t buffer_size, char const *str)
{
	FILE	*stream;
	char	*verif_buf;

	buffer_size = buffer_size > ft_strlen(str) ? buffer_size : ft_strlen(str);
	verif_buf = ft_strnew(buffer_size);
	strcpy(verif_buf, *buffer);
	strcat(verif_buf, str);
	ft_strcat(*buffer, str);
	stream = strcmp(verif_buf, *buffer) == 0 ? stdout : stderr;
	fprintf(stream,
			"Catted %s to %s: %s - %s\n",
			str,
			*buffer,
			verif_buf,
			strcmp(*buffer, verif_buf) ? "false" : "true");
	ft_strdel(&verif_buf);
}
void	do_test(char const *a, char const *b)
{
	size_t	len = ft_strlen(a) + ft_strlen(b);
	char	*buf = ft_strnew(len);

	if (!buf)
		return ;
	do_copy(&buf, len, a);
	do_cat(&buf, len, b);

	ft_strdel(&buf);
}


int	main(void)
{
	print_hr();
	printf("Testing '%s':\n", FUNC_NAME);
	print_hr();

	do_test("Bite", "Molle");
	do_test("", "Molle");
	do_test("Bite", "");
	do_test("", "");

	print_hr();
	return (0);
}
