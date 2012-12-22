#include "big_integer.h"

typedef struct Big_Int
{
	big_integer *integer;
	Big_Int* (*get_integer_as_char)()
}Big_Int;



