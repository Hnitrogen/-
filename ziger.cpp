#include <iostream>

using namespace std;

const int N = 10;
int g[N][N];

int main()
{
    int n  = 5;
    //cin >> n ;

    int x = 0 , y = 0 ;
    for(int i = 1; i < n * n ; i++)
    {
        g[x][y] = i ; 

    }


    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
               cout << g[i][j] <<' '; 
        
        cout << endl;
    }

    return 0;
}