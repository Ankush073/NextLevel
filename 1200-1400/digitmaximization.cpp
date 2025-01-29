#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (long long i = 0; i < n; i++)
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
typedef pair<long long, long long> pii;
typedef pair<ll, ll> pl;
typedef vector<long long> vi;
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
        string s;
        cin>>s;
        int n=s.length();
        vector<int>digit(n);
        for(int i=0;i<n;i++){
            digit[i]=s[i]-'0';
        }
        for(int i=1;i<n;i++){
            int j=i;
            while(j>=1 && digit[j]>0 && digit[j]>digit[j-1]+1 ){
                  swap(digit[j],digit[j-1]);
                  digit[j-1]--;
                  if(j>1) j--;
                  else break;
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            ans+=to_string(digit[i]);
        }
        cout<<ans<<endl;


    
  
    }
}
  