/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_memset
*/

#include "tests.h"

void *(*my_memset)(void *str, int c, size_t n);

void starter_memset(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_memset = dlsym(handle, "memset");
    }
}

Test(memset, basic, .init = starter_memset)
{
    char str[] = "Hello";
    char *str2 = str;
    char str3[] = "Babar";
    char *str4 = str3;

    my_memset(str2, 'a', 5);
    my_memset(str4, 'a', 5);
    cr_assert_str_eq(str2, str4);
}