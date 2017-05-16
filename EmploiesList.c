#include "EmploiesList.h"


listNode* constractor(){
	listNode* dummyHead = (listNode*) malloc(sizeof (listNode));
	return dummyHead;
}

char* endOfString(char* s){
	while(*s++);
	return (s - 1);
}

void updateEmployMangerNames (listNode* employ, listNode* manger){
	// + 2 - one byte for , and on for 0 (end of string)
	char* mangers = (char*)malloc(sizeof(manger->manegers) + sizeof(manger->name) + 2);
	if( manger -> manegers != NULL){
		strcpy(mangers, manger-> manegers);
		char* endoflist = endOfString(mangers);
		*endoflist = ',';
		endoflist++;
		strcpy(endoflist,manger -> name);

	}else{
		strcpy(mangers,manger -> name);
	}
	employ -> manegers = mangers;

}

int insertToList(listNode* prev, listNode* current, listNode* toAdd){

	if(prev != NULL && current != NULL && toAdd!= NULL){
		prev -> next = toAdd;
		toAdd -> prev = prev;
		toAdd -> next = current;
		current -> prev = toAdd;
		return 1;
	}
	return 0;

}

int addToSortedList(listNode* list, listNode* nodeToAdd){
	char* nodeTOAddName = nodeToAdd -> name;
	listNode* prev = list;
	listNode* current = list -> next;

	while(current != NULL){
		char* currentName = current -> name;
		if( strcmp(currentName, nodeTOAddName) > 0){
			insertToList(prev, current, nodeToAdd);
			return 1;
		}
		prev = current;
		current = current -> next;
	}
	// add at the end of the list
	prev->next = nodeToAdd;
	nodeToAdd->prev = prev;
	nodeToAdd->next = NULL;

	return 1;

}

int addemploy(listNode* compayTree, char* employName, char* managerName){
	listNode* employNode = (listNode*)malloc(sizeof(listNode));
	employNode -> name = employName;
	listNode* employManger = searchEmploy(compayTree, managerName);
	// Could not find the manger
	if(employManger == NULL){
		addToSortedList(compayTree,employNode);
	}else{
		if(employManger-> myEmploies == NULL){
			employManger -> myEmploies = constractor();
		}
		addToSortedList(employManger-> myEmploies, employNode);
		updateEmployMangerNames(employNode, employManger);
	}
	return 1;
}

listNode* searchEmploy(listNode* companyTree, char* name){

	listNode* foundedNode = NULL;
	if(companyTree == NULL){
		return NULL;
	}
	listNode* currentNode = companyTree -> next;
	if(currentNode != NULL ){
		char* currentNodeName = currentNode -> name;
		if( strcasecmp(currentNodeName, name) == 0){
			return currentNode;
		}else{
			foundedNode = searchEmploy(currentNode, name);
			if( foundedNode == NULL){
				foundedNode = searchEmploy(currentNode->myEmploies , name);
			}

		}
	}
	return foundedNode;
}

void printTree(listNode* companyTree, int numberOfDepth){
	if(companyTree == NULL){
		return;
	}else{
		listNode* current = companyTree -> next;
		while(current != NULL){
			if(current->name != NULL){
				int i =0;
				for(;i < numberOfDepth; i++){
					printf("\t");
				}
				printf("%s\n", current -> name);
				printTree(current -> myEmploies, numberOfDepth+1);
			}
			current = current-> next;
		}

	}
}

void takeOutOfAlist(listNode* node){
	listNode* pre = node -> prev;
	listNode* next = node -> next;
	pre -> next = next;
	if( next != NULL){
		next -> prev = pre;
	}
	node -> next = NULL;
	node -> prev = NULL;
}

void moveEmploy(listNode* tree ,char* employName, char* newMangerName){
	listNode* employToMove = searchEmploy(tree, employName);
	listNode* newManger = searchEmploy(tree, newMangerName);
	takeOutOfAlist(employToMove);
	if(newManger-> myEmploies == NULL){
		newManger -> myEmploies = constractor();
	}
	addToSortedList(newManger -> myEmploies, employToMove);
	updateEmployMangerNames(employToMove, newManger);
}

void printEmployMangers(listNode* tree, char* name){
	listNode* em = searchEmploy(tree, name);
	char* managers = em -> manegers;
	while(*managers){
		printf("\t*)");
		while((*managers) != ',' && (*managers)){
			printf("%c", *managers);
			managers++;
		}
		printf("\n");
		managers++;
	}
	printf("Mangers are: %s", em->manegers);
}

int joinLists(listNode* listOne, listNode* listTwo){
	listNode* pointerInListTwo = listTwo -> next;
	listNode* currentNodeTopass;
	while(pointerInListTwo != NULL){
		currentNodeTopass = pointerInListTwo;
		pointerInListTwo = pointerInListTwo-> next;
		takeOutOfAlist(currentNodeTopass);
		addToSortedList(listOne, currentNodeTopass);
	}
}

int removeEmploy(){

}

/*
 * employ* creatEmploy(char* employName, char* managerName){
	employ* employ = (employ*) malloc(sizeof(employ*));
	if(employ){
		perror("error in creatEmploy");
		return NULL;
	}
	if( strlen(employName) < 15){
		employ -> name = employName;
	}else {
		// ToDO - add for longer name
	}
	return employ;
}
 */
