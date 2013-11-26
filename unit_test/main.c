#include "unit_test.h"
#include "libft.h"
#include <string.h>
#include <strings.h>

UT_TEST(ft_memset)
{
	char	b1[100], b2[100];

	UT_BEGIN_TEST();
	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	UT_ASSERT_EQ(memset(b1, 33, 0), ft_memset(b1, 99, 0));
	UT_ASSERT_EQ(memcmp(b1, b2, 100), 0);
	UT_END_TEST();
}

UT_TEST(ft_bzero)
{
	char	b1[10], b2[10];
	UT_BEGIN_TEST();
	bzero(b1, 10);
	bzero(b2, 10);
	UT_ASSERT_EQ(memcmp(b1, b2, 10), 0);
	UT_END_TEST();
}

UT_TEST(ft_memcpy)
{
	char	b1[100], b2[100];

	UT_BEGIN_TEST();
	ft_memcpy(b1, b2, 100);
	UT_ASSERT_EQ(memcmp(b1, b2, 100), 0);
	UT_ASSERT_EQ(b1, ft_memcpy(b1, b2, 0));
	UT_END_TEST();
}

UT_TEST(ft_memccpy)
{
	char	buf1[] = "Ceci est un test.";
	char	buf2[200];
	void	*p1, *p2;
	UT_BEGIN_TEST();
	p1 = memccpy(buf2, buf1, 'i', 10);
	p2 = ft_memccpy(buf2, buf1, 'i', 10);
	UT_ASSERT_EQ(p1, p2);
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 'k', 5), 0);
	UT_ASSERT_EQ(ft_memccpy(buf2, buf1, 0, 0), 0);
	UT_END_TEST();
}

UT_TEST(ft_memmove)
{
	char	test[] = "abcdef";

	UT_BEGIN_TEST();
	ft_memmove(test + 1, test, 5);
	ft_memmove(test + 1, test, 0);
	UT_ASSERT_EQ(strcmp(test, "aabcde"), 0);
	UT_END_TEST();
}

UT_TEST(ft_memchr)
{
	char	test[] = "abcdef";

	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_memchr(test, 'c', 5), test + 2);
	UT_ASSERT_EQ(ft_memchr(test, 'z', 6), 0);
	UT_END_TEST();
}

UT_TEST(ft_memcmp)
{
	char	*t = "ab\0ab";

	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_memcmp(t, t, 5), 0);
	UT_ASSERT_NEQ(ft_memcmp(t, "abcab", 5) ,0);
	UT_END_TEST();
}

UT_TEST(ft_strlen)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_strlen("chat"), strlen("chat"));
	UT_ASSERT_EQ(ft_strlen(""), strlen(""));
	UT_END_TEST();
}

UT_TEST(ft_strdup)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(strcmp(ft_strdup("aaaaa"), "aaaaa"), 0);
	UT_END_TEST();
}

UT_TEST(ft_strcpy)
{
	char	buf[100];

	UT_BEGIN_TEST();
	ft_strcpy(buf, "abcde");
	UT_ASSERT_EQ(strcmp(buf, "abcde"), 0);
	UT_END_TEST();
}

UT_TEST(ft_strncpy)
{
	char	b[6];

	UT_BEGIN_TEST();
	ft_strncpy(b, "abc", 6);
	UT_ASSERT_EQ(memcmp(b, "abc\0\0", 6), 0);
	ft_strncpy(b, "abcdefghi", 6);
	UT_ASSERT_EQ(memcmp(b, "abcdefghi", 6), 0);
	UT_END_TEST();
}

UT_TEST(ft_strcat)
{
	char	buf[9];

	UT_BEGIN_TEST();
	bzero(buf, 9);
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "jour.");
	ft_strcat(buf, "");
	UT_ASSERT_EQ(strcmp(buf, "Bonjour."), 0);
	UT_END_TEST();
}

UT_TEST(ft_strncat)
{
	char	buf[20];

	UT_BEGIN_TEST();
	strcpy(buf, "To be ");
	ft_strncat(buf, "or not to be", 6);
	UT_ASSERT_EQ(strcmp(buf, "To be or not"), 0);
	UT_END_TEST();
}

