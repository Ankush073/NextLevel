#include<bits/stdc++.h>
using namespace std;
using  ll =long long ; 
int main(){
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      int t;
      cin>>t;
      while(t--){
            ll n;
            cin>>n;
            set<pair<ll,ll>>edges;
            vector<ll>degree(n+1);
            ll ans=0;
            for(ll i=0;i<n-1;i++){
                  ll u,v;
                  cin>>u>>v;
                  edges.insert({u,v});
                  edges.insert({v,u});
                  degree[u]++;
                  degree[v]++;
            }
            vector<pair<ll,ll>>b;
            for(ll i=0;i<n;i++){
                  b.push_back({degree[i+1],i+1});
            }
            sort(b.begin(),b.end(),greater<pair<ll,ll>>());
            for(ll i=0;i<n;i++){
                  for(ll j=i+1;j<n;j++){
                        if(edges.find({b[i].second,b[j].second})==edges.end()){
                              ans=max(ans,b[i].first+b[j].first-1);
                              break;
                        }
                  }
            }
            for(auto x:edges){
                  ans=max(ans,degree[x.first]+degree[x.second]-2);
            }
            cout<<ans<<endl;
      }

}