//PhysicalReverse of Doubly using pPrev

//call:-void PhysicalReverse(&pFirst);

void PhysicalReverse(struct node **ppHead)
{
	struct node *pPrev=NULL;
	struct node *pNext=NULL;
	struct node *pCurrent=*ppHead;

	while(pCurrent!=NULL)
	{
		pNext=pCurrent->pNext;
		pCurrent->pNext=pPrev;
		pCurrent->pPrev=pNext;
		pPrev=pCurrent;
		pCurrent=pNext;
		
	}

	*ppHead=pPrev;
}