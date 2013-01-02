/*! \file double_edged_node.h
 *  \brief serves as reusable code for dequeues and binary trees
 *  This file contains the definition of the double edged node, which will contain data,
 *  as well as links to a left and a right node.<br/>
 *  Author : Sidhartha Mani<br/>
 *  Contact : sidharthamn@gmail.com <br/> 
 *  Last Updated : 27 Dec 2012<br/>
 *  \ingroup core
 */
#ifndef DOUBLE_EDGED_NODE_H
#define DOUBLE_EDGED_NODE_H

/*! \struct double_edged_node
 *  \brief a common reusable node containing two edges and data
 */
typedef struct double_edged_node {
	/*! A pointer to the data contained in the node*/
	void *data;
	/*! A pointer to the starting element of the left chain*/
	void *left_node;
	/*! A pointer to the startng element of the right chain*/
	void *right_node;
}double_edged_node;

#endif
