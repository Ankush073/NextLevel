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
            ll l,r;
            cin>>l>>r;
            if(l==1 && r==1){
                  cout<<1<<endl;
            }
            else cout<<r-l<<endl;
      }

}