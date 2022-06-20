/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strcmp
*/

#include "tests.h"

int (*my_strcmp)(const char *str, const char *str2);

void starter_strcmp(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_strcmp = dlsym(handle, "strcmp");
    }
}

Test(strcmp, basic, .init = starter_strcmp)
{
    char *str = "fefefe";
    char *str2 = "fefef";

    cr_assert_eq(my_strcmp(str, str2), strcmp(str, str2));
}

Test(strcmp, basic2, .init = starter_strcmp)
{
    char *str = "fefef";
    char *str2 = "fefef";

    cr_assert_eq(my_strcmp(str, str2), strcmp(str, str2));
}