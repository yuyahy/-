#include <bits/stdc++.h>

// 積載量Pに対して積むことのできる
// 荷物の数を返す
int BaggageAmount(int P, std::vector<int> vecW, int& idx, int n) {
    int sum = 0;
    int i = 0;
    // 積載量P以下の限り
    // 順番に荷物を積み続ける
    while (true) {
        // 積載量Pを超える前に終了
        if (sum + vecW[idx+i] > P) break;
        if (i == n) break;
        sum += vecW[idx+i];
        i++;
    }
    idx += i;
    return i;
}

int main()
{
    int n = 0;
    int k = 0;
    int w = 0;
    int sum = 0;
    std::vector<int> vecW (200000, 0);

    // 荷物の個数を取得
    std::cin >> n;

    // トラックの台数を取得
    std::cin >> k;

    for (int i = 0; i < n; i++)
    {
        std::cin >> w;
        vecW[i] = w;
    }

    int P = 0;
    int idx = 0;
    int left = 0;

    // 必要積載量 P の最大値 = 積載量荷物 * 重量の最大値
    int right = 100000 * 10000;
    int mid = 0;

    // 二分木探索で最小となるPを探す
    while (right > left) {
        sum = 0;
        idx = 0;
        mid = (right + left) / 2;
        for (int i = 0; i < k; i++)
        {
            sum += BaggageAmount(mid, vecW, idx, n);
        }
        if (sum < n) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    std::cout << right <<"\n";
    return 0;
}