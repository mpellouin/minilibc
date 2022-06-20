/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strlen
*/

#include "tests.h"

long unsigned int (*my_strlen)(const char *str);

void starter_strlen(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_strlen = dlsym(handle, "strlen");
    }
}

Test(strlen, basic_test, .init = starter_strlen)
{
    char *str = "Hello World";

    cr_assert_eq(my_strlen(str), strlen(str));
}

Test(strlen, empty, .init = starter_strlen)
{
    char *str = "";

    cr_assert_eq(my_strlen(str), strlen(str));
}