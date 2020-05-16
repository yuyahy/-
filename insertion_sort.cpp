#include<iostream>
// 配列出力関数
void OutputArray(int A[], int N)
{
    for (int x=0; x<N-1; x++) {
        // 空白区切りで出力
        std::cout << A[x] << " ";
    }
    std::cout << A[N-1] << std::endl;
}
// 挿入ソート実行関数
void InsertionSort(int A[], int N)
{
    // ソート前
    OutputArray(A, N);
    for (int i=1; i<N; i++) {
        int v = A[i];
        int j = i-1;
        while(j>=0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        // ソート後
        OutputArray(A, N);    
    }
}

int main()
{
    static const int MAX = 100;
    int n, R[MAX];
    std::cin >> n;
    
    for (int i=0; i<n; i++) std::cin >> R[i];
    
    InsertionSort(R, n);
    return 0;
}