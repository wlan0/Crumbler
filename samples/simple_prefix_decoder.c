#include "simple_prefix.h"
#include<stdio.h>

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        printf("Intructions : simple_prefix input_file output_file\n");
        exit(0);
    }
    struct simple_prefix *decoder = init();
    decoder->decode_file(argv[1],argv[2]);
    return 0;
	
    /* TO ENCODE , USE THIS AS AN EXAMPLE
	 struct simple_prefix *encoder = init();
	 encoder->encode_file("xyz","output");
	 return 0;
	 */
}