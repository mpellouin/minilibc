/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strlen
*/

#include "tests.h"

int (*my_strncmp)(const char *str, const char *str2, int n);

void starter_strncmp(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_strncmp = dlsym(handle, "strncmp");
    }
}

Test(strncmp, basic, .init = starter_strncmp)
{
    char *str = "fefefe";
    char *str2 = "fefef";

    cr_assert_eq(my_strncmp(str, str2, 2), strncmp(str, str2, 2));
}

Test(strncmp, basic2, .init = starter_strncmp)
{
    char *str = "fefefe";
    char *str2 = "fefef";

    cr_assert_eq(my_strncmp(str, str2, 15), strncmp(str, str2, 15));
}

Test(strncmp, basic3, .init = starter_strncmp)
{
    char *str = "fefefe";
    char *str2 = "fefef";

    printf("%d %d\n", my_strncmp(str, str2, 4), strncmp(str, str2, 4));
    cr_assert_eq(my_strncmp(str, str2, 5), strncmp(str, str2, 5));
}

Test(strncmp, basic_test, .init = starter_strncmp)
{
    char *str = "";
    char *str2 = "fefef";

    cr_assert_eq(my_strncmp(str, str2, 5), strncmp(str, str2, 5));
}

Test(strncmp, basic_test2, .init = starter_strncmp)
{
    char *str = "";
    char *str2 = "";

    cr_assert_eq(my_strncmp(str, str2, 5), strncmp(str, str2, 5));
}

Test(strncmp, basic_test3, .init = starter_strncmp)
{
    char *str = "rer";
    char *str2 = "";

    cr_assert_eq(my_strncmp(str, str2, 5), strncmp(str, str2, 5));
}