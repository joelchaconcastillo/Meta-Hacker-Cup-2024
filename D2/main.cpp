#include <bits/stdc++.h>
#define MAX_N 2000000
using namespace std;
int main(){
   int T;
   cin>> T;
   for(int t = 1; t <=T; t++){
      long long N, G; cin>>N>>G;
      vector<long long> S(N);
      for(int i = 0 ;i < N; i++){
	  long long ei;
	  cin>>ei; S[i] = ei-(N-i-1);
      }
      sort(S.begin(), S.end());
      for(int i = 0 ; i < N; i++) S[i] +=i;
      pair<long long, long long> pp(INT_MAX, -1);
      for(int i = 0 ; i < N; i++) pp = min(pp, {abs(S[i]-G),-S[i]}); 
      int c = 0;
      for(int i = 0; i < N; i++) c+= (S[i] < -pp.second);
      cout << "Case #"<<t<<": "<< N-c<<" " << pp.first<<endl;
   }
   return 0;
}
