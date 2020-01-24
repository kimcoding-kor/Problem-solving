#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef vector <int> vi;

char arr[400005];
string s;
vi pi, ans;

void get_pi() {
	pi.resize((int)s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
}

void answer() {
	int sz = s.size();
	while (sz) {
		ans.push_back(sz);
		sz = pi[sz - 1];
	}
}

int main() {
	scanf("%s", arr);
	s = arr;
	scanf("%s", arr);
	s += arr;
	get_pi();
	answer();
	sort(ans.begin(), ans.end());
	for (auto& now : ans) printf("%d ", now);
	return 0;
}