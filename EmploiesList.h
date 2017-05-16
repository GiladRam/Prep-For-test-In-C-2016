#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
	char* manegers;
	char* name;
	struct listNode *next;
	struct listNode *prev;
	struct listNode *myEmploies;
}listNode;


listNode* constractor();
//int destroyList(LinkList*);
//employ* creatEmploy(char* employName, char* managerName);
//int destroyEmploy(employ*);
int addemploy(listNode* list, char* employName, char* managerName);
listNode* searchEmploy(listNode* companyTree, char* name);

