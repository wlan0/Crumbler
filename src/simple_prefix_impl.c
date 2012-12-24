/*!
 * \file simple_prefix_impl.c
 * \brief The implementation of simple_prefix tree
 * This file contains functions required to support the encoding and de-coding functions.<br/> 
 * Author : Sidhartha Mani<br/>
 * Contact : sidharthamn@gmail.com <br/>
 * Last Updated : 23 Dec 2012 <br/>
 * \ingroup core 
 */

//CURRENT_TASK : USE A STANDARD PAGE SIZE AND A STRUCTURE FOR ENCODED STRING

//TBD
//EXTEND TO ALL PRINTABLE CHARACTERS
//IMPROVE ENCODING ALGORITHM
//TAKE CARE OF BITS THAT DO NOT END IN LENGTHS THAT ARE MULTIPLES OF 8

#include "simple_prefix_impl.h"

/*! \fn node* init_simple_prefix()
 *  \brief allocate memory for a new simple_prefix tree <br/>
 *  <b>Precondition:</b> The structure should not have already been allocated memory <br/>
 *  <b>Postcondition:</b> Memory is allocated and returned to the calling environment <br/>
 *  \return A pointer to the allocated memory
 */
node* init_simple_prefix()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
	root->is_leaf = 0;
	root->left_node = NULL;
 	root->right_node = NULL;
 	return root;
}


/*! \fn node* construct_simple_prefix_tree(struct node *root, char *input_msgs,int size_of_input_msgs)
 *  \brief construct a naive simple_prefix tree for a set of characters specified by input_msgs <br/>
 *  <b> Precondition: </b> Root should have already been initialized <br/>
 *  <b> Postcondition: </b> The Root is initialized to a simple prefix tree for all printable characters <br/>
 *  \param root A pointer to the root of the tree. It is essentially a pointer to the entire tree.
 *  \param input_msgs An array of characters for which the tree is being built. <br/> <b>Note :</b> The letters that occur
 *  earlier in the input_msgs array will have a lower encoded length than the letters that occur later in the 
 *  input_msgs array.
 *  \param size_of_input_msgs The length of the input_msgs array
 *  \return it returns the root of the constructed prefix tree
 */
node* construct_simple_prefix_tree(struct node *root, char *input_msgs,int size_of_input_msgs)
{
	//definition : Naive simple_prefix tree  -  a simple_prefix tree that is constructed without considering
	//the probabilites of messages. A lower length prefix code is given to a message 
	//if it occurs before another message while processing. That is, a msg whose index is lower
	//in the input_msgs array will have a shorter prefix code than a msg that has a higher array 
	//index
	int i = 0;
	struct node *temp =  root;
	for (i = 0; i<size_of_input_msgs; i++) 
	{
		while (temp->left_node != NULL) 
		{
			temp = temp->left_node;
		}
		if (temp->right_node == NULL && temp == root) 
		{
			struct node *new_node = (struct node *)malloc(sizeof(struct node));
			new_node->msg = input_msgs[i];
			temp->right_node = new_node;
			new_node->left_node = NULL;
			new_node->right_node = NULL;
			new_node->is_leaf = 1;
		}
		else if (temp->left_node == NULL && temp == root) 
		{
			struct node *new_node = (struct node *)malloc(sizeof(struct node));
			new_node->msg = input_msgs[i];
			temp->left_node = new_node;
			new_node->left_node = NULL;
			new_node->right_node = NULL;
			new_node->is_leaf = 1;
		}
		else if (temp->right_node == NULL)
		{
			struct node *new_node = (struct node *)malloc(sizeof(struct node));
			new_node->msg = temp->msg;
			temp->is_leaf = 0;
			temp->right_node = new_node;
			new_node->left_node = NULL;
			new_node->right_node = NULL;
			new_node->is_leaf = 1;
			struct node *new_node_2 = (struct node *)malloc(sizeof(struct node));
			temp->left_node = new_node_2;
			new_node_2->msg = input_msgs[i];
			new_node_2->is_leaf = 1;
			new_node_2->left_node = NULL;
			new_node_2->right_node = NULL;
		}
	}
	return root;
}


