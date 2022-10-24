#include <stdio.h>
#include <string.h>

struct person{
	int number;
	char ch;
};

int main(){
	char str[20]="1level1";
	struct person persons[100];
	int i,n,m,count=0,k;
	
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++) {
		persons[i].number=i+1;
		persons[i].ch='*';
	}
	
	i=0;//i为每次循环的计数变量
	k=0;//k为1，2，3...计数的变量；
	count=0;//退出者的计数变量 
	
	//printf("%d\n" , m );
	
	while(count < strlen(str) )  {
		if(persons[i].ch=='*')k++;//此位置之人没有退出
		if(k==m){//报数为m的人做以下处理
			//[textArea=3,20]
			persons[i].ch = str[count]; 
		    count++ ;
		    k = 0 ; 
		} 
		i++;
		if(i == n) i = 0 ;
	}

	for(i=0;i<n;i++) {
// 		if([textArea=1,20]!='*')
        if(persons[i].ch != '*')
			printf("%d %c \n",persons[i].number,persons[i].ch);
	}
	
	return 0 ;
}
