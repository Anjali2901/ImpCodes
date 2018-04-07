//SegmentTreeLazyPropagation

#include <bits/stdc++.h>
#define ll long long int
#define MAX 100005
using namespace std;
ll arr[MAX];
struct node2 {
    ll val;
    ll lazy;
} tree[4 * MAX];

void merge(node2 &p, node2 &q, node2 &ans) {
    ans.val = p.val + q.val;
    ans.lazy = 0;
}
void build(ll node, ll start, ll end) {
    if(start == end) {
        tree[node].val = arr[start];
        tree[node].lazy = 0;
        return;
    }
    ll mid, p, q;
    mid = (start + end) >> 1;
    p = node << 1;
    q = p|1;
    build(p, start, mid);
    build(q, mid + 1, end);
    merge(tree[p], tree[q], tree[node]);
}
void lazyUpdate(ll node, ll start, ll end) {
    ll k = tree[node].lazy;
    if(k) {
        tree[node].val+= k * (end + 1 - start);
        if(start != end) {
            ll p, q;
            p = node << 1;
            q = p|1;
            tree[p].lazy+=k;
            tree[q].lazy+=k;
        }
        tree[node].lazy = 0;
    }
}
node2 query(ll node, ll start, ll end, ll l, ll r) {
    if(start > r || end < l) {
        node2 temp;
        temp.val = temp.lazy = 0;
        return temp;
    }
    lazyUpdate(node, start, end);
    if(start >= l && end <= r) {
        return tree[node];
    }
    ll mid, p, q;
    mid = (start + end) >> 1;
    p = node << 1;
    q = p|1;
    node2 left, right, ans;
    left = query(p, start, mid, l, r);
    right = query(q, mid + 1, end, l, r);
    merge(left, right, ans);
    return ans;
}
void update(ll node, ll start, ll end, ll l, ll r, ll val) {
    lazyUpdate(node, start, end);
    if(start > r || end < l) {
        return;
    }
    if(start >= l && end <= r) {
        tree[node].val +=(end + 1 - start) * val;
        if(start != end) {
            ll p = node << 1;
            ll q = p|1;
            tree[p].lazy+=val;
            tree[q].lazy+=val;
        }
        return;
    }
    ll mid, p, q;
    mid = (start + end) >> 1;
    p = node << 1;
    q = p|1;
    update(p, start, mid, l, r, val);
    update(q, mid + 1, end, l, r, val);
    merge(tree[p], tree[q], tree[node]);
}
int main() {
    ll n;
    cin >> n;
    ll i;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    ll q, val;
    cin >> q;
    while(q--) {
        int ch;
        cin >> ch;
        ll l, r;
        cin >> l >> r;
        if(ch == 1) {
            node2 ans = query(1, 1, n, l, r);
            cout << ans.val << endl;
        }
        else {
            cin >> val;
            update(1, 1, n, l, r,val);
        }
    }
    return 0;
}



/*

Input
5
1 2 3 4 5
5
1 3 5
2 2 3 4
1 1 5
2 1 4 3
1 2 4

Output
12
23
26

*/
