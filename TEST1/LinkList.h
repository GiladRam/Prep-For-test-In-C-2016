/*
 * LinkList.h
 *
 *  Created on: May 11, 2017
 *      Author: student
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct listNode{
	struct listNode *next;
	struct listNode *prev;
	char* name;
	char** direction;
	struct listNode *under;
}listNode;

listNode* constructor();
int add(listNode* listHead ,listNode* node);
void enterInBetween(listNode*, listNode*, listNode*);
int addUnder(listNode* h_node, listNode* under_node);
listNode* find_emp(listNode* tree,char* name);
void printTree(listNode* tree, int numberOfSpaces);
listNode* createNode(char* name);
int moveEmploy(listNode* tree, char* employName, char* newMangerName);
int takeOutOfaList(listNode* node);
int removeEmploy(listNode*, char* name);
int unitLists(listNode* headOne, listNode* headTwo);
#endif /* LINKLIST_H_ */
