#include "big_integer.h"

//The getters and setters require that the structure calling them is initialized
char* get_integer_as_char(Big_Int *x)
{
	return x->integer->value;
}

int get_sign_as_int(Big_Int *x)
{
	return x->integer->sign;
}

void set_integer(Big_Int *x,char *y)
{
	free(x->integer->value);
	x->integer->value = (char*)malloc(strlen(y));
	memcpy(x->integer->value,y,strlen(y));
}

void set_sign(Big_Int *x, int sign)
{
	x->integer->sign = sign;
}

Big_Int* init_Big_Int()
{
	struct Big_Int *temp = (struct Big_Int*)malloc(sizeof(struct Big_Int));
	temp->integer = init_big_integer();
	temp->get_integer = get_integer_as_char;
	temp->get_sign = get_sign_as_int;
	temp->set_integer = set_integer;
	temp->set_sign = set_sign;
	return temp;
}

Big_Int* init_Big_Int_from_char(char *value)
{
	struct Big_Int *temp = (struct Big_Int*)malloc(sizeof(struct Big_Int));
	temp->integer =init_big_integer_from_char(value);
	temp->get_integer = get_integer_as_char;
	temp->get_sign = get_sign_as_int;
	temp->set_integer = set_integer;
	temp->set_sign = set_sign;
	return temp;
}

Big_Int* init_Big_Int_from_long(long long value)
{
	struct Big_Int *temp = (struct Big_Int*)malloc(sizeof(struct Big_Int));
	temp->integer = init_big_integer_from_long(value);
	temp->get_integer = get_integer_as_char;
	temp->get_sign = get_sign_as_int;
	temp->set_integer = set_integer;
	temp->set_sign = set_sign;
	return temp;
}

Big_Int* init_Big_Int_from_int(int value)
{
	struct Big_Int *temp = (struct Big_Int*)malloc(sizeof(struct Big_Int));
	temp->integer = init_big_integer_from_int(value);
	temp->get_integer = get_integer_as_char;
	temp->get_sign = get_sign_as_int;
	temp->set_integer = set_integer;
	temp->set_sign = set_sign;
	return temp;
}

int compare_Big_Ints(Big_Int *operand1,Big_Int *operand2)
{
	return compare_big_integers(operand1->integer,operand2->integer);
}

Big_Int* add_Big_Ints(Big_Int *operand1,Big_Int *operand2,Big_Int *result)
{
	
}

void destroy_Big_Int(Big_Int *obj)
{
	destroy_big_integer(obj->integer);
	free(obj);
}

/*int main()
{
	
	return 0;
}*/


