#ifndef SIMPLE_PREFIX_H
#define SIMPLE_PREFIX_H

#include "simple_prefix_impl.h"

typedef struct simple_prefix 
{
	FILE* (*encode_file)(char*,char*); 
	FILE* (*decode_file)(char*,char*); 
}simple_prefix;

simple_prefix* init();

#endif