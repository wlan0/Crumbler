#include "big_integer_impl.h"

int main()
{
    char integer1[50];
    char integer2[50];
    printf("Enter x\n");
    scanf("%s",integer1);
    printf("Enter y\n");
    scanf("%s",integer2);
    struct big_integer *x = init_big_integer_from_char(integer1);
    struct big_integer *y = init_big_integer_from_char(integer2);
    int compare = compare_big_integers(x,y);
    char comparison_message[50];
    if(compare == 0)
        sprintf(comparison_message,"the integers are equal");
    else if(compare > 0)
        sprintf(comparison_message,"x is greater");
    else
        sprintf(comparison_message,"y is greater");
    printf("%s\n",comparison_message);
}