#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int M;
	cin >> M;
	
	int s = 0;
	for (int m=0; m<M; m++) {
		string cmd = "";
		int data = 0;
		cin >> cmd;
		
		if (cmd == "add") {
			cin >> data;
			s |= (1<<data);
			
		} else if (cmd == "remove") {
			cin >> data;
			s &= ~(1<<data);
			
		} else if (cmd == "check") {
			cin >> data;
			bool flag;
			flag = (s & (1<<data))? true:false;
			cout << flag << '\n';
			
		} else if (cmd == "toggle") {
			cin >> data;
			s ^= (1<<data);
			
		} else if (cmd == "all") {
			s = (1 << 21)-1;
			
		} else if (cmd == "empty") {
			s = 0;
		}
	}
	
	return 0;
}