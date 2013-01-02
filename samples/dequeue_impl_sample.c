/*! \file dequeue_impl_sample.c
 *  \brief A sample implementation of enqueing and dequing using crumbler library <br/>
 *  Author : Sidhartha Mani <br/>
 *  Contact : sidharthamn@gmail.com <br/>
 *  Last updated on : 29 Dec 2012
 *  \ingroup samples
 */

#include "big_integer.h"
#include "dequeue.h"

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
	struct Dequeue *queue = init_dequeue(sizeof(Big_Int));
	queue->enqueue(queue,(void *)x);
	queue->enqueue(queue,(void *)y);
	struct Big_Int *z;
	z = (struct Big_Int *)queue->dequeue(queue);
	printf("%s\n",z->get_integer(z));
	z = (struct Big_Int *)queue->dequeue(queue);
	printf("%s\n",z->get_integer(z));
	destroy_dequeue(queue);
	destroy_Big_Int(x);
	destroy_Big_Int(y);
	//the data of z was never allocated!! It is just copying the pointer to big_integer data. Calling destroy_Big_Int, will try
	// to free de-allocated memory. Therefore error! In order to avoid this, call free....
	free(z);
    return 0;
}