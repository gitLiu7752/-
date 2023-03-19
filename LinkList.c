#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

struct Node* creatList()//创建链表 
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode->date=1;
	headNode->next = NULL;
	return headNode;
}
//创建节点 
struct Node* creatNode(int data)
{
	struct Node*  newNode=(struct Node*)malloc(sizeof(struct Node ));
	newNode->data = data;
	newNode->next = NULL;
	return newNode; 
}
//遍历 
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
//表头法插入 
void insertNode(struct Node*headNode,int data)
{
	struct Node*newNode=creatNode(data);
	newNode->next=headNode->next;
	headNode->next=newNode;
	return ; 
}
//删除	
void deleteNode(struct Node*headNode ,int posData)
{
	struct Node*posNode=headNode->next;
	struct Node*posNodeFront=headNode;
	if (posNode==NULL)
	printf("无法删除，链表为空\n");
	else
	{
		while(posNode->data!=posData)
		{
			posNodeFront=posNode;
			posNode=posNodeFront->next;
			if(posNode==NULL)
			{
				printf("没有找到相关信息，无法删除\n");
				return ;
			} 
		}
		posNodeFront->next=posNode->next;
	    free(posNode);
	}
}
//销毁 
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
//查找
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
//奇偶调换 会漏数据 
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

//找中点 
int MidPoint(struct Node*headNode)
{
	int i=0;//i负责计数 
	struct Node *p1,*p2;    //p1为快指针，p2为慢指针 
	p2=p1=headNode->next;
	while(p1->next!=NULL||p1->next->next!=NULL)
	{
		p1=p1->next->next;
		p2=p2->next;
		i++;
	} 
	return i;//当p1走到链表最后时i的大小就是中间节点的位置 
}
//判断成环
 int judgeRing(struct Node*headNode)
 {
	struct Node *p1,*p2;    //p1为快指针，p2为慢指针 
	p2=p1=headNode->next;
	while(1)
	{
		p1=p1->next->next;
		p2=p2->next;
		if(p1==p2)return 1;//如果p1p2相遇说明链表成环 
		if(p1->next==NULL||p1->next->next==NULL)return 0;//如果p1走到链表尽头，说明不成环 
	} 
 }

//反转链表不递归 
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
//反转链表递归
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
