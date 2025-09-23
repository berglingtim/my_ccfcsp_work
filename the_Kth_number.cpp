#include<bits/stdc++.h>
using namespace std;

#define N 10010
int q[N];

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
 void quick_sort(int q[],int l,int r){
    while(l<r){
        int pivot_index = uniform_int_distribution<int>(l,r)(rng);
        int x = q[pivot_index];

        int i = l,j = r;
        int k = l;

        while(k <= j){
            if(q[k]<x) swap(q[k++],q[i++]);
            else if(q[k]>x) swap(q[k],q[j--]);
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

 int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&q[i]);
    quick_sort(q,0,n-1);
    for(int i =0;i < n;i++) printf("%d ",q[i]);
    printf("\nK的值是：");
    int k;
    scanf("%d",&k);
    printf("数组从小到大排列后，第k的数是:%d\n",q[k-1]);
    return 0;
 }
