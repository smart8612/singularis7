#include <bits/stdc++.h>
using namespace std;

typedef long double C;
typedef complex<C> P;

#define X real()
#define Y imag()

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Method to create vector instance
    P p = {4, 2};
    cout << p.X << ' ' << p.Y << '\n';

    // Method to caculate distance between two vectors
    P a = {4, 2};
    P b = {3, -1};
    cout << abs(b-a) << '\n';

    // Method to calculate radian(angular component) between x-axis and vector v
    P v = {4, 2};
    cout << arg(v) << '\n';

    // polar(s, a) mean creating a new vector which have scale 's' and radian(angular component) 'a'
    v *= polar(1.0, 0.5);
    cout << arg(v) << '\n';

    // Method to calculate cross product between vector a and b;
    a = {4, 2};
    b = {1, 2};
    C pp = (conj(a)*b).Y;
    cout << pp << '\n';

    return 0;
}
