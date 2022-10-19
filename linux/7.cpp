#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std ;

typedef long long LL ;
long long sqs[10] ;

string tricat(string a , string b , string c)
{
    string res ;
    res += a ; res += b ; res += c;
    
    return res ;
}

string scmp(string a , string b)
{
    int len = a.size() ;
    
    for(int i = 0 ; i < len ; i ++)
    {
        int num1 = a[i]-'0' , num2 = b[i]-'0';
        if(num1 > num2) return a ;
        else if(num1 < num2) return b ;
    }
    
    return a ;
} 

int main()
{
        string s[10] ; 
        cin >> s[1] >> s[2] >> s[3] ;
        
        string ans = tricat(s[1],s[2],s[3]);
        
        ans = scmp(ans,tricat(s[1],s[2],s[3]));
        ans = scmp(ans,tricat(s[1],s[3],s[2]));
        ans = scmp(ans,tricat(s[2],s[1],s[3]));
        ans = scmp(ans,tricat(s[2],s[3],s[1]));
        ans = scmp(ans,tricat(s[3],s[2],s[1]));
        ans = scmp(ans,tricat(s[3],s[1],s[2]));
        
        
        cout << ans << endl ;
        return 0;
}
