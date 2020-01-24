#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector <string> v, temp, ans;

void input() {
	ans.clear();
	v.clear();  temp.clear();
	char arr[105];
	scanf("%s", arr);
	int idx = 0;
	while (arr[idx] != '\0') {
		if (arr[idx] == '*') {
			v.push_back("*"); idx++;
		}
		else {
			if (!idx || arr[idx - 1] == '*') v.push_back("");
			v[v.size() - 1] += arr[idx++];
		}
	}
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", arr);
		temp.push_back(arr);
	}
}

int solve(int idx ,int v_idx, string &temp) {
	int chk = 0;
	for (int i = v_idx, j ,k; i < v.size(); i++) {
		string now = v[i];
		if (now == "*") chk = 1;
		else if (chk) {
			for (j= idx; j < temp.size() - now.size() + 1; j++) {
				for (k = 0; k < now.size(); k++) {
					if (now[k] == '?') continue;
					if (temp[j + k] != now[k]) break;
				}
				if (k < now.size()) continue;
				if (solve(j + k, i + 1, temp)) return 1;
			}
			return 0;
		}
		else {
			for (j = 0; j < now.size(); j++) {
				if (now[j] == '?') {
					idx++; continue;
				}
				if (now[j] != temp[idx++]) return 0;
			}
		}
	}
	if (idx < temp.size() && !chk) return 0;
	return 1;
}

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		input();
		for (auto& now : temp)
			if (solve(0, 0, now)) ans.push_back(now);
		sort(ans.begin(), ans.end());
		for (auto& now : ans) printf("%s\n", now.c_str());
	}
	return 0;
}