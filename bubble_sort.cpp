#include <bits/stdc++.h>

// 配列出力関数
void OutputArray(int A[], int N)
{
    for (int x=0; x<N-1; x++) {
        // 空白区切りで出力
        std::cout << A[x] << " ";
    }
    std::cout << A[N-1] << std::endl;
}

// 結果出力
void DisplayResults(int A[], int N, int Cnt)
{
    OutputArray(A, N);
    std::cout << Cnt << std::endl;
}

// バブルソート実行関数
void BubbleSort(int R[], int N)
{
    // ソート回数をカウント
    int cnt_sort = 0;
    // 隣接要素が存在するか
    bool bIsAnyNext = true;
    
    // 二重for文でも書ける
    while(bIsAnyNext) {
        bIsAnyNext = false;
        for (int i=N-1; 0<i; i--) {
            if(R[i] <  R[i-1]) {
                // 自前でswap関数を実装したら
                // TLEになったのでstdで
                std::swap(R[i], R[i-1]);
                bIsAnyNext = true;
                cnt_sort++;
            }
        }
    }
    DisplayResults(R, N, cnt_sort);
}

int main()
{
    static const int MAX = 100;
    int n, R[MAX];
    std::cin >> n;
    
    for (int i=0; i<n; i++) std::cin >> R[i];
    
    BubbleSort(R, n);
    return 0;
}