#include <bits/stdc++.h>
using namespace std;
vector<double> Ai, Bi, slopeLow, slopeHi;
long long N;

int main(){
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
	   cin>>N;
      Ai.assign(N,0);
      Bi.assign(N,0);
      //double maxSlope = INT_MAX;
      double maxVel = numeric_limits<double>::infinity(); // Use numeric_limits for better infinity handling
      double minVel = -numeric_limits<double>::infinity(); // Use numeric_limits for better infinity handling
      for(int i = 0 ; i < N; i++){
	      cin>>Ai[i]>>Bi[i];
	      minVel = max(minVel, (1.0+i)/Bi[i]);
	      if(Ai[i]!=0) maxVel = min(maxVel, (1.0+i)/Ai[i]);
      }
      cout << fixed << setprecision(6); // Fixed-point notation and precision of 6 decimal places
      cout << "Case #"<<t<<": ";

      if(maxVel<minVel)cout << -1<<endl;
      else cout << minVel<<endl;
   }
   return 0;
}
/*
 1) remove for each one
 y = m*x + b where b = 0.0;

 * */
