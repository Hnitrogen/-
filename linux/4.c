#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n ;
    scanf("%d",&n) ;
    int nums[1010] ; 
    
    for(int i = n - 1 ; i >= 0 ; i --)
        scanf("%d",&nums[i]) ;
    
    for(int i = 0 ; i < n ; i++)
        printf("%d ",nums[i]) ;
    
    return 0 ;
}
