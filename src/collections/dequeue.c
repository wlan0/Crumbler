/*! \file dequeue.c
 *  \brief This file serves as the interface to dequeue functionality. <br/>
 *  It contains the interface to the various functions associated with the queue.<br/>
 *  Author : Sidhartha Mani<br/>
 *  Contact : sidharthamn@gmail.com <br/> 
 *  Last Updated : 2 Jan 2013<br/>
 *  \ingroup core
 */
#include "dequeue.h"

/*! \fn void x_enqueue(struct Dequeue *queue, void *data)
 *  \brief enqueues data into the queue <br/>
 *  <b> Precondition : The queue should have been initialized</b> <br/>
 *  <b> Postcondition : The data is added into the queue</b> <br/>
 *  \param queue The queue to which data is being added
 *  \param data The data which is being added to the queue
 *  \return Nothing
 */
void x_enqueue(struct Dequeue *queue, void *data)
{
	q_enqueue(queue->queue,data,queue->size_of_data);
}

/*! \fn void* x_dequeue(struct Dequeue *queue)
 *  \brief deletes the oldest element from queue and returns it<br/>
 *  <b> Precondition : The queue should have been initialized</b> <br/>
 *  <b> Postcondition : The last element is returned. If no element was present, then NULL is returned</b> <br/>
 *  \param queue The queue which is being dequeued
 *  \return a pointer to the data. IMPORTANT - The programmer is responsible for typecasting the data to the appropriate type before using it.
 */
void* x_dequeue(struct Dequeue *queue)
{
	void *ptr;
	ptr = q_dequeue(queue->queue,ptr,queue->size_of_data);
	return ptr;
}

/*! \fn struct Dequeue* init_dequeue(int size_of_data)
 *  \brief allocate memory to the a new dequeue<br/>
 *  <b> Precondition : The queue structure to which the memory is being allocated should not have been already allocated memory.</b> <br/>
 *  <b> Postcondition : The required memory to represent a dequeue is allocated</b> <br/>
 *  \param size_of_data The size of the data type which the queue will hold
 *  \return a pointer to the allocated memory
 */
struct Dequeue* init_dequeue(int size_of_data)
{
	struct Dequeue *queue = (struct Dequeue *)malloc(sizeof(struct Dequeue));
	queue->queue = init_dq();
	queue->enqueue = x_enqueue;
	queue->dequeue = x_dequeue;
	queue->size_of_data = size_of_data;
	return queue;
}

/*! \fn void destroy_dequeue(struct Dequeue *queue)
 *  \brief deletes the data stored in the dequeue and the dequeue itself <br/>
 *  <b> Precondition : The queue should have been initialized by a call to init_dq, it should not have been already de-allocated</b> <br/>
 *  <b> Postcondition : The queue's memory is completely de-allocated</b> <br/>
 *  \param queue The queue which is being de-allocated
 *  \return Nothing
 */
void destroy_dequeue(struct Dequeue *queue)
{
	destroy_dq(queue->queue);
	free(queue);
}