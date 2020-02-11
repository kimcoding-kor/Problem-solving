#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define fs first
#define sd second
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ppi pair <pii,pii>
#define mod 16000057
#define MAX (int)1e9
using namespace std;

struct HASH {
	vector <pii> hash;
	HASH(){
		hash.resize(mod, { mod, 0 });
	}
	int next(int key) {
		return (key + MAX + (key % 307)) % mod;
	}
	void insert(int key) {
		int val = key;
		do {
			key = next(key);
		} while (hash[key].fs != val && hash[key].fs != mod);
		hash[key].fs = val;
		hash[key].sd++;
	}
	int find(int key) {
		int val = key;
		do {
			key = next(key);
		} while (hash[key].fs != val && hash[key].fs != mod);
		return hash[key].fs == mod ? 0 : hash[key].sd;
	}
	~HASH(){
		hash.clear();
	}
};

int main() {
	FIO;
	int n; cin >> n;
	vvi v(4, vi(n));
	FOR(i, 0, n - 1) FOR(j, 0, 3)
		cin >> v[j][i];
	HASH h;
	FOR(i, 0, n - 1)FOR(j, 0, n - 1)
		h.insert(v[0][i] + v[1][j]);
	ll ans = 0;
	FOR(i, 0, n - 1) FOR(j, 0, n - 1)
		ans += 1LL * h.find(-(v[2][i] + v[3][j]));
	cout << ans << '\n';
	return 0;
}