#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int q[N];
int tmp[N];

typedef long long LL;

LL merge_sort_reverse_pairs(int q[],int l,int r){
    if(l >= r) return 0;

    int mid = (l + r) >> 1;
    int i = l, j = mid + 1;
    int k = 0;

    LL res = merge_sort_reverse_pairs(q,l,mid) + merge_sort_reverse_pairs(q,mid+1,r);

    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else{
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    }

    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    for(int i = 0,j = l;j <= r;j++,i++){
        q[j] = tmp[i];
    }

    return res;
}

int main()
{
    printf("plz input the total nums of the elements:");
    int n;
    scanf("%d",&n);
    printf("plz input the exact elements in the array:");
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    LL KKK = merge_sort_reverse_pairs(q,0,n-1);
    printf("the elements in the sorted array are:");
    for(int i = 0;i < n;i++){
        printf("%d ",q[i]);
    }
    cout << "\n";

    printf("the nums of the reverse pairs in the array is %lld",KKK);

    return 0;

}

