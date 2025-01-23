#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
      while (t--) {
        int n, k;
        cin >> n >> k;
 
        vector<int> x(n);
        unordered_map<int, int> freq;
 
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            freq[x[i]]++;
        }
 
        int score = 0;
 
        for (const auto it: freq) {
            int num=it.first;
            int count=it.second;
            int complement = k - num;
            if (complement == num) {
                score += freq[num] / 2;
            } else if (freq.count(complement)) {
                int pairs = min(freq[num], freq[complement]);
                score += pairs;
                freq[num] -= pairs;
                freq[complement] -= pairs;
            }
        }
        cout << score << endl;
    }
         return 0;
}
 