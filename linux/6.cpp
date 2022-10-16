
#include <iostream>

using namespace std; 

int fiber(int n)
{
	if(n == 1 ) return 1 ;
	else if(n == 2 ) return 2 ;
	else return fiber(n-1) + fiber(n-2) ;
}

int main()
{
	int n ;
	cin >> n ;

	cout << fiber(n) << endl ;

	return 0;
}
