#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct SingleNode{
	ElemType data;
	struct SingleNode *next;
}SingleNodeList,*Linklist;
void LinkedListInit(SingleNodeList **head){//1初始化有头节点的单链表 
    Linklist p; 
	if((*head=(SingleNodeList *)malloc(sizeof(SingleNodeList)))==NULL){
		exit(1);
	}
	(*head)->next=NULL;
}
int LinkedList_PushFront(SingleNodeList *head,ElemType x){//2单链表头插入 
	//(*head=(SingleNodeList *)malloc(sizeof(SingleNodeList)))==NULL
	SingleNodeList *q;
	//if((q=【		1	 	】)==NULL){
	if((q = (SingleNodeList *)malloc(sizeof(SingleNodeList)) )==NULL){ 
		exit(1);
	}
//	【		2	 	】
//【		3	 	】//头节点的数据域与指针域赋值 
//	【		4	 	】//头节点加入链表 
	q -> data = x ;
	q -> next = head -> next;
	
	head -> next = q;
	return 1;
} 
int LinkedList_PopFront(SingleNodeList *head,ElemType *x){//3单链表头删除 
	SingleNodeList *p=head,*q;
	if(p->next==NULL){
		printf("There is no data in the Linkedlist to delete.\n");
		*x = -12345;//未成功删除则在x指向单元赋特定值 
		return 0;
	}
	//【		5	 	】//请填写多行代码

	q = head -> next;
	*x = q -> data ; 
	p = q -> next;
	head -> next = p ;
	free(q);
} 
int LinkedListGet_current(SingleNodeList *p,ElemType *x){//4取当前指针指数据 
	//【		6	 	】=p->data;
	*x = p -> data;
	return 1;
}
int LinkedListUpdata_current(SingleNodeList *p,ElemType x){//5修改当前指针数据 
	//p->data=【		7	 	】;
	p -> data = x;
	return 1;
}
int LinkedListShow(SingleNodeList *head){//6打印单链表
	SingleNodeList *p=head;
	if(p->next==NULL){
		printf("There is no data in the Linkedlist to print.\n");
		return 0;
	} 
	while(p->next!=NULL){
		printf("%d ",p->next->data);
		p=p->next;
	}
	printf("\n");
	return 1;
}
void LinkedListDestroy(SingleNodeList **head){//7释放链表 
	SingleNodeList *p=*head,*q;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	*head=NULL;
}
int LinkedListLength(SingleNodeList *head){//8求单链表长度 
	SingleNodeList *p=head;
	int size=0;
	while(p->next!=NULL){
		size++;
		p=p->next;
	}
	return size;
}
int main(){
	SingleNodeList *head,*p;
	ElemType i,x;
	int switch_num;
	scanf("%d",&switch_num);
	switch(switch_num){
		case 1:
			LinkedListInit(&head);
			LinkedList_PushFront(head,1);
			LinkedList_PushFront(head,3);
			LinkedList_PushFront(head,2);
			LinkedListShow(head);
			break;
		case 2:
			LinkedListInit(&head);
			LinkedList_PushFront(head,11);
			LinkedList_PushFront(head,31);
			LinkedList_PushFront(head,22);
			for(i=1;i<=5;i++)
					LinkedList_PushFront(head,i);
			printf("%d\n",LinkedListLength(head));
			LinkedListShow(head);
			break;
		case 3: 
			LinkedListInit(&head);
			for(i=1;i<=5;i++)
					LinkedList_PushFront(head,i*i);
			for(i=1;i<=5;i++){
					LinkedList_PopFront(head,&x);
					printf("The %d PopFront delete  num = %d\n",i,x);
			}
			//LinkedListShow(head);
			break;
		case 4:
			LinkedListInit(&head);
			LinkedList_PushFront(head,11);
			LinkedList_PushFront(head,31);
			LinkedList_PushFront(head,22);
			for(i=1;i<=5;i++){
					LinkedList_PopFront(head,&x);
					printf("The %d PopFront delete  num = %d\n",i,x);
			}
			break;
		case 5:
			LinkedListInit(&head);
			for(i=1;i<=10;i++){
				LinkedList_PushFront(head,i);
			}
			LinkedListShow(head);
			p=head;
			for(i=1;i<=10;i=i++){
				p=p->next;
				if(i%2==0) LinkedListUpdata_current(p,i*i);
				else{
					LinkedListGet_current(p,&x);
					printf("The %d get Node is  %d\n",i,x);
				}
			}
			LinkedListShow(head);
			break;
  	}
  	LinkedListDestroy(&head);
  	return 0;
}

