#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct SingleNode{
	ElemType data;	// val  
	struct SingleNode *next;	//nextָ�� 
}SingleNodeList,*Linklist;
void LinkedListInit(SingleNodeList **head){//1��ʼ����ͷ�ڵ�ĵ����� 
    Linklist p; 
	if((*head=(SingleNodeList *)malloc(sizeof(SingleNodeList)))==NULL){
		exit(1);
	}
	(*head)->next=NULL;
}
int LinkedList_PushBack(SingleNodeList *head,ElemType x){//2������β���� 
	SingleNodeList *p=head,*q;	// p = q = head 
	while(p->next!=NULL)
		p=p->next;
	if((q=(SingleNodeList *)malloc(sizeof(SingleNodeList)))==NULL){ 
		exit(1);
	}
	
	q->data=x;
	q->next=NULL; //β�ڵ����������ָ����ֵ 
	//��		1	 	��;//β�ڵ��������
	while(p->next != NULL)
		p = p -> next;
	p -> next = q ;
	
	return 1;
} 
int LinkedList_PopBack(SingleNodeList *head,ElemType *x){//3������βɾ�� 
	SingleNodeList *p=head,*q;
	if(p->next==NULL){
		printf("There is no data in the Linkedlist to delete.\n");
		*x = -12345;//δ�ɹ�ɾ������xָ��Ԫ���ض�ֵ 
		return 0;
	} 
	while(p->next!=NULL){
		q=p;
		p=p->next;
	}//p��β�ڵ㣬q��p��ֱ��ǰ�� 
	//��		2	 	�� ;//��ֵq��ָ����
	q -> next = NULL;
	*x=p->data;
	free(p);//�ͷ�p
	return 1;
} 
int LinkedListLength(SingleNodeList *head){//4�������� 
	SingleNodeList *p=head;
	int size=0;
	while(p->next!=NULL){
	//��		3	 	��;
	size++;
	p=p->next;
	//��		4	 	��; 
	}
	return size;
}
int LinkedListShow(SingleNodeList *head){//5��ӡ������
	SingleNodeList *p=head;
	if(p->next==NULL){
		printf("There is no data in the Linkedlist to print.\n");
		return 0;
	} 
	//while()
	while(p != NULL){ 
		printf("%d ",p->next->data);
		p=p->next;
	}
	printf("\n");
	return 1;
}
void LinkedListDestroy(SingleNodeList **head){//6�ͷ����� 
	SingleNodeList *p=*head,*q;
	while(p!=NULL){
	//��		6	 	��;
	p = p -> next; 
	//��		7	 	��; 
	
		free(q);
	}
	*head=NULL;
}
int main(){
	SingleNodeList *head;
	ElemType i,x;
	int switch_num;
	scanf("%d",&switch_num);
	switch(switch_num){
		case 1:
			LinkedListInit(&head);
			LinkedList_PushBack(head,1);
			LinkedList_PushBack(head,3);
			LinkedList_PushBack(head,2);
			printf("%d\n",LinkedListLength(head));
			LinkedListShow(head);
			break;
		case 2:
			LinkedListInit(&head);
			LinkedList_PushBack(head,11);
			LinkedList_PushBack(head,31);
			LinkedList_PushBack(head,22);
			for(i=1;i<=5;i++)
					LinkedList_PushBack(head,i);
			printf("%d\n",LinkedListLength(head));
			LinkedListShow(head);
			break;
		case 3: 
			LinkedListInit(&head);
			for(i=1;i<=5;i++)
					LinkedList_PushBack(head,i*i);
			for(i=1;i<=5;i++){
					LinkedList_PopBack(head,&x);
					printf("The %d PopBack delete  num = %d\n",i,x);
			}
			break;
		case 4:
			LinkedListInit(&head);
			LinkedList_PushBack(head,11);
			LinkedList_PushBack(head,31);
			LinkedList_PushBack(head,22);
			for(i=1;i<=5;i++){
					LinkedList_PopBack(head,&x);
					printf("The %d PopBack delete  num = %d\n",i,x);
			}
			break;
		case 5:
			LinkedListInit(&head);
			LinkedList_PopBack(head,&x);
			printf("%d\n",LinkedListLength(head));
			LinkedListShow(head);
			break;
  	}
  	LinkedListDestroy(&head);
  	return 0;
}

