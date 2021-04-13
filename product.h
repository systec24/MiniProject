//product.h 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[64]; //이름
    int grams; //무게
    int price; //가격
    int rating; //평점 (1~5 사이)
    int rating_no; //달린 평점의 갯수
} Product; //제품 정보를 저장하는 구조체

int loadData(Product *p[]); //File에서 데이터를 불러오는 함수

int addProduct(Product *p); //제품을 추가하는 함수

void readProduct(Product p); //저장된 제품을 출력하는 함수

void listProduct(Product *p[], int count); //현재 저장된 모든 제품을 출력하는 함수

void searchName(Product *p[], int count); //이름을 이용해 저장된 제품을 찾는 함수

void searchRating(Product *p[], int count); //평점을 이용해 저장된 제품을 찾는 함수

void searchPrice(Product *p[], int count); //가격을 이용해 저장된 제품을 찾는 함수

void updateProduct(Product *p); //저장된 제품 목록에서 선택된 제품의 정보를 업데이트/수정 하는 함수

int deleteProduct(Product *p[], int n); //저장된 제품 목록에서 선택된 제품의 정보를 삭제하는 함수

void saveData(Product *p[], int count); //File에 현재 데이터를 저장하는 함수

int selectMenu(); //사용자가 이용할 수 있는 기능 목록을 출력 및 선택된 기능을 리턴하는 함수
