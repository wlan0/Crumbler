/*! \file dequeue_impl.h
 *  \brief This file serves as the interface to the implementation of dequeue logic. <br/>
 *  It contains the implementation of various functions that the queue supports.<br/>
 *  Author : Sidhartha Mani<br/>
 *  Contact : sidharthamn@gmail.com <br/>
 *  Last Updated : 28 Dec 2012<br/>
 *  \ingroup core
 */
#ifndef DEQUEUE_IMPL_H
#define DEQUEUE_IMPL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_edged_node.h"

/*! \struct dq
 *  \brief the implementation of double ended queue
 */
typedef struct dq 
{
	/*! a pointer to the head of the queue*/
	struct double_edged_node *head;
	/*! a pointer to the tail of the queue*/
	struct double_edged_node *tail;	
	/*! the length of the queue*/
	int length;
}dq;

/*! \fn struct double_edged_node* init_double_edged_node()
 *  \brief initialize a double edged node with the head and tail pointing to the same location, both unallocated<br/>
 *  <b> Precondition :</b>  The data structure collecting the allocated memory should not have already been allocated<br/>
 *  <b> Postcondition :</b> The memory is allocated<br/>
 *  \return pointer pointing to the allocated memory
 */
struct double_edged_node* init_double_edged_node();

/*! \fn struct dq* init_dq()
 *  \brief initializes a double ended queue<br/>
 *  <b> Precondition :</b>  The data structure collecting the allocated memory should not have already been allocated<br/>
 *  <b> Postcondition :</b> The memory is allocated<br/>
 *  \return pointer pointing to the allocated memory
 */
struct dq* init_dq();

/*! \fn void q_enqueue(dq* queue,void *data, int size_of_data)
 *  \brief Adds an element to the front of the queue<br/>
 *  <b> Precondition : The queue should have been initialized by a call to init_dq</b> <br/>
 *  <b> Postcondition : The element is copied to the queue Data Structure</b> <br/>
 *  \param queue The queue to which the element is being added
 *  \param data The value which is being added to the queue
 *  \param size_of_data The size of the data being added
 *  \return Nothing
 */
void q_enqueue(dq* queue,void *data, int size_of_data);


/*! \fn void destroy_double_edged_node(struct double_edged_node *node)
 *  \brief It de-allocates the memory allocated to a single node of a queue, including the data<br/>
 *  <b> Precondition : The node should have been allocated memory</b> <br/>
 *  <b> Postcondition : The node is deleted</b> <br/>
 *  \param node a pointer to the node which has to be deleted
 *  \return Nothing
 */
void destroy_double_edged_node(struct double_edged_node *node);


/*! \fn void* q_dequeue(dq* queue, void *data,int size_of_data)
 *  \brief it removes one element from the back of the queue and returns it to the calling environment<br/>
 *  Note : The programmer is responsible for deleting the memory allocated for the returned value<br/>
 *  <b> Precondition : queue should have been allocated memory, data should not have been allocated memory, size of data should be known, also type of data</b> <br/>
 *  <b> Postcondition : one element from the back of the queue is deleted and copied to the calling environment</b> <br/>
 *  \param queue The queue from which the element needs to be removed
 *  \param data A pointer to the data structure that will hold the returned value
 *  \param size_of_data The size of the expected returned value
 *  \return The data of the element at the back of the queue
 */
void* q_dequeue(dq* queue, void *data,int size_of_data);

/*! \fn void destoy_dq(struct dq *queue)
 *  \brief It de-allocates the memory of an entire queue<br/>
 *  <b> Precondition : The queue should have already been allocated some memory</b> <br/>
 *  <b> Postcondition : The memory is completely de-allocated</b> <br/>
 *  \param queue A pointer to the queue being deleted
 *  \return Nothing
 */
void destroy_dq(struct dq *queue);

#endif