/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_rindex
*/

#include "tests.h"

char *(*my_rindex)(const char *str, int c);

void starter_rindex(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else
    {
        my_rindex = dlsym(handle, "rindex");
    }
}

Test(rindex, basic, .init = starter_rindex)
{
    char *str = "fefefe";
    int c = 'e';

    cr_assert_eq(my_rindex(str, c), rindex(str, c));
}

Test(rindex, basic2, .init = starter_rindex)
{
    char *str = "efefef";
    int c = 'e';

    cr_assert_eq(my_rindex(str, c), rindex(str, c));
}

Test(rindex, end_of_string, .init = starter_rindex)
{
    char *str = "fefef";
    int c = '\0';

    cr_assert_eq(my_rindex(str, c), rindex(str, c));
}

Test(rindex, not_found, .init = starter_rindex)
{
    char *str = "fefef";
    int c = 'z';

    cr_assert_eq(my_rindex(str, c), rindex(str, c));
}

Test(rindex, empty_string, .init = starter_rindex)
{
    char *str = "";
    int c = 'z';

    cr_assert_eq(my_rindex(str, c), rindex(str, c));
}