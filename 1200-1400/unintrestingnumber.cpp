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
ll power(ll n, ll expo){
      if(expo==0){
            return 1;
      }
      while(expo>1){
            n*=n;
            expo--;
      }
      return n;

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
        string s;
        cin>>s;
        long long cnt2=0;
        long long cnt3=0;
        long long sum=0;
        bool flag=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='2') cnt2++;
            else if(s[i]=='3') cnt3++;
            sum+=s[i]-'0';
        }
        long long diff_cover= (9-sum%9)%9;
        for(long long i=0;i<=cnt3;i++){
            long long new_diff=(diff_cover-6ll*i)%9;
            if(new_diff<0){
                new_diff+=9;
            }
            long long a=(new_diff*5)%9;
            if(a<=cnt2){
               flag=true;
                break;
            }
        }
        if(flag){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
       
    }
    return 0;
}