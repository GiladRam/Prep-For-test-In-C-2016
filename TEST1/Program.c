#include "stdio.h"
#include <stdlib.h>
#include "EmploiesList.h"


int main() {
	int userInput = 1;
	listNode* tree = constractor();
	while(userInput){

		printf("Menu:\n");
		printf("1. add an employ.\n");
		printf("2. To print company tree.\n");
		printf("3. Move Employ.\n");
		printf("4. Print Employ Information.\n");
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
			printf("Enter a Manager Name:");
			scanf("%s", mangerName);
			addemploy(tree, empName, mangerName);
			break;
		case 2:
			printf("-------------------- COMPONY TREE -------------------------\n");
			printTree(tree,0);
			printf("-------------------- ************ -------------------------\n");
			break;
		case 3:
			printf("Enter a Name:");
			scanf("%s", empName);
			printf("Enter a Manager Name:");
			scanf("%s", mangerName);
			moveEmploy(tree, empName, mangerName);
			break;
		case 4:
			printf("Enter a name:");
			scanf("%s", empName);
			printEmployMangers(tree, empName);
			printf("\n");
			break;
		default:
			break;
		}

	}
}

