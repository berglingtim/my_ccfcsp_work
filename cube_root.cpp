#include<bits/stdc++.h>

using namespace  std;

int main(){
    int x;
    scanf("%d",&x);//input the number and the calculate the cube root of it(x >= -10000 && x <= 10000)
    double l = -100;
    double r = 100;
    while(r-l > 1e-8){
        double mid = (l + r) / 2;
        if(mid*mid*mid >= x) r = mid;
        else l = mid;//这里已经不是数组了，所以不能以1为步长，否则会有极大的误差
    }
    printf("%f",l);
    return 0;

}

