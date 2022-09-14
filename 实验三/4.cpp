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
int LinkedListLength(SingleNodeList *head){//2求单链表长度 
	SingleNodeList *p=head;
	int size=0;
	while(p->next!=NULL){
		size++;
		p=p->next;
	}
	return size;
}
int LinkedListShow(SingleNodeList *head){//3打印单链表
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
int LinkedList_PushBack(SingleNodeList *head,ElemType x){//4单链表尾插入 
	SingleNodeList *p=head,*q;
	while(p->next!=NULL)
		p=p->next;
	if((q=(SingleNodeList *)malloc(sizeof(SingleNodeList)))==NULL){ 
		exit(1);
	}
	q->data=x;q->next=NULL; //尾节点的数据域与指针域赋值 
	p->next=q;//尾节点加入链表 
	return 1;
} 
int LinkedListGetMid(SingleNodeList *head,ElemType *x){//5取单链表中间的数据，存入x指针 
	//【		1	 	】//请填入多行代码
    int len = LinkedListLength(head);
    //printf("%d",len);

    for(int i = 0 ; i < len/2 ; i++)    //求链表长度,一次遍历
        head = head -> next;

    *x = head -> data ;
}   
int LinkedListGetLastofN(SingleNodeList *head,int n,ElemType *x){//6取单链表倒数第n个节点数据，存入x指针 
	SingleNodeList *fast,*slow;
	int j=0;
	fast=slow=head;

    while(fast->next!=NULL){
	//	【		2	 	】//请填入多行代码
        for(int i = 0; i < n -1&& j == 0; i++)  //超前预处理
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

int LinkedListReversal(SingleNodeList *head,int n){//7单链表翻转n（循环前移n位） 
	SingleNodeList *fast,*slow;
	int j=0;
	fast=slow=head;
	
    
    while(fast->next!=NULL){
	//	【		3	 	】//请填入多行代码	    
    for(int i = 0 ; i < n - 1&& j == 0 ; i++)   //同理
        fast = fast -> next;

    fast = fast -> next;
    slow = slow -> next;    
    j++;
} 
	fast->next=head->next;
	head->next=slow->next;  //swap罢了
	slow->next=NULL;
	return 0; 
}
// 循环链表 
//1》判断某有头节点单链表是否为循环链表
//2》如果是循环链表，求出环的长度
//3》求出环的起点
//4》将循环链表断链成一个单链表
int Is_circular_linked_list(SingleNodeList *head,ElemType *x){//8判断是否为循环链表 ，是则返回1，否则返回0
 	//【		4	 	】//请填入多行代码
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

int LinkedListShow_N(SingleNodeList *head,int n){//9打印单链表前n个节点 
	SingleNodeList *p=head;
	int i=0;
	if(p->next==NULL){
		printf("There is no data in the Linkedlist to print.\n");
		return 0;
	} 
	//【		5	 	】//请填入多行代码	
    p = head -> next;

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",p->data);      //这传参不合理
        p = p -> next;
        if(p == NULL)  break;
    }

// printf("\n");    //这里最好回车
	return 1;
}
void LinkedListDestroy(SingleNodeList **head){//10释放链表 
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
			    LinkedListShow_N(head,30);  //这最好是50
			    printf("\n");
			    i=Is_circular_linked_list(head,&x);
                printf("%d\n",i);
			    
                printf("The circular_linked_list'length is= %d\n",i);
			    printf("The circular_linked_list start at node = %d\n",x);
			    //LinkedListShow(head);     //断环
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