/*! \fn char* simple_prefix_encode(char *msg, int size_of_msg)
 * \brief encode a string based on the current simple_prefix tree, size_of_msgs(param 2) should be specified in bytes<br/>
 * <b>Precondition :</b> The string into which the returned value should be captured should not have already been 
 * allocated. Right now, the function can only encode characters defined in LOWER_CASE_ALPHABETS macro<br/>
 * <b>Postcondition :</b> The message is encoded according to the simple_prefix algorithm and returned to the calling environment
 * \param msg the string that needs to be encoded
 * \param size_of_msg the length of the message
 * \return a pointer to the encoded message. <br/>
 * The returned encoded message is not in binary, it is still a character array. It can be converted into binary
 * using char2bits(char *, int) function
 */
char* simple_prefix_encode(char *msg, int size_of_msg)
{
	char conversion_tree[][27] = {
		"1", //e
		"01", //a
		"001", //r
		"0001", //i
		"00001", //o
		"000001", //t
		"0000001", //n
		"00000001", //s
		"000000001", //l
		"0000000001", //c
		"00000000001", //u
		"000000000001", //d
		"0000000000001", //p
		"00000000000001", //m
		"000000000000001", //h
		"0000000000000001", //g
		"00000000000000001", //b
		"000000000000000001", //f
		"0000000000000000001", //y
		"00000000000000000001", //w
		"000000000000000000001", //k
		"0000000000000000000001", //v
		"00000000000000000000001", //x
		"000000000000000000000001", //z
		"0000000000000000000000001", //j
		"00000000000000000000000001", //q
		"00000000000000000000000000" //WHITE SPACE
	};
	char *encoded_string = (char *)malloc(27*size_of_msg);
	int i = 0;
	char reference_string[] = LOWER_CASE_ALPHABETS;
	while (i < size_of_msg) 
	{
	//ignore un-recognized characters
	if ((int)((strchr(reference_string,msg[i])) - reference_string) < 0 || (int)((strchr(reference_string,msg[i])) - reference_string) > 26) {
		i++;
		continue;
	}
	encoded_string = strcat(encoded_string,conversion_tree[(int)((strchr(reference_string,msg[i])) - reference_string)]);
	i++;
	}
	return encoded_string;
}

/*! \fn char* simple_prefix_decode(char *encoded_string, struct node *root, int size_of_encoded_string)
 *  \brief decode an encoded string by using the prefix tree generated by construct_simple_prefix(struct node*, char*, int)
 *  The parameter 2 (struct node* root) is a pointer to the generated tree.<br/>
 *  <b>Precondition :</b> The tree should have already been generated. The string capturing the return value should not
 * have already been allocated memory<br/>
 *  <b>Postcondition :</b> The encoded string is decoded and returned to the calling environment
 * \param encoded_string the encoded string as an array of characters, not as binary data
 * \param root the simple_prefix tree needed by the decoding algorithm
 * \param size_of_encoded_string the size of the encoded string
 * \return the decoded string
 */
char* simple_prefix_decode(char *encoded_string, struct node *root, int size_of_encoded_string)
{
    char *decoded_string = (char *)malloc(size_of_encoded_string);
    int i = 0;
    int j = 0;
    struct node *temp;
	while(i < size_of_encoded_string)
    {
		//iterate through each node until you reach the encoded character
        temp = root;
        while(temp->is_leaf != 1 && i < size_of_encoded_string)
        {
            if(encoded_string[i] == '0')
            {
                temp = temp->left_node;
            }
            else
            {
                temp = temp->right_node;
            }
			i++;
		}
        decoded_string[j++] = temp->msg;
    }
	//finish the string
    decoded_string[j] = '\0';
    return decoded_string;
}

