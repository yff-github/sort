#include<stdio.h>
#include"aaa.h"
#include<stdlib.h>
//github

int* p = (int*)malloc(sizeof(int) * 10);
int main()
{
	int a[MAX];
	for (int i = 0; i < 100; i++)
		a[i] = rand() % 50;
	print1(a);
	kuaisu(a);
	print1(a);

	return 0;
}