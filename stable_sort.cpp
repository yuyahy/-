#include <bits/stdc++.h>
// トランプの絵柄・数字から
// 数字だけを取り出す
int SplitNumberFromTrump(std::string A)
{
    int num_trump = 0;
    num_trump = stoi(A.substr(1));
    return num_trump;
}

// 配列出力関数
void OutputArray(std::string A[], int N)
{
    for (int x=0; x<N-1; x++) {
        // 空白区切りで出力
        std::cout << A[x] << " ";
    }
    std::cout << A[N-1] << std::endl;
}

// ソートされた配列が
// 安定か調べる
// →バブルソートは安定なので
// それと比較
bool IsStableArray(std::string A[], std::string A_Origin[], int N)
{
    for (int i=0; i<N; i++) {
        if (A[i].compare(A_Origin[i])) return false;
    }
    return true;
}

// 結果出力
void DisplayResults(std::string A[], int N, std::string A_Origin[])
{
    OutputArray(A, N);
    std::string stable = (IsStableArray(A, A_Origin, N))?  "Stable" : "Not stable";
    std::cout << stable << std::endl;
}

// 選択ソート実行関数
void SelectionSort(std::string R[], int N)
{
    int array_length = sizeof(R)/sizeof(R[0]);
    std::string R_Origin[array_length];
    std::copy(R, R + array_length, R_Origin);
    for (int i=0; i<N; i++) {
        // 初期化しないとRuntime Error
        int v = 0;
        int minVal = 100;
        for (int j=i; j<N; j++) {
            if (SplitNumberFromTrump(R[j]) < minVal) {
                minVal = SplitNumberFromTrump(R[j]);
                v = j;
            }
        }
        if (SplitNumberFromTrump(R[i]) != SplitNumberFromTrump(R[v])) {
            std::swap(R[i], R[v]);
        }
    }
}

// バブルソート実行関数
void BubbleSort(std::string R[], int N)
{
    int array_length = sizeof(R)/sizeof(R[0]);
    std::string R_Origin[array_length];
    std::copy(R, R + array_length, R_Origin);

    // 隣接要素が存在するか
    bool bIsAnyNext = true;
    
    // 二重for文でも書ける
    while(bIsAnyNext) {
        bIsAnyNext = false;
        for (int i=N-1; 0<i; i--) {
            if(SplitNumberFromTrump(R[i]) < SplitNumberFromTrump(R[i-1])) {
                // 自前でswap関数を実装したら
                // TLEになったのでstdで
                std::swap(R[i], R[i-1]);
                bIsAnyNext = true;
            }
        }
    }
}

int main()
{
    static const int MAX = 100;
    int n;
    std::string R[MAX];
    std::cin >> n;
    
    for (int i=0; i<n; i++) std::cin >> R[i];

    // 配列のコピー
    int array_length = sizeof(R)/sizeof(R[0]);
    std::string R2[MAX];
    std::copy(R, R + MAX, R2);

    BubbleSort(R, n);
    OutputArray(R,n);
    //  バブルソートは安定ソート
    std::cout << "Stable" << std::endl;

    SelectionSort(R2, n);
    DisplayResults(R2, n ,R);
    return 0;
}