#include "product.h"

int loadData(Product *p[]) {
	int i = 0;
	FILE *fp;

	fp = fopen("product.txt", "rt");

	if(fp == NULL) {
		printf("=> No file detected.\n");
		return i;
	}

	for(; i < 100; i++) {
		fscanf(fp,"%s", p[i]->name);
		if(feof(fp)) break;
		fscanf(fp, "%d", &p[i]->grams);
		fscanf(fp, "%d", &p[i]->price);
		fscanf(fp, "%d", &p[i]->rating);
		fscanf(fp, "%d", &p[i]->rating_no);
	}
	fclose(fp);
	printf("=> Successfully loaded!\n");
	return i;
}

int addProduct(Product *p) {
	getchar();
	printf("Name? ");

	fgets(p->name, 64, stdin);

	p->name[strlen(p->name)-1] = '\0';

	printf("Grams? ");
	scanf("%d", &p->grams);
	printf("Price? ");
	scanf("%d", &p->price);
	
	while(1) {
		printf("Rating? ");
		scanf("%d", &p->rating);
		if(p->rating < 1 || p->rating > 5) {
			printf("Please Enter a number between 1 and 5.\n");
		} else {
			break;
		}
	}
	
	printf("Rating No? ");
	scanf("%d", &p->rating_no);
	
	printf("\nAdded!\n");

	return 1;	
}

void listProduct(Product *p[], int count) {
	int i = 0;
	
	printf("NO\tName\tGrams\tPrice\tRating\tRating No.\n");
	printf("==================================================\n");
	for(i = 0; i < count; i++) {
		if(p[i] == NULL) continue;
		printf("%d\t", i+1);
		readProduct(*p[i]);
	}
}

void readProduct(Product p) {
	printf("%s\t%d\t%d\t%d\t%d\n", p.name, p.grams, p.price, p.rating, p.rating_no);
}

void updateProduct(Product *p) {
	getchar();
	printf("Name? "); 
	fgets(p->name,
 64, stdin);

	p->name[strlen(p->name)-1] = '\0';

	printf("Grams? ");
	scanf("%d", &p->grams);
	printf("Price? ");
	scanf("%d", &p->price);
	
	while(1) {
		printf("Rating? ");
		scanf("%d", &p->rating);
		if(p->rating < 1 || p->rating > 5) {
			printf("Please Enter a number between 1 and 5.\n");
		} else {
			break;
		}
	}
	
	printf("Rating No? ");
	scanf("%d", &p->rating_no);
	
	printf("\nUpdated!\n");
}

int deleteProduct(Product *p[], int n) {
	free(p[n-1]);
	p[n-1] = NULL;
	printf("\nDeleted!\n");

	return 1;
}

void saveData(Product *p[], int count) {
	FILE *fp;
	fp = fopen("product.txt", "wt");

	for(int i = 0; i < count; i++) {
		if(p[i]->name == NULL) continue;
		fprintf(fp, "%s %d %d %d %d\n", p[i]->name, p[i]->grams, p[i]->price, p[i]->rating, p[i]->rating_no);
		
		fclose(fp);
		printf("=> Saved!\n");
	}
}

int selectMenu() {
	int menu;
	printf("\n1. Add\n");
	printf("2. Read\n");
	printf("3. Update\n");
	printf("4. Delete\n");
	printf("5. Save to file\n");
	printf("0. End Program\n");
	printf("원하는 메뉴는? => ");
	scanf("%d", &menu);
	printf("\n");
	return menu;
}


