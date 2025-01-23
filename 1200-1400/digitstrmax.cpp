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
int find(vi &arr,int maxi){
      int n=arr.size();
      for(int i=n-1;i>=1;i--){
            if(arr[i]==maxi){
                  return i;
            }
      }
      return -1;
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
        string ans;
        cin>>s;
        int n=s.length();
        vi arr(n);
        fo(i,n){
            
        }
        fo(i,n-1){
            int maxi=*max_element(arr.begin()+1,arr.end());
            // cout<<maxi<<endl;
            if(maxi==0){
                  continue;
            }
            int index=find(arr,maxi);
            maxi--;
            arr[index]=maxi;
            swap(arr[index-1],arr[index]);
        }
        arr[n-1]-=1;
        swap(arr[n-2],arr[n-1]);
        fo(i,n){
            ans+=to_string(arr[i]);
        }
        cout<<ans<<endl;

       
    }
    return 0;
}