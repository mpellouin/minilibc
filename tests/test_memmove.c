/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_memmove
*/

#include "tests.h"

void *(*my_memmove)(void *dest, const void *src, size_t n);

void starter_memmove(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_memmove = dlsym(handle, "memmove");
    }
}

Test(memmove, basic, .init = starter_memmove)
{
    char str[] = "Hello";
    char *str2 = str;

    my_memmove(str2, str2, 5);
    cr_assert_str_eq(str2, str);
}

Test(memmove, basic2, .init = starter_memmove)
{
    char str[] = "Hello";
    char *str2 = str;
    char str3[] = "Hello";
    char *str4 = str;

    my_memmove(str2 + 3, str2, 5);
    memmove(str4 + 3, str4, 5);
    cr_assert_str_eq(str2, str4);
}

Test(memmove, empty_string, .init = starter_memmove)
{
    char str[] = "";
    char *str2 = str;
    char str3[] = "";
    char *str4 = str;

    my_memmove(str2, str2, 0);
    memmove(str4, str4, 0);
    cr_assert_str_eq(str2, str4);
}

Test(memmove, empty_string2, .init = starter_memmove)
{
    char str[] = "";
    char *str2 = str;
    char str3[] = "";
    char *str4 = str;

    my_memmove(str2, str2, 5);
    memmove(str4, str4, 5);
    cr_assert_str_eq(str2, str4);
}

Test(memmove, move_1_byte, .init = starter_memmove)
{
    char str[] = "Hello";
    char *str2 = str;
    char str3[] = "Hello";
    char *str4 = str;

    my_memmove(str2 + 3, str2, 1);
    memmove(str4 + 3, str4, 1);
    cr_assert_str_eq(str2, str4);
}