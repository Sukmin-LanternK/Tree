#include "LCRS.h"

LCRSNode* LCRS_CreateNode(ElementType NewData) {
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));

	NewNode->Data = NewData;
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;

	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node) {
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root) {
	if (Root->LeftChild != NULL) LCRS_DestroyTree(Root->LeftChild);
	if (Root->RightSibling != NULL) LCRS_DestroyTree(Root->RightSibling);

	Root->LeftChild = NULL;
	Root->RightSibling = NULL;
	free(Root);
}

void LCRS_AddChild(LCRSNode* Parent, LCRSNode* Child) {
	if (Parent->LeftChild == NULL) {
		Parent->LeftChild = Child;
	}
	else {
		LCRSNode* TempSibling = Parent->LeftChild;
		while (TempSibling->RightSibling != NULL) {
			TempSibling = TempSibling->RightSibling;
		}
		TempSibling->RightSibling = Child;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth) {
	for (int i = 0;i < Depth - 1;i++) {
		printf(" ");
	}
	if (Depth > 0) printf("+--");

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL) LCRS_PrintTree(Node->LeftChild, Depth + 1);
	if (Node->RightSibling != NULL) LCRS_PrintTree(Node->RightSibling, Depth);
}