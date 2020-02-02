#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> psi;
typedef vector<psi> vpsi;

bool compare(psi &pairA, psi &pairB) {
	return pairA.second > pairB.second;
}

void printArray(vpsi &vec) {
    cout << '[';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].first << ':' << vec[i].second;
        (i != vec.size()-1)? cout << ',' : cout << "]\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vpsi vec = {
		psi("DEF", 85),
		psi("ABC", 90),
		psi("JKL", 72),
		psi("GHI", 63),
		psi("PQR", 20),
		psi("NMO", 40),
		psi("STU", 50),
		psi("XYZ", 30)
	};
	
	printArray(vec);
	
	sort(vec.begin(), vec.end());
    printArray(vec);
	
	sort(vec.begin(), vec.end(), compare);
    printArray(vec);
    
    return 0;
}