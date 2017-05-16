#include "stdio.h"
#include <stdlib.h>
#include "LinkList.h"


int main() {
	int userInput = 1;
	listNode* tree = constructor();
	while(userInput){

		printf("Menu:\n");
		printf("1. add an employ.\n");
		printf("2. Print the tree\n");
		printf("3. Find an employ by name\n");
		printf("4. Delete an employ\n");
		printf("5. add under\n");
		printf("6. Move Employ\n");
		printf("7. Remove Employ\n");
		printf("please enter your choice or 0 to exit \n");
		scanf("%d", &userInput);
		char* empName = (char*)malloc(sizeof(char) * 15);
		char* mangerName = (char*)malloc(sizeof(char) * 15);
		switch (userInput){
		case  0:
			printf("Bye Bye!");
			break;
		case 1:
			printf("Enter a Name:");
			scanf("%s", empName);
			listNode* new_employ = createNode(empName);
			add(tree, new_employ);
			break;
		case 2:
		{
			printTree(tree -> next,0);
		}
		break;
		case 5:
			printf("Enter an employ Name:");
			scanf("%s", empName);
			printf("Enter manger Name:");
			scanf("%s", mangerName);
			addUnder(find_emp(tree,mangerName),createNode(empName));
			break;
		case 6:
			printf("Enter an employ Name:");
			scanf("%s", empName);
			printf("Enter new manger Name:");
			scanf("%s", mangerName);
			moveEmploy(tree, empName, mangerName);
			break;
		case 7:
			printf("Enter an employ Name:");
			scanf("%s", empName);
			removeEmploy(tree, empName);
			break;
		default:
			break;
		}

	}

}
