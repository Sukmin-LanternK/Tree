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
	// 뒤에서부터 수식 읽기

	/*
	1. 처음 Root 만든다
	2. 그 다음이 연산자? -> 차일드 라이트 생성 
	2.1 그 다음이 연산자? -> 차일드 레프트 생성 
	2.2.1 그 다음이 숫자 -> 차일드 라이트부터 채워넣는다 (그리고 그 밑에는 더 안생김) 
	2.2.2 그 다음이 연산자 -> 차일드 라이트부터 채워넣는다 
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
	// 후위로 조회 
	// 차일드 차일드 -> 부모 노드에 따라 연산 
	// 부모노드를 결과로 치환

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