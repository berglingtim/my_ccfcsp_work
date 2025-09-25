#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A); // 下面的循环是以A为例子，假如A更短会提前退出

    vector<int> C; // 用来存储大数
    int car = 0;   // 进位的暂时存储
    for (int i = 0; i < A.size(); i++)
    {
        car += A[i];
        if (i < B.size()) // 当B没有被遍历完的时候，才继续进行
            car += B[i];
        C.push_back(car % 10); // pushback的作用是在vector的末尾加上一个元素
        car /= 10;             // 进位进行保存，下次循环继续使用
    }

    if (car) // 如果结束循环之后car仍有说明首位需要进一
        C.push_back(car);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0'); // ASCII码来相减与数字相减是一样的
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0'); // 与上面一样，存储上是倒着的

    auto C = add(A, B); // auto自动判断是什么类型，这里明显是vector<int>

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;

    return 0;
}
