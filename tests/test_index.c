/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_index
*/

#include "tests.h"

char *(*my_index)(const char *str, int c);

void starter_index(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else
    {
        my_index = dlsym(handle, "index");
    }
}

Test(index, basic, .init = starter_index)
{
    char *str = "fefefe";
    int c = 'e';

    cr_assert_eq(my_index(str, c), index(str, c));
}

Test(index, basic2, .init = starter_index)
{
    char *str = "efefef";
    int c = 'e';

    cr_assert_eq(my_index(str, c), index(str, c));
}

Test(index, end_of_string, .init = starter_index)
{
    char *str = "fefef";
    int c = '\0';

    cr_assert_eq(my_index(str, c), index(str, c));
}

Test(index, not_found, .init = starter_index)
{
    char *str = "fefef";
    int c = 'z';

    cr_assert_eq(my_index(str, c), index(str, c));
}

Test(index, empty_string, .init = starter_index)
{
    char *str = "";
    int c = 'z';

    cr_assert_eq(my_index(str, c), index(str, c));
}