UT_TEST(ft_strlcat)
{
	char	buf[10];

	UT_BEGIN_TEST();
	bzero(buf, 10);
	strcpy(buf, "abc");
	ft_strlcat(buf, "abcdefghijklmnop", 10);
	UT_ASSERT_EQ(strcmp(buf, "abcabcdef"), 0);
	UT_ASSERT_EQ(ft_strlcat(buf, "abcd", 2), 6);
	bzero(buf, 10);
	UT_ASSERT_EQ(ft_strlcat(buf, "abc", 10), 3);
	UT_ASSERT_EQ(ft_strlcat(buf, "def", 10), 6);
	bzero(buf, 10);
	memset(buf, 'a', 10);
	UT_ASSERT_EQ(ft_strlcat(buf, "ccc", 10), 13);
	UT_END_TEST();
}

UT_TEST(ft_strchr)
{
	char	buf[] = "Je suis un poisson.";

	UT_BEGIN_TEST();
	UT_ASSERT_EQ(strchr(buf, 'p'), ft_strchr(buf, 'p'));
	UT_ASSERT_EQ(strchr(buf, 0), ft_strchr(buf, 0));
	UT_ASSERT_EQ(ft_strchr(buf, 'z'), 0);
	UT_END_TEST();
}

UT_TEST(ft_strrchr)
{
	char	buf[] = "abcdedcba";

	UT_BEGIN_TEST();
	UT_ASSERT_EQ(strrchr(buf, 'a'), ft_strrchr(buf, 'a'));
	UT_ASSERT_EQ(strrchr(buf, 0), ft_strrchr(buf, 0));
	UT_ASSERT_EQ(ft_strrchr(buf, 'z'), 0);
	UT_END_TEST();
}

UT_TEST(ft_strstr)
{
	char	buf[] = "Ceci n'est pas une pipe.";

	UT_BEGIN_TEST();
	UT_ASSERT_EQ(strstr(buf, "une"), ft_strstr(buf, "une"));
	UT_ASSERT_EQ(strstr(buf, ""), ft_strstr(buf, ""));
	UT_ASSERT_EQ(strstr(buf, "aaaaa"), ft_strstr(buf, "aaaaa"));
	UT_END_TEST();
}

UT_TEST(ft_strnstr)
{
	char	buf[10];

	UT_BEGIN_TEST();
	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
	UT_ASSERT_EQ(strnstr(buf, "9", 3), ft_strnstr(buf, "9", 3));
	UT_ASSERT_EQ(ft_strnstr(buf, "", 6), buf);
	UT_ASSERT_EQ(ft_strnstr(buf, "deux", 5), strnstr(buf, "deux", 5));
	buf[9] = '6';
	UT_ASSERT_EQ(strnstr(buf, "cinq", 10), ft_strnstr(buf, "cinq", 10));
	UT_ASSERT_EQ(strnstr(buf, "deux", 10), ft_strnstr(buf, "deux", 10));
	UT_END_TEST();
}

UT_TEST(ft_strcmp)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_strcmp("abc", "abc"), 0);
	UT_ASSERT(ft_strcmp("abc", "abd") < 0);
	UT_ASSERT_NEQ(ft_strcmp("a", "abcde"), 0)
	UT_END_TEST();
}

UT_TEST(ft_strncmp)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_strncmp("abc", "abcde", 3), 0);
	UT_ASSERT_EQ(ft_strncmp("abc", "abc\0defg", 100), 0);
	UT_ASSERT_NEQ(ft_strncmp("ab\0cde", "abcc\0e", 20), 0);
	UT_END_TEST();
}

UT_TEST(ft_atoi)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_atoi(" -sfecf"), 0);
	UT_ASSERT_EQ(ft_atoi("+2798"), 2798);
	UT_ASSERT_EQ(ft_atoi("  \t\n  \r\r\v\f-899"), -899);
	UT_ASSERT_EQ(ft_atoi("+0089"), 89);
	UT_ASSERT_EQ(ft_atoi("-2147483648"), -2147483648);
	UT_END_TEST();
}

