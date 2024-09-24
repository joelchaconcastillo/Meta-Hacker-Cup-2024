#include <bits/stdc++.h>
using namespace std;
pair<int, int> norm_sl(int dx, int dy){
   if(dx==0) return {0, 1}; //vertical
   if(dy==0) return {1, 0}; //horizontal
   int g = __gcd(dx, dy);
   dx /=g, dy/=g;
   if(dx < 0) dx =-dx, dy = -dy;
   return {dx, dy};
}
int sampling_method(int n, vector<pair<int, int> > &a, int samples){ //lets try montecarlo method :v'
   if(n==2) return 0;
   int res = n-1;
   for(int s = 0; s < samples; s++){
      int i = rand()%n;
      map<pair<int, int>, int> slope_count;
      int max_col=0;
      for(int j = 0 ;j < n; j++){
	  if(i==j)continue;
          int dx = a[j].first-a[i].first, dy = a[j].second-a[i].second;
          pair<int, int> slope = norm_sl(dx, dy);
          slope_count[slope]++;
          max_col = max(max_col, slope_count[slope]);
      }
      res = min(res, n-max_col-1);
   }
   return res;
}
int expensive(int n, vector<pair<int, int>> &a){
   if(n==2) return 0;
   int res = n-1;
   for(int i = 0 ;i < n; i++){
     map<pair<int, int>, int> slope_count;
     int max_col=0;
     for(int j = i+1; j<n; j++){
       int dx = a[j].first-a[i].first, dy = a[j].second-a[i].second;
       pair<int, int> slope = norm_sl(dx, dy);
       slope_count[slope]++;
       max_col = max(max_col, slope_count[slope]);
     }
     res = min(res, n-max_col-1);
   }
   return res;
}
int merge(int l, int r, int m, int left, int right, vector<pair<int, int> > &a){//This won; WORK :S
   map<pair<int, int>, int> slope_count;
   int max_col=0;
   for(int i = l; i < m; i++){
      for(int j = m; j < r; j++){
       int dx = a[j].first-a[i].first, dy = a[j].second-a[i].second;
       pair<int, int> slope = norm_sl(dx, dy);
       slope_count[slope]++;
       max_col = max(max_col, slope_count[slope]);
      }
   }
   return min(min(left, right), (int)a.size()-max_col-1);
}
int merge_approach(int l, int r, vector<pair<int, int>> &a){
   if(l+1>=r)return 0;
   int m = (r+l)/2;
   int left = merge_approach(l, m, a); //0, 1 --> 
   int right = merge_approach(m, r, a);// 1, 1
   return merge(l, r, m, left, right, a);
}
int main(){
   int T; cin >> T;
   for(int t = 1; t <=T; t++){
      int n; cin >>n;
      vector<pair<int, int> >a(n);
      for(auto &i:a)cin >> i.first >>i.second;
      //sort(a.begin(), a.end());
      //int res = merge_approach(0, a.size(), a);
      int res = 0;
//      cout << n <<endl;
      if(n<5000) res = expensive(n, a);
      else{
	   int samples = 10;
           res = sampling_method(a.size(), a, samples);
      }
      cout << "Case #"<<t<<": ";
      cout << res<<endl;
   }
   return 0;
}