/*! /fn char* char2bits(char* encoded_string, int size_of_encoded_string)
 *  \brief convert encoded character array into bits for reducing storage space. Use this on an encoded string 
 *  before persisting this in a file or wherever<br/>
 *  <b>Precondition :</b> The string capturing the return value should not
 *  have already been allocated memory<br/>
 *  <b>Postcondition :</b> The binary representation of the encoded string is returned as an array of bytes(char)
 *  \param encoded_string The string to be converted into binary
 *  \param size_of_encoded_string the size of the string in param 1
 *  \return a bit stream containing the binary information encoded in param 1(encoded_string) 
 */
char* char2bits(char* encoded_string, int size_of_encoded_string)
{
	char *bit_stream = (char *)malloc(size_of_encoded_string/8 + 2);
	char bit = 0;
	int i = 0;
	int j = 0;
	for (i=0; i<size_of_encoded_string; i++) 
	{
		bit |= (int)((int)encoded_string[i] - (int)'0');
		if ((i+1)%8 == 0) 
		{
			bit_stream[j++] = bit;
			bit = 0;
		}
		bit <<= 1;
	}
	return bit_stream;
}

/*! /fn char* bits2char(char* bit_stream, int size_of_bit_stream)
 *  \brief convert encoded bits(as binary data) into a character array for decoding. Use this whenever you read from a
 *  persisted source.simple_prefix_decode(char*, struct node*, int) undersands
 *  encoded strings in char format, not actual binary. Lots of improvement required in this function. Right now, it can
 *  only work with the constraint of encoded string length being a multiple of 8.<br/>
 *  <b>Precondition :</b> The string capturing the return value should not
 *  have already been allocated memory<br/>
 *  <b>Postcondition :</b> The character representation of the encoded binary string is returned as an array of bytes(char)
 *  \param bit_stream bit stream containing the binary encoded information
 *  \param size_of_bit_stream size of the bit_stream
 *  \return an array of bytes(char) containing each bit of param 1(bit_stream) as a character, as required by simple_prefix_decode(char*, struct node*, int)
 */
char* bits2char(char* bit_stream, int size_of_bit_stream)
{
	char *encoded_string = (char *)malloc(strlen(bit_stream)*8 + 1);
	int i = 0;
	int j = 0;
	int k = size_of_bit_stream*8 - 1;
	encoded_string[k+1] = '\0';
	char bit;
	for(i = 0;i<size_of_bit_stream;i++)
	{
		bit = bit_stream[i];
		for (j=0; j<8; j++) 
		{
			if (bit & 1) 
			{
				encoded_string[k--] = '1';
			}
			else 
			{
				encoded_string[k--] = '0';
			}
			bit >>= 1;
		}
	}
	return encoded_string;
}

/*
//Just a simple testing function
int main(int argc, char** argv)
{
	printf("simple_prefix Encoder \n Instruction : Enter a string, containing only lower case alphabets - NO WHITE SPACES, NO SYMBOLS\n Output is undefined for violation of rules\n");
	char input_msgs[] = LOWER_CASE_ALPHABETS;
	char *msg = (char *)malloc(1000);
	msg = gets(msg);
    char *arr = simple_prefix_encode(msg,(int)(strlen(msg)));
	struct node *root = init_simple_prefix();
    root = construct_simple_prefix_tree(root,input_msgs,(int)(strlen(input_msgs)));
    char *result = simple_prefix_decode(arr,root,(int)(strlen(arr)));
	printf("Input String : %s Input String size : %d bytes\nEncoded String : %s Encoded String size : %f bytes\nDecoded String : %s Decoded String size : %d bytes\n",msg,(int)(strlen(msg)),arr,(float)((float)strlen(arr)/(float)8),result,(int)(strlen(result)));
	return 0;
}*/