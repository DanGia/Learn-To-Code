#include <bits/stdc++.h>
using namespace std;
void changeValue(int x)
{
	x = 2;
}
void passbyRef(int &x){
    x = 2;
}
int main()
{
	int x = 0;
	changeValue(x);
	cout<<x;

    passbyRef(x);
    cout << x;
	return 0;
}	