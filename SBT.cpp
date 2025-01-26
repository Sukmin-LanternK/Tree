#include "SBT.h"

SBTNode* SBTNode_CreateNode(ElementType Data) {
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = Data;

	return NewNode;
}

void SBTNode_DestroyNode(SBTNode* Node) {
	free(Node);
}

void SBTNode_PreorderPrintTree(SBTNode* Node) {
	if (Node == NULL) return;
	printf("%c", Node->Data);

	SBTNode_PreorderPrintTree(Node->Left);
	SBTNode_PreorderPrintTree(Node->Right);
}

void SBTNode_InorderPrintTree(SBTNode* Node) {
	if (Node == NULL) return;
	SBTNode_InorderPrintTree(Node->Left);
	printf("%c", Node->Data);
	SBTNode_InorderPrintTree(Node->Right);
}

void SBTNode_PostorderPrintTree(SBTNode* Node) {
	if (Node == NULL) return;
	SBTNode_PostorderPrintTree(Node->Left);
	SBTNode_PostorderPrintTree(Node->Right);
	printf("%c", Node->Data);
}

void SBTNode_DestroyTree(SBTNode* Node) {
	if (Node == NULL) return;
	SBTNode_PreorderPrintTree(Node->Left);
	SBTNode_PreorderPrintTree(Node->Right);
	SBTNode_DestroyNode(Node);
}