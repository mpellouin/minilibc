/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strlen
*/

#include "tests.h"

char * (*my_strchr)(const char *str, char to_find);
char * (*my_strrchr)(const char *str, char to_find);

void starter_strchr(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_strchr = dlsym(handle, "strchr");
        my_strrchr = dlsym(handle, "strrchr");
    }
}

Test(strchr, basic_test, .init = starter_strchr)
{
    char *str = "Hello i'm a stupid sandwich";
    char c = 'i';
    char d = '\0';
    char e = 'z';

    cr_assert_eq(my_strchr(str, c), strchr(str, c));
    cr_assert_eq(my_strchr(str, d), strchr(str, d));
    cr_assert_eq(my_strchr(str, e), strchr(str, e));
}

Test(strrchr, basic_test, .init = starter_strchr)
{
    char *str = "Hi world!";
    char c = 'i';
    char d = '\0';
    char e = 'z';

    cr_assert_eq(my_strrchr(str, c), strrchr(str, c));
    cr_assert_eq(my_strrchr(str, d), strrchr(str, d));
    cr_assert_eq(my_strrchr(str, e), strrchr(str, e));
}