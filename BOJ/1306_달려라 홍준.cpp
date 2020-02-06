#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

struct bufferedreader {
	char* buffer;
	int i = 0, idx = 0;
	bufferedreader() {
		buffer = new char[1 << 22];
	}
	void readinput() {
		idx = fread(buffer, 1, 1 << 22, stdin);
		i = 0;
	}
	int readint() {
		int ret = 0;
		if (i == idx) readinput();
		while (i < idx && (buffer[i] >= '0' && buffer[i] <= '9')) {
			ret = ret * 10 + (buffer[i] - '0'), i++;
			if (i == idx) readinput();
		}
		return i++, ret;
	}
	~bufferedreader() {
		delete[] buffer;
	}
};

struct bufferedwriter {
	char* buffer;
	int i = 0;
	bufferedwriter() {
		buffer = new char[1 << 22];
	}
	void writeoutput() {
		fwrite(buffer, 1, i, stdout);
	}
	void check() {
		if (i == (1 << 22)) {
			writeoutput(), i = 0;
		}
	}
	void writeint(int x) {
		int temp[15], j = 0;
		check();
		while (x) {
			temp[j++] = x % 10;
			x /= 10;
		}
		RFOR(k, j - 1, 0) {
			buffer[i++] = (temp[k] + '0');
			check();
		}
		buffer[i++] = ' ';
		check();
	}
	~bufferedwriter() {
		delete[] buffer;
	}
};

int main() {
	bufferedreader br;
	bufferedwriter bw;
	int n = br.readint(), m = br.readint();
	deque <pair <int, int>> dq;
	FOR(i, 1, n) {
		int x = br.readint();
		while (dq.size() && (dq.front().first <= i - 2 * m + 1))
			dq.pop_front();
		while (dq.size() && dq.back().second <= x)
			dq.pop_back();
		dq.push_back({ i,x });
		if (i >= 2 * m - 1) bw.writeint(dq.front().second);
	}
	if (bw.i) bw.writeoutput();
	return 0;
}