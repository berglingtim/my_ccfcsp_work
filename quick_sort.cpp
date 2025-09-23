#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int q[N];

// 随机数初始化
mt19937 rng((unsigned) chrono::steady_clock::now().time_since_epoch().count());//这一段得特别记忆，特别是括号有几个
void quick_sort(int q[],int l,int r){
    while(l<r){
        int pivot_index = uniform_int_distribution<int>(l,r)(rng);
        int x = q[pivot_index];
        int i = l,j = r;
        int k = l;

        while(k <= r){
            if(q[k]>x) swap(q[k++],q[i++]);
            else if(q[k]<x) swap(q[k],q[j--]);
            else k++;

            
        }
        if(i-l<r-j){
            quick_sort(q,l,i-1);
            l = j+1;
        }else{
            quick_sort(q,j+1,r);
            r = i-1;
        }
        }
    }


int main() {
    
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ",q[i]);
    printf("\n");

    return 0;
}
