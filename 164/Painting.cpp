#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
      int t;
      cin>>t;
      while(t--)
      {
            long long n,m,k;
            cin>>n>>m>>k;
            int maxcol=(n+m-1)/m;
            if(n-maxcol<=k){
                  cout<<"NO\n";

            }
            else cout<<"YES\n";
      }
}