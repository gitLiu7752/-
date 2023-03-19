#include <stdio.h>
#include <stdlib.h>
//每个节点的结构 
typedef struct DulNode{
	int data;
	struct DulNode *prior;//前驱指针 
	struct DulNode *next;//后继指针 
}DulNode,*DuLinkList;
 //生成链表 
struct DulNode* CreatList()
{
	DulNode* headNode=(DulNode*)malloc(sizeof(DulNode*));
	headNode->prior=NULL;
	headNode->next=NULL;
	return headNode;
}
//新建节点 
struct DulNode* creatNode(int data)
{
	DulNode* newNode=(DulNode*)malloc(sizeof(DulNode*));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prior=NULL;
	return newNode;
} 
//表头法插入 
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
//删除
void deleteNode(struct DulNode* headNode,int posdata) 
{
	struct DulNode*posNode=headNode->next;
	struct DulNode*posNodeFront=headNode;
	struct DulNode*posNodeNext=posNode->next;
	if (posNode==NULL)
	printf("无法删除，链表为空\n");
	else
	{
		while(posNode->data!=posdata)
		{
			posNodeFront=posNode;
			posNode=posNodeNext;
			posNodeNext=posNode->next;
			if(posNode==NULL)
			{
				printf("没有找到相关信息，无法删除\n");
				return ;
			} 
		}
		posNodeNext->prior=posNode->prior;
		posNodeFront->next=posNode->next;
	    free(posNode);
	}
}
//销毁
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
//查找 
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








