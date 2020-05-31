#include <bits/stdc++.h>

// 番兵を追加してwhile文で回す方が
// 二重for文で回すより若干速い
bool LinearSearch(int num, int A[], int n) {
    // 終了判定用の値を配列にセットする
    // →番兵
    // while文で必ずループ終了する事が保証されているので
    // 比較演算がfor文より一個少なくて済む
    A[n] = n;
    int i=0;
    while (A[i] != num) {
        // 末端まで見つからなかった
        if (i == n) return false;
        i++;
    }
    return true;
}

int main()
{
    static const int MAX = 20000;
    static const int MAX2 = 600;

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

    for (int m=0; m<s; m++) {
        if (LinearSearch(S[m], R, n)) cnt++;
    }
    std::cout << cnt << "\n";
    return 0;
}