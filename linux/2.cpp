#include <iostream>

using namespace std;

int main()
{
	int n ;
	cin >> n ;

	if(n == 1) {cout << 10 ; return 0;}

	int res = 0 ;
	for(int i = 10 ; i < pow(10,n) ; i++)
	{
		int tmp = i ; int l , r ;
		while(tmp) {r++ ; tmp /= 10 ;} 

		int x = i ;
		bool flag = true;
		while(l <= r) 
		{

		}
	}
	
	res += 10 ;

	cout << res << endl ;

	return 0 ;
}
