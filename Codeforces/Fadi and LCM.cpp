#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define all(x) (x).begin(), (x).end()
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;
typedef vector <ll> vl;
 
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n; cin >> n;
	ll temp = 1;
	for (int i = 1; 1LL * i * i < n; i++) {
		if (!(n % i) && gcd(1LL * n / i, 1LL * i) == 1)
			temp = 1LL * i;
	}
	cout << temp << " " << n / temp << '\n';
	return 0;
}