#include "manager.h"

int main() {
	int menu;
	Product *fruit[100];
	int count = 0, index = 0;
	int isdel, num;

	count = loadData(fruit);
	index = count;

	while(1) {
		menu = selectMenu();
		if(menu == 0) break;
		
		if(menu == 2 || menu == 3 || menu == 4) {
			if(count == 0) {
			       	printf("No data available.\n");
				continue;
			}
		}
				
		if(menu == 1) {
			fruit[index] = (Product *)malloc(sizeof(Product));
			count += addProduct(fruit[index++]);
		} else if(menu == 2) {
			listProduct(fruit, index);
		} else if(menu == 3)  {

			num = selectDataNo(fruit, index);
			if(num != 0) {
				updateProduct(fruit[num-1]);
			} else {
				printf("=> Cancelled!\n");
			}

		} else if(menu == 4) {
	
			num = selectDataNo(fruit, index);

			if(num != 0) {
				printf("Are you sure you want to delete saved data? (1 : Yes, 0 : No) ");
				scanf("%d", &isdel);
				if(isdel) {
					count -= deleteProduct(fruit, num);
				} else {
					printf("=> Cancelled!\n");
				}
			}
		} else if(menu == 5) {
			saveData(fruit, index);
		}
	}
	
	printf("Program Closed.\n");
	return 0;
}

