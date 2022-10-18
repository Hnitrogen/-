#include <stdio.h>

#define N 100010

void * cat(char *s, char *t)
{
    int i , j ;

    while(s[i] != '\0') i++; 

    for(int j = 0 ; t[j] != '\0' ; j++)
    {
        s[i] = t[j];
        i++;
    }  
    s[i] = '\0';
}

int main()
{
    char s1[N] ,s2[N] ;
    scanf("%s%s",s1,s2);
    
    cat(s1,s2);
    printf("%s",s1);

    return 0 ;
}
