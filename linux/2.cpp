#include <iostream>

using namespace std ;

int fiber(int u)
{
    if(u==0)    return 9;
    else return 10 * fiber(u-1) ;
}

int main()
{
	int n ;
	cin >> n ;
    if(n==1) {cout << 10 ; return 0;}

	int k = (n+1)/2 - 1 ;
	
	cout << fiber(k) << endl ;

	return 0;
}
