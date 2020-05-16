#include<iostream>

int main() {
    static const int MAX = 200000;
    int n, R[MAX];
    
    // 要素数
    std::cin >> n;
    for (int i=0; i<n; i++) {
        std::cin >> R[i];
    }

    int minVal = R[0];
    // 利益が負になる可能性もあるので
    // 十分小さい値を初期値とする
    int maxVal = -2000000000;
    
    // 最大益を求める
    // 時系列順にしか、買う→売るができないので注意
    // →最大値、最小値を取得すれば良いわけではない
    for (int j=1; j<n; j++) {
        // 最高益の更新
        if (maxVal < R[j] - minVal) maxVal = R[j] - minVal;
        // 最小値の更新
        if (R[j] < minVal) minVal = R[j];
    }
    std::cout<< maxVal << std::endl;
    return 0;
}