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
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
ll solve(vl & arr,ll x,ll sum){
      ll n=arr.size();
      ll ans=0;
      ll j=0;
        for(int i=n-1;i>=0;i--){
            while(j<n && sum-arr[i]-arr[j]>=x){
                  j++;
            }
            ans+=(n-j);
        }
        fo(i,n){
            if(sum-arr[i]-arr[i]<x){
                  ans--;
            }
        }
        return ans/2;
}
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
        ll n,x,y;
        cin>>n>>x>>y;
        vl arr(n);
        ll sum=0;
        fo(i,n){
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr.begin(),arr.end());
        cout<<solve(arr,y+1,sum)-solve(arr,x,sum)<<endl;
       
       
    }
    return 0;
}