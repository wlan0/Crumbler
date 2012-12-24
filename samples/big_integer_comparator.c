/*! \file big_integer_comparator.c
 *  \brief A sample implementation of big_integer comparison using crumbler library <br/>
 *  Author : Sidhartha Mani <br/>
 *  Contact : sidharthamn@gmail.com <br/>
 *  Last updated on : 24 Dec 2012
 *  \ingroup samples
 */

#include "big_integer.h"

int main()
{
    char integer1[2250];
    char integer2[2250];
    printf("Enter x\n");
    scanf("%s",integer1);
    printf("Enter y\n");
    scanf("%s",integer2);
    struct Big_Int *x= init_Big_Int_from_char(integer1);
    struct Big_Int *y = init_Big_Int_from_char(integer2);
    int compare = compare_Big_Ints(x,y);
    char comparison_message[50];
    if(compare == 0)
        sprintf(comparison_message,"the integers are equal");
    else if(compare > 0)
        sprintf(comparison_message,"x is greater");
    else
        sprintf(comparison_message,"y is greater");    
	x = add_Big_Ints(x,y,x);
	printf("%s\nSUM: %s\n",comparison_message,x->get_integer(x));
	destroy_Big_Int(x);
	destroy_Big_Int(y);
	return 0;
}