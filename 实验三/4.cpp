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
int LinkedList_PushBack(SingleNodeList *head,ElemType x){//4������β���� 
	SingleNodeList *p=head,*q;
	while(p->next!=NULL)
		p=p->next;
	if((q=(SingleNodeList *)malloc(sizeof(SingleNodeList)))==NULL){ 
		exit(1);
	}
	q->data=x;q->next=NULL; //β�ڵ����������ָ����ֵ 
	p->next=q;//β�ڵ�������� 
	return 1;
} 
int LinkedListGetMid(SingleNodeList *head,ElemType *x){//5ȡ�������м�����ݣ�����xָ�� 
	//��		1	 	��//��������д���
    int len = LinkedListLength(head);
    //printf("%d",len);

    for(int i = 0 ; i < len/2 ; i++)    //��������,һ�α���
        head = head -> next;

    *x = head -> data ;
}   
int LinkedListGetLastofN(SingleNodeList *head,int n,ElemType *x){//6ȡ����������n���ڵ����ݣ�����xָ�� 
	SingleNodeList *fast,*slow;
	int j=0;
	fast=slow=head;

    while(fast->next!=NULL){
	//	��		2	 	��//��������д���
        for(int i = 0; i < n -1&& j == 0; i++)  //��ǰԤ����
            fast = fast -> next;

        fast = fast -> next;
        slow = slow -> next;
        j++;
	} 

    printf("%d\n",j);
	if(j<n)	*x=-12345;
	else	*x=slow->data;
	return 1; 
}

int LinkedListReversal(SingleNodeList *head,int n){//7������תn��ѭ��ǰ��nλ�� 
	SingleNodeList *fast,*slow;
	int j=0;
	fast=slow=head;
	
    
    while(fast->next!=NULL){
	//	��		3	 	��//��������д���	    
    for(int i = 0 ; i < n - 1&& j == 0 ; i++)   //ͬ��
        fast = fast -> next;

    fast = fast -> next;
    slow = slow -> next;    
    j++;
} 
	fast->next=head->next;
	head->next=slow->next;  //swap����
	slow->next=NULL;
	return 0; 
}
// ѭ������ 
//1���ж�ĳ��ͷ�ڵ㵥�����Ƿ�Ϊѭ������
//2�������ѭ������������ĳ���
//3������������
//4����ѭ�����������һ��������
int Is_circular_linked_list(SingleNodeList *head,ElemType *x){//8�ж��Ƿ�Ϊѭ������ �����򷵻�1�����򷵻�0
 	//��		4	 	��//��������д���
    SingleNodeList *fast,*slow;
    fast = head , slow = head ;
    
    do{
        fast = fast -> next;
        fast = fast -> next;

        slow = slow -> next;
    }while(fast != slow);

    if(fast == NULL && slow == NULL)    return 0;
    else return 1 ;
}

int LinkedListShow_N(SingleNodeList *head,int n){//9��ӡ������ǰn���ڵ� 
	SingleNodeList *p=head;
	int i=0;
	if(p->next==NULL){
		printf("There is no data in the Linkedlist to print.\n");
		return 0;
	} 
	//��		5	 	��//��������д���	
    p = head -> next;

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",p->data);      //�⴫�β�����
        p = p -> next;
        if(p == NULL)  break;
    }

// printf("\n");    //������ûس�
	return 1;
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

int main()
{
	SingleNodeList *head,*p,*q;
	ElemType i,x;
	int switch_num;
	LinkedListInit(&head);
	scanf("%d",&switch_num);
	for(i=1;i<=20;i++)
		LinkedList_PushBack(head,i);
	printf("%d\n",LinkedListLength(head));
	LinkedListShow(head);
	switch(switch_num){
		case 1:
				LinkedListGetMid(head,&x);
				printf("The mid of list is= %d\n",x);
				break;	
		case 2: LinkedListGetLastofN(head,5,&x);
				printf("The last of 5 in  list is= %d\n",x);
				break;
		case 3:
				LinkedListReversal(head,5);
				LinkedListShow(head);
				//printf("The last of 5 in  list is= %d\n",x);
				break;
		case 4: 
		        i=0;p=head;
			    while(p->next!=NULL ){
			    	p=p->next;
			    	i++;
			    	if(i<=8) q=p;
			    }
			    p->next=q;
			    LinkedListShow_N(head,30);  //�������50
			    printf("\n");
			    i=Is_circular_linked_list(head,&x);
                printf("%d\n",i);
			    
                printf("The circular_linked_list'length is= %d\n",i);
			    printf("The circular_linked_list start at node = %d\n",x);
			    //LinkedListShow(head);     //�ϻ�
			    break;
		case 5:	
				i=Is_circular_linked_list(head,&x);
			    printf("The circular_linked_list'length is= %d\n",i);
			    printf("The circular_linked_list start at node = %d\n",x);
			    LinkedListShow(head);
			    break;			
	}
	LinkedListDestroy(&head);
	return 0;			
}