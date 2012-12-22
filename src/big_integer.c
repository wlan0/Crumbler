#include "big_integer.h"

struct big_integer *integer;

//The getters and setters require that the structure calling them is initialized
char* get_integer_as_char()
{
	return integer->value;
}

int get_sign_as_int()
{
	return integer->sign;
}


Big_Int* init_Big_Int()
{
	struct Big_Int *temp = (struct Big_Int*)malloc(sizeof(struct Big_Int));
	integer = init_big_integer();
	temp->integer = integer;
	temp->get_integer = get_integer_as_char;
	temp->get_sign = get_sign_as_int;
	return temp;
}

Big_Int* init_Big_Int_from_char(char *value)
{
	struct Big_Int *temp = (struct Big_Int*)malloc(sizeof(struct Big_Int));
	integer = init_big_integer_from_char(value);
	temp->integer = integer;
	temp->get_integer = get_integer_as_char;
	temp->get_sign = get_sign_as_int;
	return temp;
}

Big_Int* init_Big_Int_from_long(long long value)
{
	struct Big_Int *temp = (struct Big_Int*)malloc(sizeof(struct Big_Int));
	integer = init_big_integer_from_long(value);
	temp->integer = integer;
	temp->get_integer = get_integer_as_char;
	temp->get_sign = get_sign_as_int;
	return temp;
}

Big_Int* init_Big_Int_from_int(int value)
{
	struct Big_Int *temp = (struct Big_Int*)malloc(sizeof(struct Big_Int));
	integer = init_big_integer_from_int(value);
	temp->integer = integer;
	temp->get_integer = get_integer_as_char;
	temp->get_sign = get_sign_as_int;
	return temp;
}

/*int main()
{
	struct Big_Int *x = init_Big_Int_from_int(123);
	struct Big_Int *y = init_Big_Int_from_int(12345);
	printf("message : %s\n",x->get_integer());
	return 0;
}*/


