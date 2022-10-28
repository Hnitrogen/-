#include <iostream>
#include <cstring>

using namespace std ;

const int N = 6 ;
char g[N][N] , backup[N][N] ;

int dx[]={-1,0,1,0,0} , dy[]={0,1,0,-1,0} ;

void turn(int x , int y)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        int a = x + dx[i] , b = y + dy[i] ;
        if(a < 0 || a >= 5 || b < 0 || b >= 5 ) continue ;
        g[a][b] ^= 1 ;
    }
}

int main()
{
    int t ;
    cin >> t ;
    
    while(t--)
    {
        for(int i = 0 ; i < 5 ; i++)
            scanf("%s",g[i]) ;
        // for(int i = 0 ; i < 5 ; i++)
        //     printf("%s\n",g[i]) ;
        
        //memcpy(g,backup,sizeof backup) ;
        int res = 10;
        for(int op = 0 ; op < 32 ; op ++)
        {
            memcpy(backup,g,sizeof g) ;
            // puts("");
            // for(int i = 0 ; i < 5 ; i++)
            // printf("%s\n",g[i]) ;
            
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
                        turn(i+1,j) ;
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
