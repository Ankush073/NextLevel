#include <bits/stdc++.h>
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
      cin >> t;
      while (t--)
      {
            //write code here
            bool flag=false;
            int n,a,b;
            cin>>n>>a>>b;
            if(a>b){
                  swap(a,b);
            }
            while(a<n && b>1){
                  if(a+1==b){
                        flag=true;
                        break;
                  }
                  a++;
                  b--;
            }
            if(flag){
                  cout<<"NO\n";
            }
            else cout<<"YES\n";

            
      }
      return 0;
}