#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b, int GCD) {
	return a*b / GCD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	int GCD = gcd(a, b);
	cout << GCD << '\n';
	cout << lcm(a, b, GCD) << '\n';
	
	return 0;
}