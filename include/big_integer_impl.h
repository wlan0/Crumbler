#ifndef BIG_INTEGER_IMPL_H
#define BIG_INTEGER_IMPL_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct big_integer
{
    char *value;
    int sign;
}big_integer;

big_integer* init_big_integer();
big_integer* init_big_integer_from_int(int int_value);
big_integer* init_big_integer_from_long(long long long_long_value);
big_integer* init_big_integer_from_char(char *char_value);
int compare_big_integers(struct big_integer *operand1, struct big_integer *operand2);
big_integer* add_big_integers(struct big_integer *operand1, struct big_integer *operand2, struct big_integer *result);
void destroy_big_integer(big_integer *obj);

#endif