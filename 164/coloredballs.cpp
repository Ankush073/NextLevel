#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
#define MOD 998244353
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
ll int arr[5005];
ll int dp[5005][7005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
        //write code here
       int n;
       cin>>n;
       ll ans=0;
       ll sum=0;
       for(int i=1;i<=n;i++){
            cin>>arr[i];
       }
       sort(arr+1,arr+n+1);
       dp[0][0]=1;
       for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                  dp[i][j]+=(dp[i-1][j])%MOD;
                  dp[i][j+arr[i]]+=(dp[i-1][j])%MOD;
            }
            for(int j=0;j<=sum;j++){
                  if(j<=arr[i]){
                        ans+=(dp[i-1][j]*(arr[i]))%MOD;
                  }
                  else ans+=(dp[i-1][j]*((arr[i]+j+1)/2))%MOD;
            }
            sum+=arr[i];
       }
       cout<<ans%MOD<<endl;
       return 0;
}