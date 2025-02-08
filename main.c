#include "ExpressTree.h"


int main() {
	ETNode* Root = NULL;
	char Postfix[30] = "71*52-/";
	ET_BuildTree(Postfix, &Root);

	/*printf("Preorder: ");
	ET_PreOrderPrintTree(Root);
	printf("\n\n");*/

	printf("Inorder: ");
	ET_InOrderPrintTree(Root);
	printf("\n\n");

	printf("Postorder: ");
	ET_PostOrderPrintTree(Root);
	printf("\n\n");

	double result = ET_Calculate(Root);
	printf("%f", result);


	return 0;
}