#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "big_integer_impl.h"

typedef struct Big_Int
{
	struct big_integer *integer;
	char* (*get_integer)();
	int (*get_sign)();
}Big_Int;

Big_Int* init_Big_Int();
Big_Int* init_Big_Int_from_char(char *value);
Big_Int* init_Big_Int_from_long(long long value);
Big_Int* init_Big_Int_from_int(int value);

#endif