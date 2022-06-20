/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_memcpy
*/

#include "tests.h"

void *(*my_memcpy)(void *dest, const void *src, size_t n);

void starter_memcpy(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_memcpy = dlsym(handle, "memcpy");
    }
}

Test(memcpy, basic, .init = starter_memcpy)
{
    char str[] = "Hello";
    char *str2 = str;

    my_memcpy(str2, str2, 5);
    cr_assert_str_eq(str2, str);
}