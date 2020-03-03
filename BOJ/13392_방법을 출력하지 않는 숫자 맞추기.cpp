#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    int dp[10005][10];
    memset(dp,0x3f,sizeof(dp));
    int a[10005],b[10005], n;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%1d",&a[i]);
    FOR(i,1,n) scanf("%1d",&b[i]);
    FOR(i,0,9) dp[0][i] = i;
    FOR(i,1,n) FOR(j,0,9) FOR(k,0,9){
        int& ref= dp[i][(j + k) % 10];
        ref = min(ref, dp[i-1][j] + k + (((a[i] + j + k) % 10) - b[i] + 10) % 10);
    }
    int ans = 1e9;
    FOR(i,0,9) ans = min(ans, dp[n][i]);
    printf("%d\n",ans);
    return 0;
}