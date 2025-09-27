#include <iostream>
#include <vector>

using namespace std;

bool greater_or_equal(vector<int> &A, vector<int> &B) // 用于判断数A是否大于等于数B
{                                                     // 大于等于则计算A-B，不加符号；
                                                      // 小于等于则计算B-A，加上负号
    if (A.size() != B.size())
        return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] != B[i])
            return A[i] > B[i];

    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, borrow = 0; i < A.size(); i++)
    {
        borrow = A[i] - borrow; // 假如我们的上一位相减小了，这一位就要进行借位，
                                //  上一次的借位要在这一次处理掉
        if (i < B.size())
            borrow -= B[i];              // 由于我们的处理方式，这里实际上是A[i] - borrow - B[i]
        C.push_back((borrow + 10) % 10); // 我们将得到的结果储存在了borrow里面，
                                         // 利用push_back我们得到此位结果
        if (borrow < 0)                  // 上一次相减的borrow小于0，则需要借位
            borrow = 1;
        else
            borrow = 0; // 大于0则表示没有发生借位
    }

    while (C.size() > 1 && C.back() == 0) // 将最后的结果删去多余的头部的0，
                                          // 假如得到的结果就是0，则只保留一位0
        C.pop_back();                     // pop_back是删除最后一个元素
    return C;
}

int main()
{
    // 注意事项，倒着存数字，倒着输入数字，其他全是正序
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    vector<int> C;

    if (greater_or_equal(A, B))
        C = sub(A, B);
    else
        C = sub(B, A), cout << '-';

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl;

    return 0;
}
