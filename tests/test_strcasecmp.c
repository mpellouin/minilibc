/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strcasecmp
*/

#include "tests.h"

int (*my_strcasecmp)(const char *str, const char *str2);

void starter_casecmp(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_strcasecmp = dlsym(handle, "strcasecmp");
    }
}

Test(strcasecmp, basic_test, .init = starter_casecmp)
{
    char *str = "Hello WoRlD";
    char *str2 = "heLLO world";

    cr_assert_eq(my_strcasecmp(str, str2), strcasecmp(str, str2));
}

Test(strcasecmp, empty, .init = starter_casecmp)
{
    char *str = "";
    char *str2 = "Hello world";

    printf("%d %d\n", my_strcasecmp(str, str2), strcasecmp(str, str2));
    cr_assert_eq(my_strcasecmp(str, str2), strcasecmp(str, str2));
}

Test(strcasecmp, both_empty, .init = starter_casecmp)
{
    char *str = "";
    char *str2 = "";

    cr_assert_eq(my_strcasecmp(str, str2), strcasecmp(str, str2));
}

Test(strcasecmp, different_size, .init = starter_casecmp)
{
    char *str = "Hello";
    char *str2 = "Hello world";

    printf("%d %d\n", my_strcasecmp(str, str2), strcasecmp(str, str2));

    cr_assert_eq(my_strcasecmp(str, str2), strcasecmp(str, str2));
}

Test(strcasecmp, different_size2, .init = starter_casecmp)
{
    char *str = "Hello world";
    char *str2 = "Hello";

    printf("%d %d\n", my_strcasecmp(str, str2), strcasecmp(str, str2));

    cr_assert_eq(my_strcasecmp(str, str2), strcasecmp(str, str2));
}