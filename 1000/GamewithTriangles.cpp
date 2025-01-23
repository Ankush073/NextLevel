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
            int n,m;
            cin>>n>>m;
            vector<ll>a(n),b(m);
            for(ll&i:a)cin>>i;
            for(ll&i:b)cin>>i;
            sort(begin(a),end(a));
            sort(begin(b),end(b));
            vector<ll>sa(n+2);
            vector<ll>sb(m+2);
            for(int i=1;i<=n;i++)sa[i]=sa[i-1]+(a[n-i]-a[i-1]);
            for(int i=1;i<=m;i++)sb[i]=sb[i-1]+(b[m-i]-b[i-1]);
            vector<ll>ans{0};
            for(int x=1;2*x-m<=n-x;x++){
                  ll l=max(0,2*x-m);
                  ll r=min(x,n-x);
                  if(l>r){
                        break;
                  }
                  auto f=[&](int k) {return sa[k]+sb[x-k];};
                  while(r-l>3){
                        ll ml=(l*2+r)/3;
                        ll mr=(l+r*2)/3;
                        if(f(ml)>f(mr)){
                              r=mr;
                        }
                        else l=ml;
                  }
                  ll mans=0;
                  for(ll i=l;i<=r;i++){
                        mans=max(mans,f(i));
                  }
                  ans.push_back(mans);
            }
            int kmax=ans.size()-1;
            cout<<kmax<<"\n";
            for(int i=1;i<=kmax;i++)cout<<ans[i]<<" \n"[i==kmax];
      }

}