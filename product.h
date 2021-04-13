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

int loadData(Product *p);

int addProduct(Product *p); 

void readProduct(Product p);

void listProduct(Product *p[], int count);

void searchName(Product *p[], int count);

void searchRating(Product *p[], int count);

void searchPrice(Product *p[], int count); //가격을 이용해 저장된 제품을 찾는 함수 (사용자가 입력한 가격보다 낮은 상품)

void updateProduct(Product *p); //저장된 제품 목록에서 선택된 제품의 정보를 업데이트/수정 하는 함수

int deleteProduct(Product *p[], int n); //저장된 제품 목록에서 선택된 제품의 정보를 삭제하는 함수

void saveData(Product *p, int count); //File에 현재 데이터를 저장하는 함수

int selectMenu(); //사용자가 이용할 수 있는 기능 목록을 출력 및 선택된 기능을 리턴하는 함수
