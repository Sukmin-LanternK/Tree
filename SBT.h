#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNODE {
	struct tagSBTNODE* Left;
	struct tagSBTNODE* Right;

	ElementType Data;
}SBTNode;

SBTNode* SBTNode_CreateNode(ElementType Data);
void SBTNode_DestroyNode(SBTNode* Node);
void SBTNode_PreorderPrintTree(SBTNode* Node);
void SBTNode_InorderPrintTree(SBTNode* Node);
void SBTNode_PostorderPrintTree(SBTNode* Node);
void SBTNode_DestroyTree(SBTNode* Node);

