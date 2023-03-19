#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

struct Node* creatList()//�������� 
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode->date=1;
	headNode->next = NULL;
	return headNode;
}
//�����ڵ� 
struct Node* creatNode(int data)
{
	struct Node*  newNode=(struct Node*)malloc(sizeof(struct Node ));
	newNode->data = data;
	newNode->next = NULL;
	return newNode; 
}
//���� 
void printList(struct Node*headNode)
{
	struct Node*pMove= headNode->next;
	while(pMove)
	{
		printf("%d",pMove ->data);
		pMove=pMove->next;
	}
	printf("\n");
}
//��ͷ������ 
void insertNode(struct Node*headNode,int data)
{
	struct Node*newNode=creatNode(data);
	newNode->next=headNode->next;
	headNode->next=newNode;
	return ; 
}
//ɾ��	
void deleteNode(struct Node*headNode ,int posData)
{
	struct Node*posNode=headNode->next;
	struct Node*posNodeFront=headNode;
	if (posNode==NULL)
	printf("�޷�ɾ��������Ϊ��\n");
	else
	{
		while(posNode->data!=posData)
		{
			posNodeFront=posNode;
			posNode=posNodeFront->next;
			if(posNode==NULL)
			{
				printf("û���ҵ������Ϣ���޷�ɾ��\n");
				return ;
			} 
		}
		posNodeFront->next=posNode->next;
	    free(posNode);
	}
}
//���� 
void ClearList(struct Node*headNode)
{
	Node *p=headNode,*q;
	p=p->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	headNode->next=NULL;
	return ; 
}
//����
int GetElem(struct Node*headNode,int i,int e)
{
	int j;
	struct Node*p;
	p=headNode->next;
	j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if (!p||j>i)return 0;
	else 
	{
		e=p->data;
		return e;
	}
	
} 
//��ż���� ��©���� 
void ExChange(struct Node*headNode)
{
	struct Node*oddNode=headNode->next;
	struct Node*evenNode=oddNode->next;
	struct Node*temNode;
    if (oddNode==NULL||evenNode==NULL) return;
    headNode->next=evenNode;
    while(1)
	{
		temNode=evenNode->next;
		oddNode->next=temNode->next;
		
		if(temNode==NULL)
		{
			oddNode->next=evenNode->next;
			evenNode->next=oddNode;
			break;
		}
		evenNode->next=oddNode;
		oddNode=temNode;
		evenNode=temNode->next;
		if(evenNode->next==NULL)
		{
		    
		    break;
		}
	}
	return;
}

//���е� 
int MidPoint(struct Node*headNode)
{
	int i=0;//i������� 
	struct Node *p1,*p2;    //p1Ϊ��ָ�룬p2Ϊ��ָ�� 
	p2=p1=headNode->next;
	while(p1->next!=NULL||p1->next->next!=NULL)
	{
		p1=p1->next->next;
		p2=p2->next;
		i++;
	} 
	return i;//��p1�ߵ��������ʱi�Ĵ�С�����м�ڵ��λ�� 
}
//�жϳɻ�
 int judgeRing(struct Node*headNode)
 {
	struct Node *p1,*p2;    //p1Ϊ��ָ�룬p2Ϊ��ָ�� 
	p2=p1=headNode->next;
	while(1)
	{
		p1=p1->next->next;
		p2=p2->next;
		if(p1==p2)return 1;//���p1p2����˵������ɻ� 
		if(p1->next==NULL||p1->next->next==NULL)return 0;//���p1�ߵ�����ͷ��˵�����ɻ� 
	} 
 }

//��ת�����ݹ� 
struct Node* reverse1(struct Node*headNode)
{
	if(headNode==NULL)
	return;
	Node*p=headNode->next;
	headNode->next=NULL;
	Node*tem=NULL;
	while(p)
	{
		tem=p->next;
		insertNode(headNode,p->data);
		p=tem;
	} 
	return headNode;
} 
//��ת����ݹ�
struct Node* reverse2(struct Node*headNode) 
{
	if (headNode==NULL||headNode->next==NULL)return headNode;
	
	Node*newHead=reverse2(headNode->next);
	
	headNode->next->next=headNode;
	headNode->next=NULL;
	return newHead;
}

int main()
{
	struct Node*list=creatList();
	
	insertNode(list,1);
	insertNode(list,2);
	insertNode(list,3);
	insertNode(list,4);
	insertNode(list,5);
	insertNode(list,4);
	insertNode(list,5);
	printList(list);
	
    deleteNode(list,3);
	printList(list);
	
	ExChange(list);
	printList(list);
	
	ClearList(list);
	printList(list);
	
	system("pause");
	return 0;
}
