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
		p[i] = (Product*)malloc(sizeof(Product));
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
		printf("%2d\t ", i+1);
		readProduct(*p[i]);
	}
}

void readProduct(Product p) {
	printf("%s\t%d\t%d\t%d\t%d\n", p.name, p.grams, p.price, p.rating, p.rating_no);
}

void updateProduct(Product *p) {
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
	
	printf("\nUpdated!\n");
}

void searchName(Product *p[], int count) {
	char search[64];
	int scnt = 0;

	printf("Enter name to find: ");
	scanf("%s", search);
	getchar();

	printf("NO\tName\tGrams\tPrice\tRating\tRating No.\n");
	printf("==================================================\n");
	for(int i = 0; i < count; i++) {
		if(p[i]->name == NULL) continue;
		if(strstr(p[i]->name, search)) {
			printf("%2d\t", i+1);
			readProduct(*p[i]);
			scnt++;
		}
	}
	
	if(scnt == 0) printf("=> No matching data found!\n");
}

void searchRating(Product *p[], int count) {
	int search, highlow;
	int scnt = 0;
	
	printf("Enter rating to find: ");
	scanf("%d", &search);

	printf("Choose mode (0 : Higher, 1 : Lower, 2 : Same): ");
	scanf("%d", &highlow);

	printf("NO\tName\tGrams\tPrice\tRating\tRating No.\n");
	printf("==================================================\n");
	for(int i = 0; i < count; i++) {
		if(p[i]->name == NULL) continue;
		
		if(highlow == 0) {
			if(search < p[i]->rating) {
				printf("%2d\t", i+1);
				readProduct(*p[i]);
				scnt++;
			}
		} else if(highlow == 1) {
			if(search > p[i]->rating) {
				printf("%2d\t", i+1);
				readProduct(*p[i]);
				scnt++;
			}
		} else if(highlow == 2) {
			if(search ==  p[i]->rating) {
				printf("%2d\t", i+1);
				readProduct(*p[i]);
				scnt++;
			}
		}
	}
	
	if(scnt == 0) printf("=> No matching data found!\n");
}

void searchPrice(Product *p[], int count) {
	int search, highlow;
	int scnt = 0;

	printf("Enter price to find: ");
	scanf("%d", &search);

	printf("Choose mode (0 : Higher, 1 : Lower, 2 : Same): ");
	scanf("%d", &highlow);

	printf("NO\tName\tGrams\tPrice\tRating\tRating No.\n");
	printf("==================================================\n");
	for(int i = 0; i < count; i++) {
		if(p[i]->name == NULL) continue;
		
		if(highlow == 0) {

			if(search < p[i]->price) {
				printf("%2d\t", i+1);
				readProduct(*p[i]);
				scnt++;
			}
		} else if(highlow == 1) {

			if(search > p[i]->price) {
				printf("%2d\t", i+1);
				readProduct(*p[i]);
				scnt++;
			}
		} else if(highlow == 2) {

			if(search ==  p[i]->price) {
				printf("%2d\t", i+1);
				readProduct(*p[i]);
				scnt++;
			}
		}
	}
	
	if(scnt == 0) printf("=> No matching data found!\n");
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
	}	
		fclose(fp);
		printf("=> Saved!\n");
}

int selectMenu() {
	int menu;
	printf("\n1. Add\n");
	printf("2. Read\n");
	printf("3. Update\n");
	printf("4. Find by name\n");
	printf("5. Find by rating\n");
	printf("6. Find by price\n");
	printf("7. Delete\n");
	printf("8. Save to file\n");
	printf("0. End Program\n");
	printf("\nExecute which menu? => ");
	scanf("%d", &menu);
	printf("\n");
	return menu;
}

