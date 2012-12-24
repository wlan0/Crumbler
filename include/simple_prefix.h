/*! \file simple_prefix.h
 *  \brief serves as the interface to simple_prefix
 *  This file contains functions required to support encoding and de-coding on files.<br/> 
 *  Author : Sidhartha Mani<br/>
 *  Contact : sidharthamn@gmail.com <br/>
 *  Last Updated : 23 Dec 2012 <br/>
 *  \ingroup core 
 */

#ifndef SIMPLE_PREFIX_H
#define SIMPLE_PREFIX_H

#include "simple_prefix_impl.h"

/*! \struct simple_prefix
 *  \brief the interface to the simple prefix functions
 */
typedef struct simple_prefix 
{
	/*! A function that allows file encode according to simple prefix algorithm, it points to FILE* x_encode_file(char *input_file_name,char *output_file_name)*/
	FILE* (*encode_file)(char*,char*); 
	/*! A function that allows file decode according to simple prefix algorithm, it points to FILE* x_decode_file(char *input_file_name,char *output_file_name)*/
	FILE* (*decode_file)(char*,char*); 
}simple_prefix;

/*! \fn simple_prefix* init()
 *  \brief it allocates memory for the simple_prefix structure and initializes the functors<br/>
 *  <b>Precondition:</b> The structure receiving the allocated memory shouold not have already been allocated memory <br/>
 *  <b>Postcondition:</b>Memory is allocated and functors are initialized and a pointer to the allocated memory is returned
 *  to the calling environment <br/>
 *  \return returns a pointer to freshly allocated memory
 */
simple_prefix* init();

#endif