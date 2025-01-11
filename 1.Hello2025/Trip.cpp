#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
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
        ll l,r,a,b,c,ans=0;
        cin>>l>>r;
        for(int i=30;i>=0;i--){
            int b1=0;
            int b2=0;
            if(l& (1ll<<i)){
                  b1=1;
            }
            if(r & (1ll<<i)){
                  b2=1;
            }
            if(b1==b2){
                  ans+=(b1*(1ll<<i));
            }
            else{
                  a=ans+(1ll<<i);
                  b=a-1;
                  break;
            }
      }
      for(int i=l;i<=r;i++){
            if(i!=a && i!=b){
                  c=i;
                  break;
            }    
        }
      cout<<a<< " "<< b<< " "<< c<<endl;
       
    }
    return 0;
}