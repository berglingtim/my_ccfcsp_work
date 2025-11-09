#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;     // 第l个加上c
    b[r + 1] -= c; // 第r个减去c
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        insert(i, i, a[i]); // 构造a[i] = b[1] + b[2] + ... + b[i]  b[i] = a[i] - a[i-1]  b[1] = a[1]
                            // 则只要第l个加上一个c，后面的就加上了，最后在r处减回去，就到达了效果

    while (m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    // 以前 
    // b[1] = a[1] - a[0]
    // b[2] = a[2] - a[1]
    // 现在
    // b[1] = b[0] = 0
    // b[2] = b[2] + b[1] = a[2] - a[1] + a[1] = a[2] = b[1] + b[2] = 0 + b[2]
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);

    return 0;
}
