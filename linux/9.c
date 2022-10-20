#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_huiwen(const char* str, int length)
{
    if(length == 1)
        return 1;//递归基准出口 
    
    if(str[strlen(str) - length] != str[length - 1])
        return 0;//不是回文串 
    else
        return is_huiwen(str,length-1);//递归调用 
}

int main(){
 char str[80];
 gets(str);
 
 if(is_huiwen(str,strlen(str)))
  printf("YES");
 else
  printf("NO");
  
 return 0;
}
