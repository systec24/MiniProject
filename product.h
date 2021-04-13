#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[64]; 
    int grams; 
    int price;
    int rating; 
    int rating_no; 
} Product; 

int loadData(Product *p[]);

int addProduct(Product *p); 

void readProduct(Product p);

void listProduct(Product *p[], int count);

void searchName(Product *p[], int count);

void searchRating(Product *p[], int count);

void searchPrice(Product *p[], int count);

void updateProduct(Product *p);

int deleteProduct(Product *p[], int n);

void saveData(Product *p[], int count);

int selectMenu();
