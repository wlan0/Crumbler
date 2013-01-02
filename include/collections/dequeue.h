/*! \file dequeue.h
 *  \brief This file serves as the interface to dequeue functionality. <br/>
 *  It contains the interface to the various functions associated with the queue.<br/>
 *  Author : Sidhartha Mani<br/>
 *  Contact : sidharthamn@gmail.com <br/>
 *  Last Updated : 2 Jan 2013<br/>
 *  \ingroup core
 */
#ifndef DEQUEUE_H
#define DEQUEUE_H

#include "dequeue_impl.h"

/*! \struct dequeue
 *  \brief the interface to the double ended queue
 */
typedef struct Dequeue 
{
	/*! */
	int size_of_data;
	/*! a pointer to the underlying queue implementation*/
	struct dq *queue;
	/*! a functor for enqueing data into the queue*/
	void (*enqueue)(struct Dequeue *this, void *data);
	/*! a functor to dequeue data from the queue*/
	void* (*dequeue)(struct Dequeue *this);
}dequeue;

/*! \fn struct dequeue* init_dequeue(int size_of_data);
 *  \brief allocate memory to the a new dequeue<br/>
 *  <b> Precondition : The queue structure to which the memory is being allocated should not have been already allocated memory.</b> <br/>
 *  <b> Postcondition : The required memory to represent a dequeue is allocated</b> <br/>
 *  \param size_of_data The size of the data type which the queue will hold
 *  \return a pointer to the allocated memory
 */
struct Dequeue* init_dequeue(int size_of_data);

/*! \fn void destroy_dequeue(struct Dequeue *queue)
 *  \brief deletes the data stored in the dequeue and the dequeue itself <br/>
 *  <b> Precondition : The queue should have been initialized by a call to init_dq, it should not have been already de-allocated</b> <br/>
 *  <b> Postcondition : The queue's memory is completely de-allocated</b> <br/>
 *  \param queue The queue which is being de-allocated
 *  \return Nothing
 */
void destroy_dequeue(struct Dequeue *queue);

#endif