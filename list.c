#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
char ShowMenu ();
struct Node
{
	int id;
	Position Next;
};

main (void)
{
	List L = malloc(sizeof(struct Node));
	L = MakeEmpty (L);
	int input;
	Position P = L;
	puts("Please input integers separated with space or newline:\n");
	while (scanf("%d", &input) == 1) {
		Insert (input, L, P);
		P = P->Next;
	}
	Display (L);

	return 0;
}

int
IsEmpty (List L)
{
	if (L->Next == NULL)
		return true;
	else
		return false;
}
int
IsLast (Position P, List L)
{
	if (P->Next == NULL)
		return true;
	else
		return false;
}
List
MakeEmpty (List L)
{
	L->Next = NULL;
}
void
Insert (int X, List L, Position P)
{
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof (struct Node));
	if (TmpCell == NULL)
		printf("Out of Space!");
	TmpCell->id = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
Position
Find (int X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->id != X)
		P = P->Next;

	return P;
}
Position
FindPrevious (int x, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->id != x)
		P = P->Next;

	return P;
}
void Delete (int X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (P->Next == NULL)
		printf("Can not find %d, so not able to delete it\n", X);
	if (! IsLast(P, L)) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free (TmpCell);
	}
}
void
Display (List L)
{
	while (! IsEmpty(L)) {
		printf("%d\n", L->Next->id);
		L = L->Next;
	}
}

void Append (List L)
{
	int input;
	Position P = L;
	puts("Please input integers separated with space or newline:\n");
	while (scanf("%d", &input) == 1) {
		Insert (input, L, P);
		P = P->Next;
	}
}
	
/*
#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty (List L);
int IsEmpty (List L);
int IsLast (Position P, List L);
Position Find (int X, List L);
Position FindPrevious (int X, List L);
void Delete (int X, List L);
void Insert (int X, List L, Position P);
void DeleteList (List L);
void Display (List L);
Position Header (List L);
Position First (List L);
Position Advance (Position P);
int Retrieve (Position P);

#endif
*/
