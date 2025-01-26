#include "SBT.h"

int main() {

	SBTNode* A = SBTNode_CreateNode('A');
	SBTNode* B = SBTNode_CreateNode('B');
	SBTNode* C = SBTNode_CreateNode('C');
	SBTNode* D = SBTNode_CreateNode('D');
	SBTNode* E = SBTNode_CreateNode('E');
	SBTNode* F = SBTNode_CreateNode('F');
	SBTNode* G = SBTNode_CreateNode('G');

	A->Left = B;
	B->Left = C;
	B->Right = D;
	
	A->Right = E;
	E->Left = F;
	E->Right = G;

	printf("PreOrder: ");
	SBTNode_PreorderPrintTree(A);
	printf("\n\n");
	printf("InOrder: ");
	SBTNode_InorderPrintTree(A);
	printf("\n\n");
	printf("PostOrder: ");
	SBTNode_PostorderPrintTree(A);
	printf("\n\n");

	SBTNode_DestroyTree(A);

	return 0;
}