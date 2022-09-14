#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int ElemType;
typedef struct SingleNode{
	ElemType data;
	struct SingleNode *next;
}SingleNodeList,*Linklist;
void LinkedListInit(SingleNodeList **head){//1��ʼ����ͷ�ڵ�ĵ����� 
    Linklist p; 
	if((*head=(SingleNodeList *)malloc(sizeof(SingleNodeList)))==NULL){
		exit(1);
	}
	(*head)->next=NULL;
}
int LinkedListLength(SingleNodeList *head){//2�������� 
	SingleNodeList *p=head;
	int size=0;
	while(p->next!=NULL){
		size++;
		p=p->next;
	}
	return size;
}
int LinkedListShow(SingleNodeList *head){//3��ӡ������
	SingleNodeList *p=head;
	//ElemType x;
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
int LinkedListInsert(SingleNodeList *head,int i,ElemType x){//4��ai��0<=i<=size��ǰ����ڵ� 
	//��		1	 	��//����д���д���
	SingleNodeList *p ;
		//malloc�жϣ� 
		if((p = (SingleNodeList *)malloc(sizeof(SingleNodeList)) )==NULL){ 
		exit(1);
	}
	
	p -> data = x;
	p -> next = head -> next;
	
	head -> next = p ;
	return 1;
}
int LinkedListDelete(SingleNodeList *head,int i,ElemType *x) {//5ɾ��iλ�ã�0<=i<=size��ǰ�ڵ� 
	SingleNodeList *p=head,*q;
	int j=-1;
	while(p->next!=NULL && p->next->next!=NULL && j<i-1){
		p=p->next;j++;
	}
	if(j!=i-1){
		printf("The location parameter of the delete node is wrong.");
		return	0;
	}
	//��		2	 	��//����д���д���
	free(q);
	return 1;
}
int LinkedListInsert_Order(SingleNodeList *head,ElemType x){//6�������x 
	SingleNodeList *pre,*curr,*q;
	int j=-1;
	pre=head;
	curr=head->next;
	while(curr!=NULL && curr->data<=x){
	//	��		3	 	��//����д���д���
	
	} 
	if((q=(SingleNodeList *)malloc(sizeof(SingleNodeList)))==NULL){
		exit(1);
	}
	q->data=x;
	//��		4	 	��;//��ֵq->next 
	//��		5	 	��; //������p->next 
	return 1;
}
int LinkedListDelete_Order(SingleNodeList *head,ElemType x) {//7ɾ����һ��ֵΪx�Ľڵ� 
	SingleNodeList *p=head,*q;
	while(p->next!=NULL && p->next->data!=x){
		p=p->next;
	}
	if(p->next==NULL){
		printf("There is no node %d to delete.\n",x);return -1;
	}	
	//��		6	 	��//����д���д���
	head -> next = p ;
	 
	
	free(q);
	return 1;
}
int LinkedListDelete_All(SingleNodeList *head,ElemType x) {//8ɾ������ֵΪx�Ľڵ� 
	//��p��ͷ��βɨ�赥����preָ��*p�ڵ��ǰ������p��ָ�ڵ�ֵΪx����ɾ��������p
	//������һ���ڵ㣬������pre��pָ��ͬ������һ���ڵ㡣 
	SingleNodeList *p=head->next,*pre=head,*q;
	int j=0;
	while(p!=NULL){
		if(p->data==x) {
			//��		7	 	��
		}
		else{//ͬ������ 
			pre=p;
			p=p->next;
		}	
	}
	if(j==0)
		printf("There is no node %d to delete.\n",x);
	else 
		printf("There is  %d node deleted.\n",j);
	return 1;
}
int LinkedListGet(SingleNodeList *head,int i,ElemType *x){//9ȡ�������i���ڵ�����ݣ�����xָ�� 
	//��		9	 	��
}
void LinkedListDestroy(SingleNodeList **head){//10�ͷ����� 
	SingleNodeList *p=*head,*q;
	while(p!=NULL){
		q=p;
		p=p->next;
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
			   for(i=1;i<=10;i++)
			   		LinkedListInsert(head,0,i);
			   printf("%d\n",LinkedListLength(head));
			   LinkedListShow(head);
			   break;
		case 2:
			   LinkedListInit(&head);
			   for(i=1;i<=10;i++)
			   		LinkedListInsert(head,0,i);
			   printf("%d\n",LinkedListLength(head));
			   LinkedListShow(head);
			   
			   for(i=1;i<=3;i++)
			   		LinkedListDelete(head,i,&x);
			   printf("%d\n",LinkedListLength(head));
			   LinkedListShow(head);
		       break;
		case 3:
			   LinkedListInit(&head);
			   for(i=1;i<=8;i++){
			   	     scanf("%d",&x);
					 LinkedListInsert_Order(head,x);	
			   }
			   printf("%d\n",LinkedListLength(head));
			   LinkedListShow(head);
			   break;
		case 4:
			   LinkedListInit(&head);
			   for(i=1;i<=5;i++){
			   	     scanf("%d",&x);
					 LinkedListInsert(head,0,x);	
			   }
			   LinkedListShow(head);
			   
			   scanf("%d",&x);
			   LinkedListDelete_Order(head,x); 
			   printf("%d\n",LinkedListLength(head));
			   LinkedListShow(head);
			   break;
		case 5:
			   LinkedListInit(&head);
			   for(i=1;i<=5;i++){
			   	     scanf("%d",&x);
					 LinkedListInsert(head,0,x);	
			   }
			   LinkedListShow(head);
			   
			   scanf("%d",&x);
			   LinkedListDelete_All(head,x); 
			   printf("%d\n",LinkedListLength(head));
			   LinkedListShow(head);
			   break;
	} 
	return 0;
}

