//Whole program without using pprev for physical reverse

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	struct node * pPrev;
	int iData;
	struct node * pNext;
};

void Display(struct node *);
void InsertFirst(struct node **,int );
void PhysicalReverse(struct node **);


int main(void)
{
	struct node * pFirst=NULL;

	InsertFirst(&pFirst,40);
	InsertFirst(&pFirst,30);
	InsertFirst(&pFirst,20);
	InsertFirst(&pFirst,10);
	
	

	Display(pFirst);
	

	PhysicalReverse(&pFirst);

	Display(pFirst);


	getch();
    return 0;
}

void InsertFirst(struct node **ppHead,int iNo)
{
	struct node * pNewNode=NULL;

    pNewNode=(struct node *)malloc(sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation failed");
	}
	pNewNode->iData=iNo;
	pNewNode->pPrev=NULL;

	if(NULL==*ppHead)
	{
		pNewNode->pNext=NULL;
		*ppHead=pNewNode;
		return;
	}
	 pNewNode->pNext=*ppHead;
	 (*ppHead)->pPrev=pNewNode;
	 *ppHead=pNewNode;
}


void Display(struct node *pHead)
{
	if(NULL==pHead)
	{
		printf("Linkedlist is empty");
		return;
	}
		

	while(pHead!=NULL)
	{
		printf("|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
		pHead=pHead->pNext;
	}
	
	printf("\n");
}
//PhysicalReverse of Doubly Without using pPrev

//call:-void PhysicalReverse(&pFirst);

void PhysicalReverse(struct node **ppHead)
{
	struct node *pCurrent=*ppHead;

	struct node *pTemp=NULL;

	if(NULL==*ppHead)
		return;
	if(NULL==(*ppHead)->pNext)
		return;
	
    while(pCurrent!=NULL)
	{
		pTemp=pCurrent->pPrev;
		pCurrent->pPrev=pCurrent->pNext;
		pCurrent->pNext=pTemp;
		pCurrent=pCurrent->pPrev;
		
	}
	if(pTemp!=NULL)
	 pTemp=pTemp->pPrev;
	*ppHead=pTemp;
	
}