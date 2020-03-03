#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main(){
    FIO;
    int n;
    cin >> n;
    if(!(n % 2 && n % 5)) return cout << -1 << '\n',0;
    for(int i=1, j = 0;;i++){
        j = (10 * j + 1) % n;
        if(!(j % n)) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}