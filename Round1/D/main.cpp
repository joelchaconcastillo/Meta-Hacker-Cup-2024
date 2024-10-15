#include <bits/stdc++.h>
using namespace std;
long long const MOD = 998244353;
int main(){
   int T; cin >>T;
   for(int t = 1; t<=T; t++){
     cout << "Case #"<<t<<": ";
     int k;
     string st;cin>>st>>k;
     string st2 = st;
     for(auto &i:st2) if(i=='?')i='1';
     int n = st.size();
     vector<int> dp(n+1); //number of combinations that can be found until s[i]
     vector<bool> can2(n, false); //it says if string at position i can be paired with position i-1
     dp[0]=1;
     for(int i = 1; i <=n; i++){
	 if(st2[i-1] != '0') dp[i] += dp[i-1];
	 if(i>=2){
	   if(st2[i-2] == '1') dp[i] +=dp[i-2], can2[i-2]=true; //both can be taken 1x
	   if(st2[i-2] == '2' && st2[i-1] < '7') dp[i] += dp[i-2], can2[i-2]=true; //both can be taken 2x
	 }
	 dp[i]%=MOD;
     }
     vector<vector<int > > f(n, vector<int> (10) ); //its just to say that for pos 'i' digit p its feasible
     vector fail(n, vector(10, vector<bool>(10, false)));
     for(int i = n-1; i>=0; i--){
	int l = 1, h = 9;
	if(st[i] != '?') l = h = (int) st[i]-'0';
	for(int d = l; d <=h; d++){ //check the full range of options
	  if(i==n-1){ //last one!
	     f[i][d] = 1; continue; //its feasible, so we don't not further checks
	  }
	  for(int p = 0; p<=9; p++){
	     if(can2[i] && (i+2==n || st2[i+2] != '0')){ //check that can2 indicates that i can be paired with i-1
	       if(!(d==1 || (d==2 && p<=6))){
		       fail[i][d][p] = true; continue; //from pos i we cann't pair d with p
	       }
	     }
	     f[i][d] = min(k, f[i][d]+f[i+1][p]);//we can take digit d on pos i to digit p on next pos
	  }
	}
     } // !for
     for(int i = 0; i < n; i++){
        int l=1, h=9;
	if(st[i]!='?') l = h = int(st[i] -'0');
	bool found=false;
	for(int d = h; d>=l; d--){
	    if(i>0){
	       int q = int(st[i-1]-'0');
	       if(fail[i-1][q][d]) continue;
	    }
	    if(k>f[i][d]) k-=f[i][d]; //remove from kth the top ones!
	    else{
		    st[i] = char('0'+d);
		    found=true;
		    break;
	    }

	}
     }
     cout << st << " "<<dp[n]<<"\n";
   }
   return 0;
}
