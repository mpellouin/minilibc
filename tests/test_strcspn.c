/*
** EPITECH PROJECT, 2022
** minilibc
** File description:
** test_strlen
*/

#include "tests.h"

int (*my_strcspn)(const char *str, const char *str2);

void starter_strcspn(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, ".libasm.so not found\n", 22);
    else {
        my_strcspn = dlsym(handle, "strcspn");
    }
}

Test(strcspn, basic_test, .init = starter_strcspn)
{
    char *str = "";
    char *str2 = "fefef";

    cr_assert_eq(my_strcspn(str, str2), strcspn(str, str2));
}

Test(strcspn, basic_test2, .init = starter_strcspn)
{
    char *str = "";
    char *str2 = "";

    cr_assert_eq(my_strcspn(str, str2), strcspn(str, str2));
}

Test(strcspn, basic_test3, .init = starter_strcspn)
{
    char *str = "rer";
    char *str2 = "";

    printf("========>%d %d\n", my_strcspn(str, str2), strcspn(str, str2));

    cr_assert_eq(my_strcspn(str, str2), strcspn(str, str2));
}

Test(strcspn, same_string, .init = starter_strcspn)
{
    char *str = "fefef";
    char *str2 = "fefef";

    printf("%d %d\n", my_strcspn(str, str2), strcspn(str, str2));

    cr_assert_eq(my_strcspn(str, str2), strcspn(str, str2));
}

Test(strcspn, 1_char_in_str2, .init = starter_strcspn)
{
    char *str = "fefef";
    char *str2 = "f";

    printf("%d %d\n", my_strcspn(str, str2), strcspn(str, str2));

    cr_assert_eq(my_strcspn(str, str2), strcspn(str, str2));
}

Test(strcspn, 1_char_in_str2_2, .init = starter_strcspn)
{
    char *str = "fefef";
    char *str2 = "e";

    printf("===> %d %d\n", my_strcspn(str, str2), strcspn(str, str2));

    cr_assert_eq(my_strcspn(str, str2), strcspn(str, str2));
}