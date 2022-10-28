#include <iostream>
#include <cstring>

using namespace std ;

const int N = 6 ;
char g[N][N] , backup[N][N] ;

int main()
{
    int t ;
    cin >> t ;
    
    while(t--)
    {
        for(int i = 0 ; i < 5 ; i++)
            scanf("%s",backup[i]) ;
        
        memcpy(g,backup,sizeof backup) ;
        int res = 10;
        for(int op = 0 ; op < 32 ; op ++)
        {
            memcpy(g,backup,sizeof g) ;
            int cnt = 0 ;        
            for(int i = 0 ; i < 5 ; i++)
                if(op >> i & 1)
                {
                    turn(0,i) ;
                    cnt ++ ;
                }
            
            for(int i = 0 ; i < 4 ; i++)
                for(int j = 0 ; j < 5 ; j++)
                    if(g[i][j] == '0')
                    {
                        turn(i-1,j) ;
                        cnt ++ ;
                    }
            
            bool dark = false ;
            for(int i = 0 ; i < 5 ; i++)
                if(g[4][i] == '0')  {dark = true ; break ;}
            if(!dark)   res = min(res , cnt ) ;
            memcpy(g,backup,sizeof g) ;
        }
        
        if(res > 6) res = -1 ;
        cout << res << endl ;
    }

    return 0 ;
}
