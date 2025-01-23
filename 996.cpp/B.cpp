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
            long long  n;
            cin>>n;
            bool flag=true;
            vector<long long >a(n+1),b(n+1);
            for(long long i=1;i<=n;i++){
                  cin>>a[i];
            }
            for(long long  i=1;i<=n;i++){
                  cin>>b[i];
            }
            for(long long  i=1;i<=n;i++){
                  if(b[i]>a[i]){
                        long long needed =b[i]-a[i];
                        for(long long j=1;j<=n;j++){
                              if(i!=j){
                                    if(a[j]-a[j]<needed){
                                          cout<<"NO\n";
                                          break;
                                    }
                              }   
                        }
                        break;

                  }
                  else{
                        cout<<"YES\n";
                              
                  }
                  
            }   
      }
      return 0;
}