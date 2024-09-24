#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
      long long n, g; cin>>n>>g;
      vector<long long>stones(n);
      for(int i = 0 ;i < n; i++){
	      cin>>stones[i];
      }
      sort(stones.begin(), stones.end());
      pair<long long, long long> res(INT_MIN,INT_MIN);
      for(int i = 0 ; i < n; i++){
	 res = max(res, {-abs(g-stones[i]), i});
      }
      cout << "Case #"<<t<<": ";
      cout << n-res.second << " "<< -res.first <<endl;

   }
   return 0;
}
/*
    3 1
    9 5 7
    0 1 2 3 4 5 6 7 8 9
        0  
		  5 7 9
		  2 1 0

		  6 7 8 9
		  0 1 2 3

		  1 3 5
		     4
 * */
