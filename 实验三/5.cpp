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
int LinkedList_PushBack(SingleNodeList *head,ElemType x){//2单链表尾插入 
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
void LinkedListDestroy(SingleNodeList **head){//4释放链表 
	SingleNodeList *p=*head,*q;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	*head=NULL;
}
//此函数完成如下功能
//1》输入一行数据，例如 1 3 5 7 9 8 6 4 2 将这些数据组织成一个有头节点的单链表A，首元素
//为1. A链表： head(A)->1->3->5->7->9->8->6->4->2
//2》输入一个数X，例如X=5.5，将A链表分成B和C两个部分，B中节点值比X小，C中节点都比X大
//如：A将分解成B与C链表：head(B)->1->3->5->4->2   head(C)->6->8->9->7
//请注意B、C链表中元素在原链表A中的次序。
//3》将B与C合并，并用A表头指向之。如 head(A)->1->3->5->4->2->6->8->9->7
int LinkedList_Divide(SingleNodeList *head,ElemType x) {//5单链表的划分 
	//【		1	 	】//请填入多行代码
    int nums[9]={0} , t = 0 ;
    while(head != NULL)
    {
        nums[t++] = head -> data ;
        head = head -> next ;
    }
    for(int i = 1 ; i <= 9; i++)    
        printf("%d ",nums[i]);
    puts("");

    int h1[9] = {0} , h2[9]={0};
    int hh = 0 , tt = 0 ;

    for(int i = 0 ,j = 9; i < 9 ; i++,j--)
    {
        if(nums[i] <= x)   h1[hh++] = nums[i];
        if(nums[j] > x)   h2[tt++] = nums[j];
    }
    for(int i = 0 ; i < 9; i++)    
        printf("%d ",h1[i]);

    puts("");    
    for(int i = 0; i < 9; i++)    
        printf("%d ",h2[i]);
    int res[9];
    
    return 0 ;
}
// int LinkedList_Add(SingleNodeList *head,ElemType x1,ElemType x2){
// 	//6两数转换成链表结构后相加  
// 	//【		2	 	】//请填入多行代码
// }
// int LinkedList_Rever(SingleNodeList *head){//7原地逆置 
// 	Linklist pre=NULL,next=NULL,p;
// 	p=head->next;
// 	//p是当前节点，pre是p的直接前驱，next是p的后继 
// 	while(p!=NULL){
// 	//	【		3	 	】//请填入多行代码	
// }
// 	head->next=pre;
// 	return 0;
// }
// //P1单链表11->23->35->47->59
// //P1单链表8->36->44->52
// //合并后P1单链表8->11->23->35->35->44->47->52->59 
// int LinkedList_MergingSort(Linklist p1,Linklist p2){//8p1与p2归并排序，并链接至p1的头节点 
// 	//【		4	 	】//请填入多行代码	
// } 
// //如一个链表为 36 -> 37 -> 65 -> 76 -> 97 -> 98 -> 98 -> 98 -> 98 -> 98 
// //删除重复元素后为: 36 -> 37 -> 65 -> 76 -> 97 -> 98
// int LinkedList_Sorted_Delete(Linklist head) {//9删除有序链表中所有重复元素
// 	Linklist curr=head->next,temp;
// 	while(curr->next!=NULL){
// 	//	【		5	 	】//请填入多行代码	
// 	}
// }
// //10判断两个有头节点单链表是否相交，如果相交，将交点的数据域带回，否则带回-12345 

// int LinkedList_Is_Intersect(Linklist p1,Linklist p2,ElemType *x){
// 	//【		6	 	】//请填入多行代码	
// }


int main(){
	SingleNodeList *head,*p,*q;
	Linklist p1,p2;
	ElemType i,x,x1,x2;
	int switch_num;
	scanf("%d",&switch_num);
	switch(switch_num){
		case 1:
				LinkedListInit(&head);
				LinkedList_PushBack(head,1);
				LinkedList_PushBack(head,3);
				LinkedList_PushBack(head,5);
				LinkedList_PushBack(head,7);
				LinkedList_PushBack(head,9);
				LinkedList_PushBack(head,8);
				LinkedList_PushBack(head,6);
				LinkedList_PushBack(head,4);
				LinkedList_PushBack(head,2);
				LinkedListShow(head);	
				LinkedList_Divide(head,5);
				//LinkedListShow(head); 
				break;
		// case 2:
		// 		LinkedListInit(&head);
		// 		LinkedList_Add(head,12345,5678999);
		// 		LinkedListShow(head); 
		// 		LinkedList_Rever(head);
		// 		LinkedListShow(head); 
		// 		break;
		// case 3:
		//         LinkedListInit(&head);
		// 		LinkedList_PushBack(head,1);
		// 		LinkedList_PushBack(head,3);
		// 		LinkedList_PushBack(head,5);
		// 		LinkedList_PushBack(head,7);
		// 		LinkedList_PushBack(head,9);
		// 		LinkedList_PushBack(head,8);
		// 		LinkedList_PushBack(head,6);
		// 		LinkedList_PushBack(head,4);
		// 		LinkedList_PushBack(head,2);
		// 		LinkedListShow(head);
		// 		LinkedList_Rever(head);		
		// 		LinkedListShow(head); 
		// 		break;
		// case 4:
		// 	    LinkedListInit(&p1);
		// 	    LinkedListInit(&p2);
		// 		LinkedList_PushBack(p1,11);
		// 		LinkedList_PushBack(p1,23);
		// 		LinkedList_PushBack(p1,35);
		// 		LinkedList_PushBack(p1,47);
		// 		LinkedList_PushBack(p1,59);
		// 		LinkedListShow(p1); 				
		// 		LinkedList_PushBack(p2,8);
		// 		LinkedList_PushBack(p2,36);
		// 		LinkedList_PushBack(p2,44);
		// 		LinkedList_PushBack(p2,52);
		// 		LinkedListShow(p2); 		
		// 		LinkedList_MergingSort(p1,p2);
		// 		LinkedListShow(p1); 			
		// 		break;
		// case 5:
		// 	    LinkedListInit(&head);
		// 		LinkedList_PushBack(head,1);
		// 		LinkedList_PushBack(head,1);
		// 		LinkedList_PushBack(head,1);
		// 		LinkedList_PushBack(head,1);
		// 		LinkedList_PushBack(head,1);
		// 		LinkedList_PushBack(head,3);
		// 		LinkedList_PushBack(head,3);
		// 		LinkedList_PushBack(head,3);
		// 		LinkedList_PushBack(head,19);
		// 		LinkedList_PushBack(head,19);
		// 		LinkedList_PushBack(head,26);
		// 		LinkedList_PushBack(head,34);
		// 		LinkedList_PushBack(head,34);
		// 		LinkedList_PushBack(head,34);
		// 		LinkedList_PushBack(head,54);
		// 		LinkedListShow(head);
		// 		LinkedList_Sorted_Delete(head);
		// 		LinkedListShow(head);
		// 		break;
		// case 6:
		// 	    LinkedListInit(&head);
		// 		LinkedList_PushBack(head,1);
		// 		LinkedList_PushBack(head,3);
		// 		LinkedList_PushBack(head,5);
		// 		LinkedList_PushBack(head,7);
		// 		LinkedList_PushBack(head,9);
		// 		LinkedList_PushBack(head,8);
		// 		LinkedList_PushBack(head,6);
		// 		LinkedList_PushBack(head,4);
		// 		LinkedList_PushBack(head,2);
		// 		LinkedListShow(head);
		// 		LinkedListInit(&p1);
		// 	    LinkedListInit(&p2);
		// 		LinkedList_PushBack(p1,11);
		// 		LinkedList_PushBack(p1,23);
		// 		LinkedList_PushBack(p1,35);
		// 		LinkedList_PushBack(p1,47);
		// 		LinkedList_PushBack(p1,59);
		// 		p=p1;
		// 		while(p->next!=NULL)
		// 			p=p->next;
		// 		p->next=head->next;
		// 		LinkedListShow(p1); 
		// 		LinkedList_PushBack(p2,8);
		// 		LinkedList_PushBack(p2,36);
		// 		LinkedList_PushBack(p2,44);
		// 		LinkedList_PushBack(p2,52);
		// 		p=p2;
		// 		while(p->next!=NULL)
		// 			p=p->next;
		// 		p->next=head->next;
		// 		LinkedListShow(p2); 
				
		// 	    LinkedList_Is_Intersect(p1,p2,&x);
		// 	    printf("The intersect node  num = %d\n",x);
	}		    
	//LinkedListDestroy(&head);
	return 0;
}