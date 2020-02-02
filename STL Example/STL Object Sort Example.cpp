#include <bits/stdc++.h>
using namespace std;

class Object {
public:
	string str;
	int number;
	
	Object(string str, int number) {
		this->str = str;
		this->number = number;
	}
	
	bool operator <(Object &object) {
		return this->number < object.number;
	}
};

bool compare(Object &objectA, Object &objectB) {
	return objectA.number > objectB.number;
}

typedef vector<Object> vo;

void printArray(vo &vec) {
    cout << '[';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].str << ':' << vec[i].number;
        (i != vec.size()-1)? cout << ',' : cout << "]\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vo vec = {
		Object("ABC", 85),
		Object("DEF", 90),
		Object("GHI", 72),
		Object("JKL", 63),
		Object("NMO", 20),
		Object("PQR", 40),
		Object("STU", 50),
		Object("XYZ", 30)
	};
	
	printArray(vec);
	
	sort(vec.begin(), vec.end());
    printArray(vec);
	
	sort(vec.begin(), vec.end(), compare);
    printArray(vec);
    
    return 0;
}