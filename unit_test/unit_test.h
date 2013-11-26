#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <stdio.h>

# define UT_TEST(name)		int ut_test_ ## name(void)
# define UT_ASSERT(cond)	if(!(cond)) {_asserts_fails++;}
# define UT_RUN_TEST(test_)	printf("Testing %s...\t\t", test_->name); if((test_->test())) \
				{ puts("Fail."); _test_fails++; } else { puts("Ok !");}
# define UT_BEGIN_TEST()	int _asserts_fails = 0
# define UT_END_TEST()		return (_asserts_fails)
# define UT_ADD_TEST(name)	ut_add_test_(&ut_test_ ## name, #name)
# define UT_RUN_ALL_TESTS()	ut_run_all_tests_()

/*
 *  Bonus
 */

# define UT_ASSERT_EQ(a, b)	UT_ASSERT((a) == (b))
# define UT_ASSERT_NEQ(a, b)	UT_ASSERT((a) != (b))

typedef	int (*ut_test)(void);

typedef struct			ut_test_list_s
{
	ut_test			test;
	char			*name;
	struct ut_test_list_s	*next;
}				ut_test_list_t;

extern	ut_test_list_t		*ut_tests;

ut_test_list_t			*ut_create_list_(ut_test, char *);
void				ut_add_test_(ut_test, char *);
int				ut_run_all_tests_(void);

#endif /* !UNIT_TEST_H */
