
#include <iostream>

using namespace std ;

int a[1010] ;
int ans[1010] ;

void rev(int f , int l)
{
	if(f == -1)	return ;
	
	ans[l] = a[f] ;
	rev(f-1,l+1) ;
}

int main()
{
	int n ;
	cin >> n ;

	for(int i = 0 ; i < n ; i++)	cin >> a[i] ;
	rev(n-1,0);
	
	for(int i = 0 ; i < n ; i++) cout << ans[i] <<' ' ;

	return 0;
}
