// 最后一组样例? 
#include <stdio.h>
#define Maxn 10001

int main()
{	int flag=0;
	int i,n,a[Maxn],left,right,ans=0;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	left=1; right=n;		
	while(left<right)
	{
		if(a[left] == a[right])
		{
			if(left+1==right || left+2==right){//成功得到回文数组 
				//[textArea=2,20] 
				flag = 1 ;
			}
			left++; right--;//left和right指针的移动 
		}
		else if(a[left] > a[right]) //右部做操作 1 6 4 2 1
		{
			a[right-1] += a[right]; 
			right--;
			ans++;
		}
		else//左部做操作 
		{
			//[textArea=3,20]
			a[left+1] += a[left] ;
			left ++ ;
			ans++;
		}
	}
	
	if(flag==0) ans=-1;
	printf("%d\n",ans);
	return 0;
}
