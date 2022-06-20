/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strstr
*/

#include "tests.h"

char * (*my_strstr)(const char *str, const char *substr);

void starter_strstr(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_strstr = dlsym(handle, "strstr");
    }
}

Test(strstr, basic_test, .init = starter_strstr)
{
    char *str = "Hello beautiful world";
    char *str2 = "beautiful";

    cr_assert_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(strstr, empty, .init = starter_strstr)
{
    char *str = "";
    char *str2 = "beautiful";

    cr_assert_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(strstr, both_empty, .init = starter_strstr)
{
    char *str = "";
    char *str2 = "";

    cr_assert_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(strstr, different_size, .init = starter_strstr)
{
    char *str = "Hello";
    char *str2 = "Hello world";

    cr_assert_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(strstr, start_substring, .init = starter_strstr)
{
    char *str = "Hello world i love rovers";
    char *str2 = "ov";

    cr_assert_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(strstr, exact_same_string, .init = starter_strstr)
{
    char *str = "Hello World";
    char *str2 = "Hello World";

    cr_assert_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(strstr, ending_str, .init = starter_strstr)
{
    char *str = "Hello world";
    char *str2 = "world";

    cr_assert_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(strstr, not_found, .init = starter_strstr)
{
    char *str = "Hello world";
    char *str2 = "lo earth";

    cr_assert_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(strstr, empty_substring, .init = starter_strstr)
{
    char *str = "Hello world";
    char *str2 = "";

    cr_assert_str_eq(my_strstr(str, str2), strstr(str, str2));
}