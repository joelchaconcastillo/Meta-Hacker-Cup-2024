#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
	long long n,k;
	cin>>n>>k;
	vector<long long> a(n);
	long long totalTime = 0;
	for(int i = 0 ; i < n; i++) cin>>a[i];
	sort(a.begin(), a.end());
	if(n==1) totalTime=a[0];
	else totalTime = (2LL*n-3LL)*a[0]; // --> 2(n-2)a_0+a_0=2na-4a+a=2na-3a=(2n-3)a
	cout << "Case #"<<t<<": ";
	if(totalTime<=k)
	cout << "YES";
	else cout <<"NO";
        cout <<endl;
   }
   return 0;
}
/*

 1  2  5
 l
       r
1+2*5+2*2 = 1+10+4

 * */
