#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int q[N];
int n, m;

// 找到最左边等于 x 的下标
int find_left(int x,int l,int r) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (q[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if (q[l] == x) return l;
    return -1;
}

// 找到最右边等于 x 的下标
int find_right(int x,int l,int r) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;  // 偏右
        if (q[mid] <= x) l = mid;
        else r = mid - 1;
    }
    if (q[l] == x) return l;
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    while (m--) {
        int x;
        scanf("%d", &x);

        int L = find_left(x,0,n-1);
        int R = find_right(x,0,n-1);

        
        cout << L << " " << R << endl;
    }
}
