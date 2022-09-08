#include <iostream>

using namespace std;

typedef pair<int,int> PII;

int n , m ;
const int N = 310;
char g[N][N];
PII q[N*N];
bool st[N][N];

int bfs(int xx , int yy )
{
    
}

int main()
{
    while(cin >> n >> m)
    {
        // ‰»Î
        for(int i = 0 ; i < n ; i++)    scanf("%s",g[i]);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(g[i][j] == '@')
                    int sx = i , sy = j ;
            }
        }

        for(int i = 0 ; i < n ; i++)
        {

        }


    }

    cout << cnt << endl;

    return 0 ;
}