UT_TEST(ft_isalpha)
{
	UT_BEGIN_TEST();
	UT_ASSERT_NEQ(ft_isalpha('a'), 0);
	UT_ASSERT_EQ(ft_isalpha('a' + 0x100), 0);
	UT_ASSERT_EQ(ft_isalpha('2'), 0);
	UT_ASSERT_NEQ(ft_isalpha('Z'), 0);
	UT_ASSERT_NEQ(ft_isalpha('t'), 0);
	UT_END_TEST();
}

UT_TEST(ft_isdigit)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_isdigit(0), 0);
	UT_ASSERT_NEQ(ft_isdigit('8'), 0);
	UT_ASSERT_EQ(ft_isdigit('8' + 0x100), 0);
	UT_END_TEST();
}

UT_TEST(ft_isalnum)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_isalnum(' '), 0);
	UT_ASSERT_NEQ(ft_isalnum('6'), 0);
	UT_ASSERT_NEQ(ft_isalnum('Z'), 0);
	UT_ASSERT_EQ(ft_isalnum('5' + 0x100), 0);
	UT_END_TEST();
}

UT_TEST(ft_isascii)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_isascii(200), 0);
	UT_ASSERT_NEQ(ft_isascii(0), 0);
	UT_ASSERT_NEQ(ft_isascii(127), 0);
	UT_END_TEST();
}

UT_TEST(ft_isprint)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_isprint(0), 0);
	UT_ASSERT_EQ(ft_isprint(127), 0);
	UT_ASSERT_NEQ(ft_isprint(' '), 0);
	UT_ASSERT_NEQ(ft_isprint('a'), 0);
	UT_ASSERT_NEQ(ft_isprint(126), 0);
	UT_END_TEST();
}

UT_TEST(ft_toupper)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_toupper('a'), 'A');
	UT_ASSERT_EQ(ft_toupper(12345), 12345);
	UT_ASSERT_EQ(ft_toupper(' '), ' ');
	UT_ASSERT_EQ(ft_toupper('Z'), 'Z');
	UT_END_TEST();
}

UT_TEST(ft_tolower)
{
	UT_BEGIN_TEST();
	UT_ASSERT_EQ(ft_tolower('T'), 't');
	UT_ASSERT_EQ(ft_tolower(99999), 99999);
	UT_ASSERT_EQ(ft_tolower('e'), 'e');
	UT_END_TEST();
}

int	main(void)
{
	UT_ADD_TEST(ft_memset);
	UT_ADD_TEST(ft_bzero);
	UT_ADD_TEST(ft_memcpy);
	UT_ADD_TEST(ft_memccpy);
	UT_ADD_TEST(ft_memmove);
	UT_ADD_TEST(ft_memchr);
	UT_ADD_TEST(ft_memcmp);
	UT_ADD_TEST(ft_strlen);
	UT_ADD_TEST(ft_strdup);
	UT_ADD_TEST(ft_strcpy);
	UT_ADD_TEST(ft_strncpy);
	UT_ADD_TEST(ft_strcat);
	UT_ADD_TEST(ft_strncat);
	UT_ADD_TEST(ft_strlcat);
	UT_ADD_TEST(ft_strchr);
	UT_ADD_TEST(ft_strrchr);
	UT_ADD_TEST(ft_strstr);
	UT_ADD_TEST(ft_strnstr);
	UT_ADD_TEST(ft_strcmp);
	UT_ADD_TEST(ft_strncmp);
	UT_ADD_TEST(ft_atoi);
	UT_ADD_TEST(ft_isalpha);
	UT_ADD_TEST(ft_isdigit);
	UT_ADD_TEST(ft_isalnum);
	UT_ADD_TEST(ft_isascii);
	UT_ADD_TEST(ft_isprint);
	UT_ADD_TEST(ft_toupper);
	UT_ADD_TEST(ft_tolower);
	UT_RUN_ALL_TESTS();
	return (0);
}
