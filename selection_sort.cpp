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

// 選択ソート実行関数
void SelectionSort(int R[], int N)
{
    // ソート回数をカウント
    int cnt_sort = 0;
    for (int i=0; i<N; i++) {
        // 初期化しないとRuntime Error
        int v = 0;
        int minVal = 100;
        for (int j=i; j<N; j++) {
            if (R[j] < minVal) {
                minVal = R[j];
                v = j;
            }
        }
        if (R[i] != R[v]) {
            std::swap(R[i], R[v]);
            cnt_sort++;
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
    
    SelectionSort(R, n);
    return 0;
}