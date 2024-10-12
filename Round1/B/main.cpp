#include <bits/stdc++.h>
using namespace std;
long long N_MAX = 10000000;
vector<bool> is_prime;
vector<int> primes;
vector<int>ans;
void sieve(){
   is_prime.assign(N_MAX+1, true);
   is_prime[0]=is_prime[1]=0;
   for(long long i = 2; i*i <= N_MAX; i++){ //TODO: checking i*i will have some primes missing so we need and extra for to keep track of all prime numbers
       if(!is_prime[i])continue;
       for(long long j = i*i; j <= N_MAX; j+=i) is_prime[j]=false;
   }
   for(long long i = 2 ; i<=N_MAX; i++)
	   if(is_prime[i])primes.push_back(i);
}
void pre(){
   set<int> dif;
   int current = 1;
   ans.assign(N_MAX+1, 0);
   for(int i = 0 ; i < primes.size(); i++){
	   while(current < primes[i]) ans[current++]=dif.size();
	   for(int j = 0 ; j < i; j++){
	      int d = primes[i]-primes[j];
	      if(is_prime[d]) dif.insert(d);
	   }
   }
   while(current <= N_MAX) ans[current++]=dif.size();
}
int main(){
   sieve();
//   pre();
   int T; cin>>T;
   for(int t = 1; t <=T; t++){
     int N;cin>>N;
     //long long res = ans[N]; //this is an alternative method
     long long res = ans[N];
     for(int i = 2; i+2 <= N; i++){
	if(is_prime[i] && is_prime[i+2]) res++;
     }
     if(N>=5)res++;
     cout << "Case #"<<t<<": "<<res<<endl;
   }  
   return 0;
}
/*
  2 3 5 7
   5: --> 2,5=3 3,5=2 {2,3}
   8: --> 2,5=3 2,7=5 3,5=2 5,7=2 {2,3,5}  
 * */
