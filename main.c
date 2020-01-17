/*
** EPITECH PROJECT, 2020
** fizz-buzz
** File description:
** fizz-buzz-desu
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int check(char *str1, char *str2)
{
    int test = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] >= '0' && str1[i] <= '9')
            test += 1;
        else if (i == 0 && (str1[i] == '-' || str1[i] == '+'))
            test += 1;
        else
            return 1;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] >= '0' && str2[i] <= '9')
            test += 1;
        else if (i == 0 && (str2[i] == '-' || str2[i] == '+'))
            test += 1;
        else
            return 1;
    }
    return 0;
}

int error_is(void)
{
    char *a;

    a = "Error: the second parameter must be greater than the first one.";
    my_puterror(a, 0);
    return 1;
}

int convert(char *str1, char *str2, int *nb1, int *nb2)
{
    if (check(str1, str2))
        return 1;
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] >= '0' && str1[i] <= '9') {
            *nb1 *= 10;
            *nb1 += (str1[i] - '0');
        }
    for (int i = 0; str2[i] != '\0'; i++)
        if (str2[i] >= '0' && str2[i] <= '9') {
            *nb2 *= 10;
            *nb2 += (str2[i] - '0');
        }
    if (str1[0] == '-')
        *nb1 *= (-1);
    if (str2[0] == '-')
        *nb2 *= (-1);
    if (*nb1 > *nb2)
        return error_is();
    return 0;
}

int main(int argc, char *argv[])
{
    int nb1 = 0;
    int nb2 = 0;

    if (argc != 3 || convert(argv[1], argv[2], &nb1, &nb2) == 1)
        return 84;
    for (int i = nb1; i <= nb2; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            if (i % 3 == 0 && i % 5 == 0)
                printf("FizzBuzz\n");
            if (i % 5 == 0 && i % 3 != 0)
                printf("Buzz\n");
            if (i % 3 == 0 && i % 5 != 0)
                printf("Fizz\n");
        }
        else
            printf("%d\n", i);
    }
    return 0;
}
