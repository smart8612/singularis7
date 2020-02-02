#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void printArray(vi &vec) {
    cout << '[';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        (i != vec.size()-1)? cout << ',' : cout << "]\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << "Default vector status" << '\n';
    vi vec = {9, 2, 31, 1, 2, 51, 7, 1};
    printArray(vec);
	
    cout << "Sorting By ASC" << '\n';
    sort(vec.begin(), vec.end());
    printArray(vec);

    cout << "Reverse" << '\n';
    reverse(vec.begin(), vec.end());
    printArray(vec);
	
    cout << "Shuffling" << '\n';
    random_shuffle(vec.begin(), vec.end());
    printArray(vec);
	
    cout << "ReSort By ASC" << '\n';
    sort(vec.begin(), vec.end());
    printArray(vec);
    
    cout << "Unique Bound Shuffling" << '\n';
    random_shuffle(lower_bound(vec.begin(), vec.end(), 2), 
                   upper_bound(vec.begin(), vec.end(), 20)
                  );
    printArray(vec);
	
    cout << "ReSort By ASC && Remove overlap" << '\n';
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    printArray(vec);
	
    return 0;
}
