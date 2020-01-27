#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()	{
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test; cin >> test; for(int t = 1;t <= test; t++){
        int n,m; cin >> n>>m;
        vector <int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(),v.end());
        int ans = -1;
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(v[i] + v[j] <= m)
                    ans= max(ans,v[i]+v[j]);
            }
        }
        cout << '#' << t << ' ' << ans << '\n';
    }
    return 0;
}