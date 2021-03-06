/*!
 * \file simple_prefix.c
 * \brief The interface to simple_prefix implementation
 * This file contains functions required to interface with other functions for encoding and decoding files<br/> 
 * Author : Sidhartha Mani<br/>
 * Contact : sidharthamn@gmail.com <br/>
 * Last Updated : 24 Dec 2012 <br/>
 * \ingroup core 
 */

#include "simple_prefix.h"

/*! \fn FILE* x_encode_file(char *input_file_name,char *output_file_name)
 *  \brief take in a file for encoding, encode it and then return the file descriptor of the file containing the encoded 
 *  data <br/>
 *  <b>Precondition:</b> The input file should only have characters defined in the macro LOWER_CASE_ALPHABETS <br/>
 *  <b>Postcondition:</b>The output file containing the binary data(each bit stored into one character - just for now) 
 *  representing the simple_prefix encoded data will be returned to the calling environment <br/>
 *  \param input_file_name The relative path from the executable directory/the absolute path of the file to be encoded 
 *  \param output_file_name The relative path from the executable directory/the absolute path of the file in which the
 *  encoded value will be persisted
 *  \return The file descriptor of the encoded file(output file)
 */
FILE* x_encode_file(char *input_file_name,char *output_file_name)
{
	FILE* input_file;
	input_file = fopen(input_file_name,"r");
	FILE *output_file;
	char *input_string = (char *)malloc(1000);
	char *output_string;
	output_file = fopen(output_file_name,"w");
	while(fread(input_string,sizeof(char),1000,input_file) != 0) 
	{
		output_string = simple_prefix_encode(input_string,strlen(input_string));
		fwrite(output_string,sizeof(char),strlen(output_string),output_file);
	}
	return output_file;
}

/*! \fn FILE* x_decode_file(char *input_file_name,char *output_file_name)
 *  \brief take in an encoded file for decoding, decode it and then return the file descriptor of the file containing the 
 *  decoded data <br/>
 *  <b>Precondition:</b> The input file should only have characters(one bit in one character) that are encoded values 
 *  generated by this simle_prefix algorithm. Any other data and the result will be undefined <br/>
 *  <b>Postcondition:</b>The output file containing the decoded data will be returned <br/>
 *  \param input_file_name The relative path from the executable directory/the absolute path of the file to be decoded 
 *  \param output_file_name The relative path from the executable directory/the absolute path of the file in which the
 *  decoded value will be persisted
 *  \return The file descriptor of the decoded file(output file)
 */
FILE* x_decode_file(char *input_file_name,char *output_file_name)
{
	FILE* input_file = fopen(input_file_name,"r");
	FILE *output_file;
	char *input_string = (char *)malloc(1000);
	char *output_string;
	char *input_msgs = LOWER_CASE_ALPHABETS;
	struct node *root = init_simple_prefix();
	root = construct_simple_prefix_tree(root,input_msgs,(int)(strlen(input_msgs)));
	output_file = fopen(output_file_name,"w");
	while(fread(input_string,sizeof(char),1000,input_file) != 0) 
	{
		output_string = simple_prefix_decode(input_string,root,(int)(strlen(input_string)));
		fwrite(output_string,sizeof(char),strlen(output_string),output_file);
	}
	
	return output_file;
}

/*! \fn simple_prefix* init()
 *  \brief it allocates memory for the simple_prefix structure and initializes the functors<br/>
 *  <b>Precondition:</b> The structure receiving the allocated memory shouold not have already been allocated memory <br/>
 *  <b>Postcondition:</b>Memory is allocated and functors are initialized and a pointer to the allocated memory is returned
 *  to the calling environment <br/>
 *  \return returns a pointer to freshly allocated memory
 */
simple_prefix* init()
{
	struct simple_prefix *x_simple_prefix = (struct simple_prefix*)malloc(sizeof(simple_prefix));
	x_simple_prefix->encode_file = x_encode_file;
	x_simple_prefix->decode_file = x_decode_file;
	return x_simple_prefix;
}