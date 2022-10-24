#include <math.h>
#include <string.h>
#include <stdio.h>

char *clean(char *s){
	char *p,*q;
	p=q=s;
	while(*p!='\0'){
		if(*p>='a' && *p<='z')
			*q++=*p;//保存小写字符
		else if(*p>='A' && *p<='Z')
			*q++=*p;    //[textArea=1,20];
            //将P指针指向的内容转换为小写并保存于q指针指向的存储单元
		else if(*p>='0' && *p<='9')
			*q++=*p;    //[textArea=1,20];//保存数字字符
			
		p++;       
	}
	*q='\0';
	
	return s;
}

int main()
{
	char str[80],*p;
	gets(str);
	//[textArea=1,10];//注意指针变量p的使用
	p = clean(str) ;
	
	puts(p);
	return 0;
}
