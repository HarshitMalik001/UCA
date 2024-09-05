#include <stdio.h>


int main()
{
	char *str = "hello";
	//str[1] = 'e'; segmentation fault
	
	char str1[10] = "hello";
	str1[1] = 'w';
	return 0;
}
