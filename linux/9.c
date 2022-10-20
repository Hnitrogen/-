#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_huiwen(const char* str, int length)
{
    //str = str.substr(1,length-2)
    if(length <= 1)
        return 1;//递归基准出口 
    
    if(str[0] != str[length-1])
        return 0;//不是回文串 
    else
		return is_huiwen(substr(str,1,length-2),length-2);//递归调用 
}

// l eve l str.substr  
int main(){
	char str[80];
	gets(str);
	
	if(is_huiwen(str,strlen(str)))
		printf("YES");
	else
		printf("NO");
		
	return 0;
}
