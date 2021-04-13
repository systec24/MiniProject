//manager.c
#include "manager.h"

int selectDataNo(Product *p[], int count) {
	int num;
	listProduct(p, count);
	printf("Which number (Cancel : 0)? ");
	scanf("%d", &num);
	return num;
}
