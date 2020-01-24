#include <cstdio>
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
 
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s; int n;
	cin >> n >> s;
	int arr[26] = {};
	for (auto i : s) {
		if (i == 'L') arr['L' - 'A']++;
		if (i == 'R') arr['R' - 'A']++;
	}
	cout << arr['R' - 'A'] + arr['L' - 'A'] + 1 << '\n';
	
	return 0;
}