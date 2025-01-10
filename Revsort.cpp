#include<bits/stdc++.h>
using  namespace std;
int revsort(vector<int>&v){
      int cost=0;
      for(int i=0;i<v.size()-1;i++){
            int m=*min_element(v.begin()+i,v.end());
            auto x=find(v.begin(),v.end(),m);
            reverse(v.begin()+i,x+1);
            cost+=distance(v.begin(),x)-i+1;
      }
      return cost;
}
int main(){
      int t;
      cin>>t;
      while(t--){
            int n;
            cin>>n;
            vector<int>v;
            for(int i=0;i<n;i++){
                  int num;
                  cin>>num;
                  v.push_back(num);
            }
            int ans=revsort(v);
            cout<<ans;
      }
}