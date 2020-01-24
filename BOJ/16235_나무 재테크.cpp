#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;i++)

struct p {
	int r, c, age;
	bool operator< (const p& t) const {
		return age < t.age;
	}
};

deque <p> dq;
int n, m, k;
int map[15][15], bonus[15][15];
int dir[8][2] = { {-1,-1}, {-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1} };

void ss() {
	deque <p> temp;
	int dqsize = dq.size();
	FOR(i,1,dqsize) {
		p now = dq.front(); dq.pop_front();
		if (map[now.r][now.c] >= now.age) {
			map[now.r][now.c] -= now.age;
			dq.push_back(p{ now.r, now.c, now.age + 1 });
		}
		else temp.push_back(now);
	}
	while (temp.size()) {
		p now = temp.front(); temp.pop_front();
		map[now.r][now.c] += now.age / 2;
	}
}

void fw() {
	deque <p> temp = dq;
	while(temp.size()) {
		p now = temp.front(); temp.pop_front();
		if (now.age % 5) continue;
		for (auto d : dir) {
			int nr = now.r + d[0], nc = now.c + d[1];
			if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
			dq.push_front(p{ nr,nc,1 });
		}
	}
	FOR(i, 1, n) FOR(j, 1, n)
		map[i][j] += bonus[i][j];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	FOR(i, 1, n) FOR(j, 1, n) {
		cin >> bonus[i][j];
		map[i][j] += 5;
	}
	p arr[105];
	FOR(i, 1, m) cin >> arr[i].r >> arr[i].c >> arr[i].age;
	sort(arr + 1, arr + m + 1);
	FOR(i, 1, m) dq.push_back(arr[i]);
	FOR(i, 1, k) ss(), fw();
	cout << (int)dq.size() << '\n';
	return 0;
}