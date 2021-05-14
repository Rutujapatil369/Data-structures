//Third version of linkedlist

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	struct node * pPrev;
	int iData;
	struct node * pNext;
};


void Display(struct node *,struct node *);
int CountNode(struct node *,struct node *);
void Reverse(struct node **,struct node **);
int DeleteLast(struct node **,struct node **);
void DeleteAll(struct node **,struct node **);
int DeleteFirst(struct node **,struct node **);
void InsertLast(struct node **,struct node **,int);
void InsertLast2(struct node **,struct node **,int);
void PhysicalReverse(struct node **,struct node **);
void InsertFirst(struct node **,struct node **,int);
void InsertFirst2(struct node **,struct node **,int);
int SearchAllOccurance(struct node *,struct node *,int);
int DeleteAtPosition(struct node **,struct node **,int);
int SearchLastOccurance(struct node *,struct node *,int);
int SearchFirstOccurance(struct node *,struct node *,int);
void InsertAtPosition(struct node **,struct node **,int,int);
void InsertAtPosition2(struct node **,struct node **,int,int);
void Concate(struct node **,struct node **,struct node **,struct node **);




int main(void)
{
  int ch;
  int iPos;
  int iData;
  int iCount;
  struct node *pFirst=NULL;
  struct node *pLast=NULL;

  struct node *pSecond=NULL;
  struct node *pSlast=NULL;

  while(1)
  {
	printf("Operations on Doubly Circular Linked List\n");
	printf("-------------------------------------------\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Search\n"); 
	printf("4.Count\n");
	printf("5.Reverse\n");
	printf("6.Concate\n");
	
	printf("7.Exit\n");

	printf("Enter your choice:\n");
	scanf("%d",&ch);

	switch(ch)
	{
	   case 1:
					while(ch!=4 )
					{
                    printf("\n---- Insert Menu ----");
                    printf("\n1.Insert at first\n2.Insert at last\n3.Insert at position\n4.Back");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);

					 switch(ch)
                    {
                        case 1: printf("Inserting Nodes in first list at first\n");
	                            printf("Enter Data for node:\n");
							    scanf("%d",&iData);
	   
								InsertFirst(&pFirst,&pLast,iData);
								Display(pFirst,pLast);
								break;

								
								

                        case 2: printf("Inserting Nodesin first list at Last\n");
								printf("Enter Data for node:\n");
								scanf("%d",&iData);

								InsertLast(&pFirst,&pLast,iData);
								Display(pFirst,pLast);
								break;
								
							

                        case 3: 
							    printf("Inserting Nodes at position in first list\n");
							    
								printf("Enter position for node:\n");
								scanf("%d",&iPos);
								iCount=CountNode(pFirst,pLast);

								if(iPos<=0 || iPos>(iCount+1))
								{
									printf("Invalid Position");
									break;
								}

								
								printf("Enter Data for node:\n");
								scanf("%d",&iData);
							

								InsertAtPosition(&pFirst,&pLast,iData,iPos);
						        
								Display(pFirst,pLast);
								break;
					 
					 
							

                        case 4: break;
							default: printf("Wrong Choice!!");
						 
                       
					 
					 }
                    
					}
                  
					  break;
	   case 2:		 if(NULL==pFirst)
					 {
						printf("LinkedList is Empty\n");
						break;
					 }

								 
					while(ch!=4)
					{	
		            printf("\n---- Delete Menu ----");
                    printf("\n1.Delete at first\n2.Delete at last\n3.Delete at position\n4.Back");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);

					
 
                    switch(ch)
                    {
						
                        case 1:  
							      printf("Delete Node at first\n");
								  iData=DeleteFirst(&pFirst,&pLast);
									  if(iData!= -1)
										printf("Deleted data is %d\n",iData);
       
								 Display(pFirst,pLast);
								 break;

						case 2: 
							      printf("Delete Node at Last\n");
								  iData=DeleteLast(&pFirst,&pLast);
									 if(iData!= -1)
										printf("Deleted data is %d\n",iData);
								   Display(pFirst,pLast);
								   break;

						case 3: 
							
							    printf("Delete Node at position\n");

							    printf("Enter position for node:\n");
							    scanf("%d",&iPos);
	   
							      iData=DeleteAtPosition(&pFirst,&pLast,iPos);
							        if(iData!= -1)
								      printf("Deleted data is %d\n",iData);
							      Display(pFirst,pLast);
							      break;

					    case 4: break;
                        default: printf("Wrong Choice!!");
						}
					}
					
                    
                    break;

	   case 3:
		            if(NULL==pFirst)
					{
						printf("LinkedList is Empty\n");
						break;
					}

					while(ch!=4)
					{
						

					printf("\n---- Search Menu ----");
                    printf("\n1.Search first occurance\n2.Search last occurance\n3.Search all occurance\n4.Back");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
					
									 
					switch(ch)
                    {
						
                        case 1:  
							     
                    
							
							     printf("First Occurance:\n");
							     
							     printf("Enter Data for search:\n");
								 scanf("%d",&iData);
								 
								 iPos=SearchFirstOccurance(pFirst,pLast,iData);
								 Display(pFirst,pLast);

								 if(0==iPos)
								{
								   printf("Data not found in Linked List\n");
								   break;
								   
								}

								printf("Data %d found at %d position\n",iData,iPos);
								
								break;
								 

								  

						case 2: 
							    
							
							    printf("Last Occurance:\n");
							    
							    printf("Enter Data for search:\n");
								scanf("%d",&iData);

								iPos=SearchLastOccurance(pFirst,pLast,iData); 
								Display(pFirst,pLast);
								if(0==iPos)
								{
								   printf("Data not found in Linked List\n");
								   break;
								   
								}

								printf("Data %d found at %d position\n",iData,iPos);
								
								break;

						case 3: 
					
							
							     printf("All Occurance\n");
							     
							     printf("Enter Data for search:\n");
								 scanf("%d",&iData);
								 iPos=SearchAllOccurance(pFirst,pLast,iData);

								 if(0==iPos)
								{
								   printf("Data not found in Linked List\n");
								   break;
								}

								 printf("Data %d found %d times\n",iData,iPos);
								 Display(pFirst,pLast);
								 break;

						 case 4: break;
                         default: printf("Wrong Choice!!");
						}
                    }
                    break;

	   case 4:      printf("\n---- CountNode Menu ----\n");
		            iData=CountNode(pFirst,pLast);
				     if(iData!=-1)
					 printf("Counted nodes are: %d\n",iData);
					Display(pFirst,pLast);
					break;

        case 5:		if(NULL==pFirst)
					{
						 printf("LinkedList is Empty\n");
						 break;
					}

					
					while(ch!=3)
					{
                    printf("\n---- Reverse Menu ----");
                    printf("\n1.PhysicalRevere\n2.ReverseDisplay\n3.Back");
                    printf("\n\nEnter your choice(1-3):");
                    scanf("%d",&ch);
 
                    switch(ch)
                    { 
						
						case 1:

								  PhysicalReverse(&pFirst,&pLast);
								  Display(pFirst,pLast);

								  break;

						case 2: 
							     
								  Reverse(&pFirst,&pLast);
								  printf("Reverse of linkedlist is:\n");
								  Display(pFirst,pLast);
								  break;

					    case 3: break;
                        default: printf("Wrong Choice!!");
                    }
					}
					
                    break;

		case 6:

			        if(NULL==pFirst)
					{
						printf("First LinkedList is Empty\n");
						break;
					}
					
									 

		   			while(ch!=4)
					{
			        printf("\n---- Concate Menu ----\n");
				
					
		                if(NULL==pSecond)

						{
							 
								printf("Second list is empty\n");
								printf("1.InsertFirst\n");
								printf("2.InsertLast\n");
								printf("3.InsertAtPosition\n");
								printf("4.Back\n");

								printf("Enter your choice(1-4):\n");
								scanf("%d",&ch);
								
						}
						

	   switch(ch)
	   {
		  
						case 1:  printf("Inserting Nodes in second list at first\n");
								 printf("Enter Data for node:\n");
								 scanf("%d",&iData);
	   
								 InsertFirst2(&pSecond,&pSlast,iData);

								 Display(pSecond,pSlast);

								 break;

						case 2:  printf("Inserting Nodes at Last in second list\n");
								 printf("Enter Data for node:\n");
								 scanf("%d",&iData);
								 InsertLast2(&pSecond,&pSlast,iData);
								 Display(pSecond,pSlast);
								 break;


						case 3: 
							
							
							    printf("Inserting Nodes at position in  second list\n");

								printf("Enter Data for node:\n");
								scanf("%d",&iData);

								printf("Enter position for node:\n");
								scanf("%d",&iPos);
								InsertAtPosition2(&pSecond,&pSlast,iData,iPos);
								Display(pSecond,pSlast);
								break;

						case 4: break;

						default : printf("Wrong choice\n");
					   
	   
				
						}
	   
	
	  
                    
						Concate(&pFirst,&pLast,&pSecond,&pSlast);
	                    Display(pFirst,pLast);
						
					}
					break;


		
						   

		     
			            

	  case 7:
						if(NULL==pFirst)
						{
							 printf("LinkedList is Empty\n");
						     break;
						}

				
						printf("\n----Delete all ----\n");
					    DeleteAll(&pFirst,&pLast);
					    printf("All nodes deleted suceessfully\n");
					    Display(pFirst,pLast);
				

					 
						 exit(0);
					   
					    default: printf("Wrong Choice!!\n");

					    
				   }

 
   	  
	}
	getch();
   return 0;
  }


