/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strpbrk
*/

#include "tests.h"

char *(*my_strpbrk)(const char *str, const char *str2);

void starter_strpbrk(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_strpbrk = dlsym(handle, "strpbrk");
    }
}

Test(strpbrk, basic, .init = starter_strpbrk)
{
    char *str = "Hello World";
    char *str2 = "asm";

    cr_assert_eq(my_strpbrk(str, str2), strpbrk(str, str2));
}

Test(strpbrk, basic2, .init = starter_strpbrk)
{
    char *str = "this is an easter egg, please star the repository";
    char *str2 = "";

    cr_assert_eq(my_strpbrk(str, str2), strpbrk(str, str2));
}

Test(strpbrk, basic3, .init = starter_strpbrk)
{
    char *str = "";
    char *str2 = "";

    cr_assert_eq(my_strpbrk(str, str2), strpbrk(str, str2));
}

Test(strpbrk, basic4, .init = starter_strpbrk)
{
    char *str = "";
    char *str2 = "thank you";

    cr_assert_eq(my_strpbrk(str, str2), strpbrk(str, str2));
}