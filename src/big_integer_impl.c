#include "big_integer_impl.h"

char* reverse_string(char* string)
{
	char reversed_string[(int)strlen(string)];
	int i = 0;
	int j = (int)strlen(string);
	while (j--) {
		reversed_string[j] = string[i++];
	}
	memcpy(string,reversed_string,strlen(string));
	return string;
}

char* long_long_to_char(long long long_long_value)
{
    char *temp = (char *)malloc(15);
    int i = 0;
    while(long_long_value)
    {
        temp[i++] = '0' + (long_long_value%10);
        long_long_value /= 10;
    }
    temp[i] = '\0';
    temp = reverse_string(temp);
	return temp;
}

big_integer* init_big_integer()
{
    struct big_integer *temp = (struct big_integer*)malloc(sizeof(struct big_integer*));
    return temp;
}

big_integer* init_big_integer_from_long(long long long_long_value)
{
    struct big_integer *temp = init_big_integer();
    temp->value = long_long_to_char(long_long_value);
    temp->sign = ((long_long_value<0)?-1:1);
    return temp;
}

big_integer* init_big_integer_from_int(int int_value)
{
	return init_big_integer_from_long((long long)int_value);
}

big_integer* init_big_integer_from_char(char *value)
{
	int i = strlen(value);
	//check for non-numbers
	while (i--) {
		if(!((value[i] <= '9' && value[i] >= '0') || (i==0 && value[i] == '-')))
			return NULL;
	}
	//check for preceeding 0's
	i++;
	while (i<strlen(value) && value[i++] == '0');
	i--;
	char *new_value;
	if(i != strlen(value))
	{
		new_value = value + i;
	}	
	else 
	{
		new_value = (char *)malloc(1);
		new_value = "0";
	}
	struct big_integer *temp = init_big_integer();
	((value[0] == '-')?(temp->value=new_value+1,temp->sign = -1):(temp->value = new_value,temp->sign = 1));
	return temp;
}

int compare_big_integers(struct big_integer *operand1, struct big_integer *operand2)
{
	if(strlen(operand1->value) != strlen(operand2->value))
	{
		return (strlen(operand1->value)>strlen(operand2->value)?1:-1);
	}
	return strcmp(operand1->value,operand2->value);
}
	
/*
int main()
{
    struct big_integer *test1 = init_big_integer_from_long(1539843948);
    struct big_integer *test2 = init_big_integer_from_long(344546455);
	struct big_integer *test3 = init_big_integer_from_char("34454645776756757565576776767676765");
	struct big_integer *test4 = init_big_integer_from_char("000000000000");
	printf("%s\n",test4->value);
	return 0;
}
*/