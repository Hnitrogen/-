
#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
	string s ;
	cin >> s ;
	int n = s.size() ;

	reverse( s.begin(),s.end() );
	cout << s << endl;

	return 0;
}