void InsertFirst(struct node **ppHead,struct node **ppTail,int iNo)
{

	struct node  *pNewNode=NULL;

	
    pNewNode=(struct node *)malloc(sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation failed");
		return;
	}

	pNewNode->iData=iNo;

    if(NULL==*ppHead)
	{
		*ppHead=pNewNode;
		*ppTail=pNewNode;

		(*ppTail)->pNext=*ppHead;
		(*ppHead)->pPrev=*ppTail;
		return;
	}
	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
	(*ppTail)->pNext=*ppHead;
	(*ppHead)->pPrev=*ppTail;

}
void Display(struct node *pHead,struct node *pTail)
{
	if(NULL==pHead)
	{
		printf("Linked List is Empty\n");
		return;
	}

	do
	{
		printf("|%d|->|%d|->|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
		pHead=pHead->pNext;

	}
	
	while(pHead!=pTail->pNext);

	printf("\n");
}
void InsertLast(struct node **ppHead,struct node **ppTail,int iNo)
{
	struct node  *pNewNode=NULL;

    pNewNode=(struct node *)malloc(sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation failed");
	}
	pNewNode->iData=iNo;

	if(NULL==*ppHead)
	{
		*ppHead=pNewNode;
		*ppTail=pNewNode;

		(*ppHead)->pPrev=*ppTail;
		(*ppTail)->pNext=*ppHead;
		return;
	}

	(*ppTail)->pNext=pNewNode;
	pNewNode->pPrev=*ppTail;
	*ppTail=pNewNode;
	(*ppTail)->pNext=*ppHead;
	(*ppHead)->pPrev=*ppTail;
}
void InsertAtPosition(struct node **ppHead,struct node **ppTail,int iNo,int iPos)
{
	int iCount;
	struct node * pTemp=NULL;
	struct node * pNewNode=NULL;

	if(NULL==*ppHead)
		return ;

	iCount=CountNode(*ppHead,*ppTail);

	if(iPos<=0 || iPos>iCount+1)
	{
		printf("Invalid Position\n");
		return;
	}

	if(iPos==1)
	{
		InsertFirst(ppHead,ppTail,iNo);
		return;
	}

	if(iPos==iCount+1)
	{
		InsertLast(ppHead,ppTail,iNo);
		return;
	}

	
    pNewNode=(struct node *) malloc (sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation failed");
		return;
		
	}
	pNewNode->iData=iNo;


	pTemp=*ppHead;

	iCount=1;

	while(iCount<iPos-1)
	{
		iCount++;

		pTemp=pTemp->pNext;
	}

	pNewNode->pNext=pTemp->pNext;
	pTemp->pNext=pNewNode;
	pTemp->pNext->pPrev=pNewNode;
	pNewNode->pPrev=pTemp;
}

int CountNode(struct node *pHead,struct node *pTail)
{
	int iCount=0;

	if(NULL==pHead)
	 return iCount;

	do
	{
		iCount++;
		pHead=pHead->pNext;
	}
	while(pHead!=pTail->pNext);
	return iCount;
}

int DeleteFirst( struct node **ppHead,struct node **ppTail)
{
	int iDelData;

	struct node *pTemp=NULL;

	if(NULL==*ppHead)
		return -1;

	iDelData=(*ppHead)->iData;

	if(*ppHead == *ppTail)
	{
		(*ppHead)->pNext=NULL;
		(*ppHead)->pPrev=NULL;
		free(*ppHead);
		*ppHead=*ppTail=NULL;

		return iDelData;
	}


	*ppHead=(*ppHead)->pNext;

	(*ppTail)->pNext->pNext=NULL;

	free((*ppTail)->pNext);

	(*ppTail)->pNext=*ppHead;

	(*ppHead)->pPrev=*ppTail;

	return iDelData;
}

	
int DeleteLast( struct node **ppHead,struct node **ppTail)
{

	int iDelData;
	struct node *pTemp;

	if(NULL==*ppHead)
		return -1;

	iDelData=(*ppTail)->iData;
    
	if(*ppHead==*ppTail)
	{
		(*ppHead)->pNext=NULL;
		(*ppHead)->pPrev=NULL;
		free(*ppHead);
		*ppHead=*ppTail=NULL;

		return iDelData;
	}

	*ppTail=(*ppTail)->pPrev;
	(*ppTail)->pNext->pPrev=NULL;
	free((*ppTail)->pNext);
	(*ppTail)->pNext=NULL;

	(*ppTail)->pNext=*ppHead;

	(*ppHead)->pPrev=*ppTail;

	return iDelData;

}

int DeleteAtPosition(struct node **ppHead,struct node **ppTail,int iPos)
{
	
	int iCount;
	struct node *pTemp=NULL;
	

	iCount=CountNode(*ppHead,*ppTail);
	if(iPos<=0 || iPos>iCount)
	{
		printf("Invalid Position\n");
		return -1;
	}

	if(iPos==1)
	{
		return DeleteFirst(ppHead,ppTail);
	}

	if(iPos==iCount)
	{
		return DeleteLast(ppHead,ppTail);
	}

	pTemp=*ppHead;

	iCount=1;

	while(iCount < iPos)
	{
		pTemp=pTemp->pNext;
		iCount++;
		
	}

	pTemp->pPrev->pNext=pTemp->pNext;
	pTemp->pNext->pPrev=pTemp->pPrev;
	
	pTemp->pNext=NULL;
	pTemp->pPrev=NULL;
    
	iCount=pTemp->iData;
	free(pTemp);
	pTemp=NULL;

    return iCount;
}

int SearchAllOccurance(struct node *pHead,struct node *pTail,int iKey)
{
	int iCounter=0;

	if(NULL==pHead)
	 return -1;

	do
	{
		if((pHead->iData)==iKey)
			iCounter++;
		pHead=pHead->pNext;
	}

	while(pHead!=pTail->pNext);

	return iCounter;

	
}

int SearchFirstOccurance(struct node *pHead,struct node *pTail,int iKey)
{
	int iPos=0;

	if(NULL==pHead)
	 return iPos;


	do
	{
		iPos++;
		if((pHead->iData)==iKey)
		{
			return iPos;
		}
		
		pHead=pHead->pNext;
	}while(pHead!=pTail->pNext);

	if(pTail->pNext==pHead)
		iPos=0;

	return iPos;
}

int SearchLastOccurance(struct node *pHead,struct node *pTail,int iKey)
{
	int iPos=0;
	int iLast=0;

	if(NULL==pHead && 0==iLast)
		return iPos;

	do
	{
		iPos++;
		if((pHead->iData)==iKey)
	
		iLast=iPos;
		
		
		pHead=pHead->pNext;
	}
	while(pHead!=pTail->pNext);
	return iLast;

}

void PhysicalReverse(struct node **ppHead,struct node **ppTail)
{
	struct node *pPrev=*ppTail;
	struct node *pNext=NULL;
	struct node *pCurrent=*ppHead;

	if(NULL==*ppHead)
		return;
	

	do
	{
		pNext=pCurrent->pNext;
		pCurrent->pNext=pPrev;
		pCurrent->pPrev=pNext;
		pPrev=pCurrent;
		pCurrent=pNext;
		
	}
	
	while(pCurrent!=*ppHead);

    *ppHead=pPrev;
	*ppTail=pCurrent;
	(*ppHead)->pPrev=*ppTail;
	
}
void Reverse(struct node **ppHead,struct node **ppTail)
{
	if(NULL==*ppHead)
	 return;
	
	 PhysicalReverse(ppHead,ppTail);
   Display(*ppHead,*ppTail);
   PhysicalReverse(ppHead,ppTail);
}

void InsertFirst2(struct node **ppHead,struct node **ppTail,int iNo)
{
	struct node  *pNewNode=NULL;

    pNewNode=(struct node *)malloc(sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation failed");
		return;
	}
	pNewNode->iData=iNo;

	if(NULL==*ppHead)
	{
		*ppHead=pNewNode;
		*ppTail=pNewNode;

		(*ppTail)->pNext=*ppHead;
		(*ppHead)->pPrev=*ppTail;
		return;
	}

	pNewNode->pNext=*ppHead;
	*ppHead=pNewNode;
	(*ppTail)->pNext=*ppHead;
	(*ppHead)->pPrev=*ppTail;

}

void Concate(struct node **ppHead,struct node **ppTail,struct node **ppHead2,struct node **ppTail2)
{
	if(NULL==*ppHead2)
		return;

	if(NULL==*ppHead)
	{
		*ppHead=*ppHead2;
		*ppTail=*ppTail2;
		*ppHead2=*ppTail2=NULL;
		return;
	}

	(*ppTail)->pNext=*ppHead2;
	(*ppHead2)->pPrev=*ppTail;
	(*ppTail2)->pNext=*ppHead;
	(*ppHead)->pPrev=*ppTail2;
	*ppTail=*ppTail2;
	*ppHead2=*ppTail2=NULL;

}
void InsertLast2(struct node **ppHead,struct node **ppTail,int iNo)
{
	struct node  *pNewNode=NULL;

    pNewNode=(struct node *)malloc(sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation failed");
	}
	pNewNode->iData=iNo;

	if(NULL==*ppHead)
	{
		*ppHead=pNewNode;
		*ppTail=pNewNode;

		(*ppHead)->pPrev=*ppTail;
		(*ppTail)->pNext=*ppHead;
		return;
	}

	(*ppTail)->pNext=pNewNode;
	pNewNode->pPrev=*ppTail;
	*ppTail=pNewNode;
	(*ppTail)->pNext=*ppHead;
	(*ppHead)->pPrev=*ppTail;
}

void InsertAtPosition2(struct node **ppHead,struct node **ppTail,int iNo,int iPos)
{
	int iCount;
	struct node * pTemp=NULL;
	struct node * pNewNode=NULL;

	iCount=CountNode(*ppHead,*ppTail);

	if(iPos<=0 || iPos>iCount+1)
	{
		printf("Invalid Position\n");
		return;
	}

	if(iPos==1)
	{
		InsertFirst(ppHead,ppTail,iNo);
		return;
	}

	if(iPos==iCount+1)
	{
		InsertLast(ppHead,ppTail,iNo);
		return;
	}

	
    pNewNode=(struct node *) malloc (sizeof(struct node));

	if(NULL==pNewNode)
	{
		printf("Memory allocation failed");
		return;
		
	}
	pNewNode->iData=iNo;


	pTemp=*ppHead;

	iCount=1;

	while(iCount<iPos-1)
	{
		iCount++;

		pTemp=pTemp->pNext;
	}

	pNewNode->pNext=pTemp->pNext;
	pTemp->pNext=pNewNode;
	pTemp->pNext->pPrev=pNewNode;
	pNewNode->pPrev=pTemp;
}






void DeleteAll(struct node **ppHead,struct node **ppTail)
 {

	 if(NULL==*ppHead)
		 return;

		 if((*ppHead)->pPrev==(*ppHead)->pNext)
	 {
		  *ppHead=NULL;
	      *ppTail=NULL;
	 }


	 while((*ppHead)!=(*ppTail))
	 {
		 if((*ppHead)->pNext!=(*ppTail))
		 {
			 (*ppHead)->pNext->pPrev=*ppTail;
	         (*ppTail)->pNext=(*ppHead)->pNext;
			 (*ppHead)->pPrev=NULL;
			 (*ppHead)->pNext=NULL;
            *ppHead=(*ppHead)->pNext;
		 }
		  *ppTail=NULL;
		  *ppHead=NULL;

		 
	  }
	     

 }



