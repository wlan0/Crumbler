/*!
 * \file big_integer.c
 * \brief The interface to the implementation of big integer logic
 * This file contains functions required to interface with the big integer manipulation functions.<br/> 
 * Author : Sidhartha Mani<br/>
 * Contact : sidharthamn@gmail.com <br/>
 * Last Updated : 24 Dec 2012 <br/>
 * \ingroup core 
 */

#include "big_integer.h"

/*! \fn char* get_integer_as_char(Big_Int *x)
 *  \brief accessor to access the big_integer value
 *  \param a pointer to self
 *  \return a char array that contains the big_integer value as a string
 */
char* get_integer_as_char(Big_Int *x)
{
	return x->integer->value;
}

/*! \fn int get_sign_as_int(Big_Int *x)
 *  \brief accessor to access the big_integer sign(+ve or -ve)
 *  \param a pointer to self
 *  \return <br/>
 *  Returns >=0, if positive <br/>
 *  Returns < 0, if negative 
 */
int get_sign_as_int(Big_Int *x)
{
	return x->integer->sign;
}

/*! \fn void set_integer(Big_Int *x,char *y)
 *  \brief sets the integer value of Big_Int to the value pointed by param2
 *  \param x a pointer to self
 *  \param y a pointer to the new value
 *  \return Nothing
 */
void set_integer(Big_Int *x,char *y)
{
	free(x->integer->value);
	x->integer->value = (char*)malloc(strlen(y));
	memcpy(x->integer->value,y,strlen(y));
}

/*! \fn void set_sign(Big_Int *x,int sign)
 *  \brief sets the sign of Big_Int to the value in param2
 *  \param x a pointer to self
 *  \param sign the sign of the Big_Int <br/>
 *  sign >=0, if positive <br/>
 *  sign < 0, if negative 
 *  \return Nothing
 */
void set_sign(Big_Int *x, int sign)
{
	x->integer->sign = sign;
}

/*! \fn Big_Int* init_Big_Int()
 *  \brief allocates memory for a new Big_Int and returns a pointer to allocated memory <br/>
 *  <b> Precondition: </b> the pointer capturing the new memory should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> the pointer is allocated memory <br/>
 *  \return a pointer to the newly allocated memory to hold a Big_Int variable
 */
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

/*! \fn Big_Int* init_Big_Int_from_char(char *value)
 *  \brief allocates memory for a new Big_Int, initializes it to the value in value and returns a pointer
 *  to allocated memory. <br/>
 *  <b> Precondition: </b> the pointer capturing the new memory should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> the pointer is initialized and allocated memory <br/>
 *  \param value the value that will be copied into the new big_integer
 *  \return a pointer to the newly allocated memory to hold a Big_Int variable containing the value in value
 */
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

/*! \fn Big_Int* init_Big_Int_from_long(long long value)
 *  \brief allocates memory for a new Big_Int, initializes it to the value in value and returns a pointer
 *  to allocated memory. <br/>
 *  <b> Precondition: </b> the pointer capturing the new memory should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> the pointer is initialized and allocated memory <br/>
 *  \param value the value that will be copied into the new big_integer
 *  \return a pointer to the newly allocated memory to hold a Big_Int variable containing the value in value
 */
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

/*! \fn Big_Int* init_Big_Int_from_int(int value)
 *  \brief allocates memory for a new Big_Int, initializes it to the value in value and returns a pointer
 *  to allocated memory. <br/>
 *  <b> Precondition: </b> the pointer capturing the new memory should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> the pointer is initialized and allocated memory <br/>
 *  \param value the value that will be copied into the new big_integer
 *  \return a pointer to the newly allocated memory to hold a Big_Int variable containing the value in value
 */
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

/*! \fn int compare_Big_Ints(Big_Int *operand1,Big_Int *operand2)
 *  \brief comapres two positive big integers only <br/>
 *  <b>Precondition :</b> Both operand should have been initialized
 *  <b>Postcondition :</b> The comparison result is provided
 *  \param operand1 the operand against which the other operand will be compared
 *  \param operand2 the operand which will be compared against operand1
 *  \return <br/>
 *  Returns   0 : if both numbers are equal <br/>
 *  Returns > 0 : if first value is larger <br/>
 *  Returns < 0 : if first value is smaller
 */
int compare_Big_Ints(Big_Int *operand1,Big_Int *operand2)
{
	return compare_big_integers(operand1->integer,operand2->integer);
}

/*! \fn void destroy_Big_Int(Big_Int *obj)
 *  \brief frees the allocated memory <br/>
 *  <b> Precondition: </b> the Big_Int pointer which it is being freed should not have been freed already <br/>
 *  <b> Postcondition: </b>The big_integer structure is freed
 *  \param operand1 the pointer to the structure which should be freed
 *  \return Nothing
 */ 
void destroy_Big_Int(Big_Int *obj)
{
	destroy_big_integer(obj->integer);
	free(obj);
}

/*! \fn Big_Int* add_Big_Ints(Big_Int *operand1,Big_Int *operand2,Big_Int *result)
 *  \brief adds two positive integers only<br/>
 *  <b> Postcondition: </b>the Big_Int object containing the sum is returned
 *  \param operand1 the first Big_Int operand for addition
 *  \param operand2 the second Big_Int operand for addition
 *  \param result the Big_Int structure in which the result should be stored, its ok if it was previously initialized or not
 *  \return a pointer to the Big_Int holding the sum
 */
Big_Int* add_Big_Ints(Big_Int *operand1,Big_Int *operand2,Big_Int *result)
{
	struct Big_Int *temp = init_Big_Int();
	temp->integer = add_big_integers(operand1->integer,operand2->integer,temp->integer);
	destroy_Big_Int(result);
	result = temp;
	return result;
}

/*int main()
{
	
	return 0;
}*/


