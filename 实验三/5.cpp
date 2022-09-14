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
int LinkedList_PushBack(SingleNodeList *head,ElemType x){//2������β���� 
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
void LinkedListDestroy(SingleNodeList **head){//4�ͷ����� 
	SingleNodeList *p=*head,*q;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	*head=NULL;
}
//�˺���������¹���
//1������һ�����ݣ����� 1 3 5 7 9 8 6 4 2 ����Щ������֯��һ����ͷ�ڵ�ĵ�����A����Ԫ��
//Ϊ1. A���� head(A)->1->3->5->7->9->8->6->4->2
//2������һ����X������X=5.5����A����ֳ�B��C�������֣�B�нڵ�ֵ��XС��C�нڵ㶼��X��
//�磺A���ֽ��B��C����head(B)->1->3->5->4->2   head(C)->6->8->9->7
//��ע��B��C������Ԫ����ԭ����A�еĴ���
//3����B��C�ϲ�������A��ͷָ��֮���� head(A)->1->3->5->4->2->6->8->9->7
int LinkedList_Divide(SingleNodeList *head,ElemType x) {//5������Ļ��� 
	//��		1	 	��//��������д���
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
// 	//6����ת��������ṹ�����  
// 	//��		2	 	��//��������д���
// }
// int LinkedList_Rever(SingleNodeList *head){//7ԭ������ 
// 	Linklist pre=NULL,next=NULL,p;
// 	p=head->next;
// 	//p�ǵ�ǰ�ڵ㣬pre��p��ֱ��ǰ����next��p�ĺ�� 
// 	while(p!=NULL){
// 	//	��		3	 	��//��������д���	
// }
// 	head->next=pre;
// 	return 0;
// }
// //P1������11->23->35->47->59
// //P1������8->36->44->52
// //�ϲ���P1������8->11->23->35->35->44->47->52->59 
// int LinkedList_MergingSort(Linklist p1,Linklist p2){//8p1��p2�鲢���򣬲�������p1��ͷ�ڵ� 
// 	//��		4	 	��//��������д���	
// } 
// //��һ������Ϊ 36 -> 37 -> 65 -> 76 -> 97 -> 98 -> 98 -> 98 -> 98 -> 98 
// //ɾ���ظ�Ԫ�غ�Ϊ: 36 -> 37 -> 65 -> 76 -> 97 -> 98
// int LinkedList_Sorted_Delete(Linklist head) {//9ɾ�����������������ظ�Ԫ��
// 	Linklist curr=head->next,temp;
// 	while(curr->next!=NULL){
// 	//	��		5	 	��//��������д���	
// 	}
// }
// //10�ж�������ͷ�ڵ㵥�����Ƿ��ཻ������ཻ�����������������أ��������-12345 

// int LinkedList_Is_Intersect(Linklist p1,Linklist p2,ElemType *x){
// 	//��		6	 	��//��������д���	
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