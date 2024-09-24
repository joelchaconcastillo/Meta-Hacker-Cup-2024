#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin >> T;
   for(int t = 1; t<=T; t++){
      double n, p; cin>>n>>p;
      p/=100.0;
      double exp = (n-1.0)/n;
      double res = (pow(p, exp)-p)*100;
      cout << "Case #"<<t<<": "<<fixed<<setprecision(7)<<res<<endl;
   }
   return 0;
}
/*
     p'^n = p^(n-1)  --> p'?
     p' = p^((n-1)/n)

     iff p' = p+delta
     p + delta = p^((n-1)/n)
     delta = p^((n-1)/n)-p
 * */
