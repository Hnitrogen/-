#include <iostream>
#include <stack>

typedef pair<int,int> PII;

using namespace std;

int main()
{
    stack<int> maj , sub;

    int n ;
    cin >> n ;

    for(int i = 0 ; i < n ; i++)
    {
        int x ;
        cin >> x ;

        if(maj.empty || x > maj.top())
        {
            maj.push({x,1});
            cout << 0 << ' ' ;
        }
        else
        {
            while(!maj.empty())
            {
                auto high = maj.top();
                maj.pop();

                int num = high.first , total = high.second;
                if(x == num)
                    total++;
            }
        }
    }   
}