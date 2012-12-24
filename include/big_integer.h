/*! \file big_integer.h
 *  \brief serves as the interface to Big Integer Implementation
 *  This file contains functions required to support big integer manipulation.<br/> 
 *  Author : Sidhartha Mani<br/>
 *  Contact : sidharthamn@gmail.com <br/>
 *  Last Updated : 23 Dec 2012 <br/>
 *  \ingroup core 
 */

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "big_integer_impl.h"

/*! \struct Big_Int
 *  \brief A data structure that holds big integer values
 */
typedef struct Big_Int
{
	/*! an instances of the internal big_integer type*/ 
	struct big_integer *integer;
	/*! an accesor function which returns the integer as a character array */
	char* (*get_integer)(struct Big_Int *x);
	/*!  an accesor function which returns the sign as an integer value. 1 : positive and '0', 2: negative,*/
	int (*get_sign)(struct Big_Int *x);
	/*!  a function to set the integer value to the value in param 2*/
	void (*set_integer)(struct Big_Int *this,char* integer);
	/*!  a function to set sign to the value in param 2*/
	void (*set_sign)(struct Big_Int *this,int sign);
}Big_Int;

/*! \fn Big_Int* init_Big_Int()
 *  \brief allocates memory for a new Big_Int and returns a pointer to allocated memory <br/>
 *  <b> Precondition: </b> the pointer capturing the new memory should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> the pointer is allocated memory <br/>
 *  \return a pointer to the newly allocated memory to hold a Big_Int variable
 */
Big_Int* init_Big_Int();

/*! \fn Big_Int* init_Big_Int_from_char(char *value)
 *  \brief allocates memory for a new Big_Int, initializes it to the value in value and returns a pointer
 *  to allocated memory. <br/>
 *  <b> Precondition: </b> the pointer capturing the new memory should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> the pointer is initialized and allocated memory <br/>
 *  \param value the value that will be copied into the new big_integer
 *  \return a pointer to the newly allocated memory to hold a Big_Int variable containing the value in value
 */
Big_Int* init_Big_Int_from_char(char *value);

/*! \fn Big_Int* init_Big_Int_from_long(long long value)
 *  \brief allocates memory for a new Big_Int, initializes it to the value in value and returns a pointer
 *  to allocated memory. <br/>
 *  <b> Precondition: </b> the pointer capturing the new memory should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> the pointer is initialized and allocated memory <br/>
 *  \param value the value that will be copied into the new big_integer
 *  \return a pointer to the newly allocated memory to hold a Big_Int variable containing the value in value
 */
Big_Int* init_Big_Int_from_long(long long value);

/*! \fn Big_Int* init_Big_Int_from_int(int value)
 *  \brief allocates memory for a new Big_Int, initializes it to the value in value and returns a pointer
 *  to allocated memory. <br/>
 *  <b> Precondition: </b> the pointer capturing the new memory should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> the pointer is initialized and allocated memory <br/>
 *  \param value the value that will be copied into the new big_integer
 *  \return a pointer to the newly allocated memory to hold a Big_Int variable containing the value in value
 */
Big_Int* init_Big_Int_from_int(int value);

/*! \fn Big_Int* add_Big_Ints(Big_Int *operand1,Big_Int *operand2,Big_Int *result)
 *  \brief adds two positive integers only<br/>
 *  <b> Postcondition: </b>the Big_Int object containing the sum is returned
 *  \param operand1 the first Big_Int operand for addition
 *  \param operand2 the second Big_Int operand for addition
 *  \param result the Big_Int structure in which the result should be stored, its ok if it was previously initialized or not
 *  \return a pointer to the Big_Int holding the sum
 */
Big_Int* add_Big_Ints(Big_Int *operand1,Big_Int *operand2,Big_Int *result);

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
int compare_Big_Ints(Big_Int *operand1,Big_Int *operand2);

/*! \fn void destroy_Big_Int(Big_Int *obj)
 *  \brief frees the allocated memory <br/>
 *  <b> Precondition: </b> the Big_Int pointer which it is being freed should not have been freed already <br/>
 *  <b> Postcondition: </b>The big_integer structure is freed
 *  \param operand1 the pointer to the structure which should be freed
 *  \return Nothing
 */ 
void destroy_Big_int(Big_Int *obj);

#endif