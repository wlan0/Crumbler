#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "big_integer_impl.h"

typedef struct Big_Int
{
	struct big_integer *integer;
	char* (*get_integer)(struct Big_Int *x);
	int (*get_sign)(struct Big_Int *x);
	void (*set_integer)(struct Big_Int *this,char* integer);
	void (*set_sign)(struct Big_Int *this,int sign);
}Big_Int;

Big_Int* init_Big_Int();
Big_Int* init_Big_Int_from_char(char *value);
Big_Int* init_Big_Int_from_long(long long value);
Big_Int* init_Big_Int_from_int(int value);
Big_Int* add_Big_Ints(Big_Int *operand1,Big_Int *operand2,Big_Int *result);
int compare_Big_Ints(Big_Int *operand1,Big_Int *operand2);
void destroy_Big_int(Big_Int *obj);

#endif