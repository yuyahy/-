#include <bits/stdc++.h>

// 二分木探索
bool BinarySearch(int num, int A[], int n) {
    int left = 0;
    int right = n;
    int mid;

    // 配列の真ん中より、探す値が
    // 大きいか小さいか等しいかで
    // 調べる範囲を狭めていく
    while(right > left){
        mid = (right + left) / 2;
        // 見つかったら終了
        if (A[mid] == num) {
            return true;
        // 前半を探索
        } else if (A[mid] > num) {
            right = mid;
        // 後半を探索
        // A[mid]は等しくない事が保証されているので
        // mid + 1を開始位置とする
        } else if (A[mid] < num) {
            left = mid + 1;
        }
    }
    return false;
}

int main()
{
    static const int MAX = 200000;
    static const int MAX2 = 60000;
    int n, s, R[MAX], S[MAX2],tmp;
    int cnt = 0;

    std::cin >> n;
    for (int i=0; i<n; i++) {
        std::cin >> R[i];
    }
    std::cin >> s;
    for (int i = 0; i < s; i++)
    {
        std::cin >> S[i];
    }

    // 各数値があるか線形探索
    for (int m=0; m<s; m++) {
        if (BinarySearch(S[m], R, n)) cnt++;
    }
    std::cout << cnt << "\n";
    return 0;
}