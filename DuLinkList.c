#include <stdio.h>
#include <stdlib.h>
//ÿ���ڵ�Ľṹ 
typedef struct DulNode{
	int data;
	struct DulNode *prior;//ǰ��ָ�� 
	struct DulNode *next;//���ָ�� 
}DulNode,*DuLinkList;
 //�������� 
struct DulNode* CreatList()
{
	DulNode* headNode=(DulNode*)malloc(sizeof(DulNode*));
	headNode->prior=NULL;
	headNode->next=NULL;
	return headNode;
}
//�½��ڵ� 
struct DulNode* creatNode(int data)
{
	DulNode* newNode=(DulNode*)malloc(sizeof(DulNode*));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prior=NULL;
	return newNode;
} 
//��ͷ������ 
void insertNode(struct DulNode* headNode,int data)
{
	DulNode *temNode;
	temNode=headNode->next;
	DulNode *newNode=creatNode(data);
	newNode->next=temNode;
	headNode->next=newNode;
	newNode->prior=headNode;
	temNode->prior=newNode;
	return;
}
//ɾ��
void deleteNode(struct DulNode* headNode,int posdata) 
{
	struct DulNode*posNode=headNode->next;
	struct DulNode*posNodeFront=headNode;
	struct DulNode*posNodeNext=posNode->next;
	if (posNode==NULL)
	printf("�޷�ɾ��������Ϊ��\n");
	else
	{
		while(posNode->data!=posdata)
		{
			posNodeFront=posNode;
			posNode=posNodeNext;
			posNodeNext=posNode->next;
			if(posNode==NULL)
			{
				printf("û���ҵ������Ϣ���޷�ɾ��\n");
				return ;
			} 
		}
		posNodeNext->prior=posNode->prior;
		posNodeFront->next=posNode->next;
	    free(posNode);
	}
}
//����
void CleanDuList(struct DulNode* headNode)
{
	DulNode *p=headNode,*q;
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
int GetElem( struct DulNode* headNode,int i,int e)
{
	int j;
	struct DulNode*p=headNode->next;
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

int main()
{
	return;
}








