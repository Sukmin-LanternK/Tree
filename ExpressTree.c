#include "ExpressTree.h"

ETNode* ET_CreatNode(ElementType NewData) {
	ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	return NewNode;
}
void ET_DestroyNode(ETNode* Node) {
	free(Node);
}
void ET_DestroyTree(ETNode* Root) {
	if (Root == NULL) return;
	
	ET_DestroyTree(Root->Left);
	ET_DestroyTree(Root->Right);
	ET_DestroyNode(Root);
}

void ET_PreOrderPrintTree(ETNode* Root) {
	if (Root == NULL) return;

	printf("%c ", Root->Data);
	ET_PreOrderPrintTree(Root->Left);
	ET_PreOrderPrintTree(Root->Right);
}
void ET_InOrderPrintTree(ETNode* Root) {
	if (Root == NULL) return;

	ET_InOrderPrintTree(Root->Left);
	printf("%c ",Root->Data);
	ET_InOrderPrintTree(Root->Right);
}
void ET_PostOrderPrintTree(ETNode* Root) {
	if (Root == NULL) return;

	ET_PostOrderPrintTree(Root->Left);
	ET_PostOrderPrintTree(Root->Right);
	printf("%c ",Root->Data);
}

void ET_BuildTree(char* Postfix, ETNode** Root) {
	// �ڿ������� ���� �б�

	/*
	1. ó�� Root �����
	2. �� ������ ������? -> ���ϵ� ����Ʈ ���� 
	2.1 �� ������ ������? -> ���ϵ� ����Ʈ ���� 
	2.2.1 �� ������ ���� -> ���ϵ� ����Ʈ���� ä���ִ´� (�׸��� �� �ؿ��� �� �Ȼ���) 
	2.2.2 �� ������ ������ -> ���ϵ� ����Ʈ���� ä���ִ´� 
	*/

	int postfixLen = strlen(Postfix);
	char Token = Postfix[postfixLen - 1];
	Postfix[postfixLen - 1] = '\0';

	switch (Token) {
	case '+': case'-': case'*': case'/':
		*Root = ET_CreatNode(Token);
		ET_BuildTree(Postfix, &(*Root)->Right);
		ET_BuildTree(Postfix, &(*Root)->Left);
		break;
	case ' ':
		break;
	default : 
		*Root = ET_CreatNode(Token);
		break;
	}
}

double ET_Calculate(ETNode* Tree) {
	// ������ ��ȸ 
	// ���ϵ� ���ϵ� -> �θ� ��忡 ���� ���� 
	// �θ��带 ����� ġȯ

	if (Tree == NULL) return 0;

	double left = 0;
	double right = 0;
	double result = 0;

	switch (Tree->Data){
	case '+': case'-': case'*': case'/':
		left = ET_Calculate(Tree->Left);
		right = ET_Calculate(Tree->Right);

		if (Tree->Data == '+') result = left + right;
		else if (Tree->Data == '-') result = left - right;
		else if (Tree->Data == '*') result = left * right;
		else if (Tree->Data == '/') result = left / right;
		break;

	default :
		char temp[2] = { '0', };
		temp[0] = (Tree)->Data;
		result = atof(temp);
	}

	return result; 
}