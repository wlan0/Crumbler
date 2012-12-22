#include "simple_prefix.h"


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

simple_prefix* init()
{
	struct simple_prefix *x_simple_prefix = (struct simple_prefix*)malloc(sizeof(simple_prefix));
	x_simple_prefix->encode_file = x_encode_file;
	x_simple_prefix->decode_file = x_decode_file;
	return x_simple_prefix;
}