#include <cstdio>
#include <deque>
#include <algorithm>
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
		int ret = 0, chk = 0;
		if (i == idx) readinput();
		if (buffer[i] == '-') {
			chk = 1, i++;
		}
		if (i == idx) readinput();
		while (i < idx && (buffer[i] >= '0' && buffer[i] <= '9')) {
			ret = ret * 10 + (buffer[i] - '0'), i++;
			if (i == idx) readinput();
		}
		return i++, chk ? -ret : ret;
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
		if (x < 0) buffer[i++] = '-', x = -x;
		check();
		if (!x) temp[j++] = 0;
		while (x) {
			temp[j++] = x % 10;
			x /= 10;
		}
		for (int k = j - 1; k >= 0; k--) {
			buffer[i++] = temp[k] + '0';
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
	int n = br.readint(), l = br.readint();
	deque <pair<int, int>> dq;
	for (int i = 0; i < n; i++) {
		int x = br.readint();
		while (dq.size() && dq.front().second < i - l + 1) dq.pop_front();
		while (dq.size() && dq.back().first > x) dq.pop_back();
		dq.push_back({ x, i });
		bw.writeint(dq.front().first);
	}
	if (bw.i) bw.writeoutput();
	return 0;
}