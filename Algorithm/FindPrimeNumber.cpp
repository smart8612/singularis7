#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void toString(vi &vec) {
    cout << '[';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        (i != vec.size()-1)? cout << ',' : cout << "]\n";
    }
}

int reseto(vi &vec, int N, int K) {
	for (int i=0; i<=N; i++) {
		vec[i] = i;
	}
	
	int answer = 0;
	for (int i=2; i<=N; i++) {
		if (vec[i] == 0) continue;
		
		for (int j=i; j<=N; j+=i) {
			if (vec[j] == 0) continue;
			answer = vec[j];
			vec[j] = 0;
			if (--K == 0) return answer;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;
	cin >> N >> K;
	
	vi vec(N+1, 0);
	int answer = reseto(vec, N, K);
	cout << answer << '\n';
	
	return 0;
}