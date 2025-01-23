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
            ll n,l,r;
            cin>>n>>l>>r;
            l--;
            r--;
            vector<ll>arr(n);
            for(int i=0;i<n;i++){
                  cin>>arr[i];
            }
            vector<ll>a;
            vector<ll>b;
            for(int i=l;i<n;i++){
                  b.push_back(arr[i]);
            }
            for(int i=0;i<=r;i++){
                  a.push_back(arr[i]);
            }
            
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            ll sum1=accumulate(a.begin(),a.begin()+(int)(r-l+1),0LL);
            ll sum2=accumulate(b.begin(),b.begin()+(int)(r-l+1),0LL);
            cout<<min(sum1,sum2)<<endl;
           
      }

}