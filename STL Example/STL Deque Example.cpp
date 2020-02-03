#include <bits/stdc++.h>
using namespace std;

typedef deque<int> dqi;

void to_string(dqi &deq) {
	cout << '[';
	for (int i = 0; i < deq.size(); i++) {
		cout << deq[i];
		(i != deq.size()-1)? cout << ',' : cout << "]\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	dqi deq;
	
	deq.push_back(5);  // [5]
	to_string(deq);
	
	deq.push_back(2);  // [5, 2]
	to_string(deq);
	
	deq.push_front(3); // [3, 5, 2]
	to_string(deq);
	
	deq.pop_back();    // [3, 5]
	to_string(deq);
	
	deq.pop_front();   // [5]
	to_string(deq);
	
	return 0;
}