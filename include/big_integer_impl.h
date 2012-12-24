/*!
 * \file big_integer_impl.h
 * \brief The interface to the implementation of big_integer logic
 * This file contains functions required to support the big integer manipulation functions.<br/> 
 * Author : Sidhartha Mani<br/>
 * Contact : sidharthamn@gmail.com <br/>
 * Last Updated : 24 Dec 2012 <br/>
 * \ingroup core 
 */

#ifndef BIG_INTEGER_IMPL_H
#define BIG_INTEGER_IMPL_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*! \struct big_integer
 *  \brief a struct to hold big integer values
 */
typedef struct big_integer
{
	/*! the string containing the big_integer */
    char *value;
	/*! the sign of the integer */
    int sign;
}big_integer;

/*! \fn big_integer* init_big_integer()
 *  \brief allocates memory for a new big_integer structure and returns a pointer to the allocated memory <br/>
 *  <b> Precondition: </b> the variable capturing the returned value should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> memory is allocated and returned to the calling environment
 *  \return a pointer to the allocated memory
 */
big_integer* init_big_integer();

/*! \fn big_integer* init_big_integer_from_long(long long long_long_value)
 *  \brief allocates memory for a new big_integer structure and returns a pointer to the allocated memory and initializes
 *  it to the value in long_long_value<br/>
 *  <b> Precondition: </b> the variable capturing the returned value should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> memory is allocated and initialized before returning to the calling environment
 *  \param long_long_value the long long value, that will be converted into big integer representation
 *  \return a pointer to the allocated and initialized memory
 */
big_integer* init_big_integer_from_int(int int_value);

/*! \fn big_integer* init_big_integer_from_int(int int_value)
 *  \brief allocates memory for a new big_integer structure and returns a pointer to the allocated memory and initializes
 *  it to the value in int_value<br/>
 *  <b> Precondition: </b> the variable capturing the returned value should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> memory is allocated and initialized before returning to the calling environment
 *  \param int_value the long int value, that will be converted into big integer representation
 *  \return a pointer to the allocated and initialized memory
 */
big_integer* init_big_integer_from_long(long long long_long_value);

/*! \fn big_integer* init_big_integer_from_char(char *value)
 *  \brief allocates memory for a new big_integer structure and returns a pointer to the allocated memory and initializes
 *  it to the value in value<br/>
 *  <b> Precondition: </b> the variable capturing the returned value should not have already been allocated memory <br/>
 *  <b> Postcondition: </b> memory is allocated and initialized before returning to the calling environment
 *  \param value the value, that will be converted into big integer representation
 *  \return a pointer to the allocated and initialized memory
 */
big_integer* init_big_integer_from_char(char *char_value);

/*! \fn int compare_big_integers(struct big_integer *operand1, struct big_integer *operand2)
 *  \brief compares two positive integers only <br/>
 *  <b> Precondition: </b> the numbers being compared should both be positive <br/>
 *  <b> Postcondition: </b>The comparison result is returned
 *  \param operand1 the operand against which the other operand will be compared
 *  \param operand2 the operand which will be compared against operand1
 *  \return <br/>
 *  Returns   0 : if both numbers are equal <br/>
 *  Returns > 0 : if first value is larger <br/>
 *  Returns < 0 : if first value is smaller
 */ 
int compare_big_integers(struct big_integer *operand1, struct big_integer *operand2);

/*! \fn big_integer* add_big_integers(struct big_integer *operand1, struct big_integer *operand2,struct big_integer *result)
 *  \brief adds two positive integers only<br/>
 *  <b> Postcondition: </b>the big_integer object containing the sum is returned
 *  \param operand1 the first big_integer operand for addition
 *  \param operand2 the second big_integer operand for addition
 *  \param result the big_integer structure in which the result should be stored, its ok if it was previously initialized or not
 *  \return a pointer to the big_integer holding the sum
 */
big_integer* add_big_integers(struct big_integer *operand1, struct big_integer *operand2, struct big_integer *result);

/*! \fn void destroy_big_integer(big_integer *obj)
 *  \brief frees the allocated memory <br/>
 *  <b> Precondition: </b> the big_integer pointer which is being freed should not have been freed already <br/>
 *  <b> Postcondition: </b>The big_integer structure is freed
 *  \param operand1 the pointer to the structure which should be freed
 *  \return Nothing
 */ 
void destroy_big_integer(big_integer *obj);

#endif