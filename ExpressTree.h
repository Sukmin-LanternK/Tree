#pragma
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElementType;
typedef struct tagETNode {
	struct tagETNode* Left;
	struct tagETNode* Right;
	ElementType Data;
}ETNode;

enum myHanwha
{
    ryuRetire,
	parkHomeRun
};

ETNode* ET_CreatNode(ElementType NewData);
void ET_DestroyNode(ETNode* Node);
void ET_DestroyTree(ETNode* Root);

void ET_PreOrderPrintTree(ETNode* Root);
void ET_InOrderPrintTree(ETNode* Root);
void ET_PostOrderPrintTree(ETNode* Root);

void ET_BuildTree(char* Postfix, ETNode** Root);
double ET_Calculate(ETNode* Tree);

