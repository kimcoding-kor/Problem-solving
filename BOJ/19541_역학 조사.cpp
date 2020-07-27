#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

int main() {
   FIO;
   int n, m;
   cin >> n >> m;

   vvi v(m + 1);
   vi result(n + 1), ans(n + 1);

   FOR(i, 1, m) {
      int x; cin >> x;
      while (x--) {
         int y; cin >> y;
         v[i].push_back(y);
      }
   }

   FOR(i, 1, n) cin >> result[i];

   FOR(i, 1, n)
      ans[i] = result[i];

   RFOR(i, m, 1) {
      bool x = false;
      for (int j : v[i])
         if (!ans[j]) x = true;
      if (!x) continue;
      for (int j : v[i])
         ans[j] = 0;
   }

   vi temp(n + 1);
   FOR(i, 1, n) temp[i] = ans[i];

   FOR(i, 1, m) {
      bool x = false;
      for (int j : v[i])
         if (temp[j]) x = true;
      if (!x) continue;
      for (int j : v[i])
         temp[j] = 1;
   }

   int f = 1;

   FOR(i, 1, n)
      if (result[i] != temp[i]) f = 0;

   if (!f) cout << "NO" << '\n';
   else {
      cout << "YES" << '\n';
      FOR(i, 1, n) cout << ans[i] << ' ';
   }

   return 0;
}