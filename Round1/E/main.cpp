#include <bits/stdc++.h>
const int L = 100;
const int MOD = 998244353;
const int K = 26;
using namespace std;
int get_len(string &s, string &t){ //it returns the index of the common prefix
  int m = min(s.size(), t.size());
  for(int i = 0 ; i < m; i++){
     if(s[i] != '?' && t[i] != '?' && s[i] != t[i]) return i;
  }
  return m;
}
void add(int &x, int y){ //it is the same than x = (x+y)%MOD;
  x +=y;
  if(x>=MOD) x-=MOD;
}
void sub(int &x, int y){ //it is the same than x = (x+MOD-y)%MOD;
  x -=y;
  if(x<0) x+=MOD;
}
int main(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0);
   
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
      cerr << "\n"<<t<<"\n"<<endl;
      int n; cin>>n;
      vector<string> s(n);
      for(auto &x:s) cin >> x;
      vector<bitset<L>> fixed(1<<n);//fixed will keep track of all bits on that are no '?'
      vector<vector<int> > len_calc(n, vector<int> (n)); //max len prefix between pairs
      for(int i = 0; i < n; i++){ //this is to compute the max prefix len between pairs of strings.
	 for(int j = 0; j < n; j++){
            len_calc[i][j] = get_len(s[i], s[j]);
	 }
      }
      vector<int> len(1<<n), dp(1<<n);
      //this dp stores the min LCP for each combination of bits or items
      //len stores the min lcp for each pair of strings
      len[0] = L;
      for(int i = 0; i < n; i++){
        bitset<L> cur;
	for(int j = 0; j < (int)s[i].size(); j++){ //turn on mask
	  if(s[i][j] != '?') cur.set(j);
	}
	dp[0] = L+1; // LCP taking the mask strings
	for(int j = 0; j < i; j++){
	   int mask = (1<<j);
	   for(int k = 0; k < mask; k++){ //take each subset
	     dp[k|mask] = min(dp[k], len_calc[i][j]); // 
	   }
	}
	for(int j = 0; j < (1<<i); j++){
	   int mask = j |(1<<i);
	   if(j == 0) len[mask] = (int) s[i].size();//edge case first item
	   else len[mask] = min(len[j], dp[j]); 
	   fixed[mask] = fixed[j]|cur;//turn on i
	}
      }
      int res=0;
      for(int mask = 1; mask < (1<<n); mask++){
         int wt = 1;
	 for(int i = 0; i < len[mask]; i++){
	   if(!fixed[mask][i]) wt = 1LL*wt*K % MOD;//this means if this bit is '?' it takes 26%MOD*wt
	   if(__builtin_popcount(mask) % 2 == 1) add(res, wt);
	   else sub(res, wt);
	 }
      }
      add(res, 1);
      cout << "Case "<<t<<": "<<res<<endl;
   }
   return 0;
}
