
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

listNode* constructor(){
	listNode* head = (listNode*) malloc(sizeof(listNode));
	head -> name = "DUMMY";
	head -> prev = NULL;
	head -> next = NULL;
	head -> under = NULL;
	return head;
}

listNode* createNode(char* name){
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	if(newNode){
		newNode -> name = name;
		newNode -> next = NULL;
		newNode -> prev = NULL;
	}
	return newNode;

}

int add(listNode* listHead ,listNode* node){
	if(listHead -> next == NULL){
		listHead -> next = node;
		node -> prev = listHead;
		return 0;
	}
	listNode* prev = listHead;
	listNode* current = listHead ->next;
	while (prev -> next != NULL){
		if(strcmp(current -> name, node->name) > 0){
			enterInBetween(prev, current, node);
			return 0;
		}
		prev = current;
		current = current->next;
	}
	prev -> next = node;
	node -> prev = prev;
	return 0;
}

void enterInBetween(listNode* prev, listNode* current , listNode* node){
	prev -> next = node;
	node -> prev = prev;
	node -> next = current;
	current -> prev = node;
}

int addUnder(listNode* h_node, listNode* under_node){
	if( h_node ->under == NULL){
		h_node ->under = constructor();
	}
	return add(h_node ->under, under_node);
}

listNode* find_emp(listNode* tree, char* name){

	if(!tree){
		return NULL;
	}
	if(strcmp(tree->name, name) == 0){
		return tree;
	}else{
		listNode* node = find_emp(tree->next, name);
		if(tree -> under != NULL && node == NULL)
			node = find_emp(tree -> under , name);
		return node;
	}
}

void printTree(listNode* tree, int numberOfSpaces){
	if(tree == NULL){
		return;
	}
	else{
		int i =0;
		for(; i< numberOfSpaces; i++){
			printf("\t");
		}
		printf("%s\n", tree->name);
		if(tree-> under != NULL){
			printTree(tree-> under ->next, numberOfSpaces+1);
		}
		printTree(tree -> next, numberOfSpaces);
	}
}

int moveEmploy(listNode* tree, char* employName, char* newMangerName){
	listNode* employ = find_emp(tree, employName);
	listNode* newManger = find_emp(tree, newMangerName);
	takeOutOfaList(employ);
	if(!newManger){
		add(tree, employ);
	}else{
		addUnder(newManger, employ);
	}

	return 0;
}

int takeOutOfaList(listNode* node){
	node -> prev ->next = node->next;
	node -> prev = NULL;
	node -> next = NULL;
	return 0;
}

int unitLists(listNode* listOne, listNode* listTwo){
	listNode* currentInListTwo = listTwo;
	listNode* currentToAdd;
	while(currentInListTwo -> next != NULL){
		currentToAdd = currentInListTwo-> next;
		takeOutOfaList(currentToAdd);
		add(listOne, currentToAdd);
	}
	return 0;
}

int removeEmploy(listNode* tree, char* name){
	listNode* employToremove = find_emp(tree, name);
	if(employToremove -> under != NULL){
		unitLists(employToremove-> prev, employToremove -> under);
	}
	takeOutOfaList(employToremove);
	free(employToremove);
	return 0;
}
