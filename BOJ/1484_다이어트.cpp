#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define EPS (1e-9)
using namespace std;

int main() {
    FIO;
    int G, flag = 0;
    cin >> G;
    for (int i = (int)sqrt(G) + 1; 1ll * i * i - 1ll * (i - 1) * (i - 1) <= G; i++) {
        double x = sqrt(1.0 * i * i - G);
        if (abs(floor(x) - x) <= EPS) cout << i << '\n', flag = 1;
    }
    if (!flag) cout << -1 << '\n';
    return 0;
}