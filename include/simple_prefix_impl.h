#ifndef SIMPLE_PREFIX_IMPL_H
#define SIMPLE_PREFIX_IMPL_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//TBD
/*
 1. Ensure all allocated memory is de-allocated - use refernece counting pointers - need to define memory.h for project simple_prefix
 2. Create structure for bitstream, so that just enough bits are decoded and not more
 3. Extend coding for all printable symbols
 4. Do actual simple_prefix coding, with a balanced simple_prefix tree and not just prefix coding
 5. Make sure tree construction probabilities for "ACTUAL" simple_prefix coding is modifiable
 */

//writing simple_prefix codes only for lower case alphabets now, will write for the rest later
//sorted based on letters occuring with highest frequency in words from the oxford dictionary - http://oxforddictionaries.com/words/what-is-the-frequency-of-the-letters-of-the-alphabet-in-english
#define LOWER_CASE_ALPHABETS "eariotnslcudpmhgbfywkvxzjq " // NOTE : White Space is also included
#define UPPER_CASE_ALPHABETS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define WHITE_SPACE " "
#define NEW_LINE "\n"
#define PERIOD "."
#define COMMA ","
//need to define for all printable characters


//a node of a simple_prefix tree
typedef struct node
{
	char msg;
    int is_leaf;
    struct node *left_node;
    struct node *right_node;
}node;

node* init_simple_prefix();

node* construct_simple_prefix_tree(struct node *root, char *input_msgs,int size_of_input_msgs);

char* simple_prefix_encode(char *msg, int size_of_msg);

char* simple_prefix_decode(char *encoded_string, struct node *root, int size_of_encoded_string);

char* char2bits(char* encoded_string, int size_of_encoded_string);

char* bits2char(char* bit_stream, int size_of_bit_stream);


#endif