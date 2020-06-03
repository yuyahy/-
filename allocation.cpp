#include <bits/stdc++.h>

#define MAX 200023
#define M 200017

// 積載量Pに対して積むことのできる
// 荷物の数を返す
int BaggageAmount(int P, std::vector<int> vecW, int& idx) {
    int sum = 0;
    int i = 0;
    // 積載量P以下の限り
    // 順番に荷物を積み続ける
    while (true) {
        if (sum + vecW[idx] > P) break;
        sum += vecW[idx+i];
        i++;
    }
    idx += i;
    return i;
}

int main()
{
    int n, k, w, sum;
    std::vector<int> vecW;

    // 荷物の個数を取得
    std::cin >> n;
   // std::cout << n << "\n";

    // トラックの台数を取得
    std::cin >> k;
    //std::cout << k << "\n";

    for (int i = 0; i < n; i++)
    {
        std::cin >> w;
        vecW.push_back(w);
    }
    //std::cout << BaggageAmount(10, vecW) << "\n";

    int P = 0;
    int idx = 0;
    while (sum < n) {
        sum = 0;
        idx = 0;
        P++;
        for (int i = 0; i < k; i++)
        {
            sum += BaggageAmount(P, vecW, idx);
            std::cout << "P = " << P <<"idx = "<< idx <<"\n";
        }
    }
    std::cout << P <<"\n";
    return 0;
}