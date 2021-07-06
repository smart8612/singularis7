#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll init(vll &tree, vll &numbers, ll start, ll end, ll node)
{
    if (start == end) return tree[node] = numbers[start];    

    ll mid = (start + end) / 2;
    
    return tree[node] = init(tree, numbers, start, mid, node * 2) + init(tree, numbers, mid + 1, end, node * 2 + 1);
}

ll sum(vll &tree, ll start, ll end, ll node, ll left, ll right)
{
    // Out of Bound
    if (left > end || right < start) return 0;
    // Inside of Bound
    if (left <= start && end <= right) return tree[node];

    ll mid = (start + end) / 2;
    
    return sum(tree, start, mid, node * 2, left, right) + sum(tree, mid + 1, end, node * 2 + 1, left, right);
}

void update(vll &tree, ll start, ll end, ll node, ll index, ll diff)
{
    // Out of Bound
    if (index < start || index > end) return;
    // Inside of Bound
    tree[node] += diff;
    if (start == end) return;
    ll mid = (start + end) / 2;
    update(tree, start, mid, node * 2, index, diff);
    update(tree, mid + 1, end, node * 2 + 1, index, diff);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, K;
    cin >> N >> M >> K;

    vll numbers;
    for (ll i = 0; i < N; i++)
    {
        ll number;
        cin >> number;
        numbers.push_back(number);
    }

    vll segment_tree(4 * N, 0);
    init(segment_tree, numbers, 0, N-1, 1);

    for (ll i = 0; i < M + K; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            ll diff = c - numbers[b-1];
            numbers[b-1] = c;

            update(segment_tree, 0, N-1, 1, b-1, diff);
        }
        else
        {
            cout << sum(segment_tree, 0, N-1, 1, b-1, c-1) << '\n';
        }
    }
    
    
    return 0;
}
