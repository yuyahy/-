#include<iostream>

// 配列出力関数
void OutputArray(int A[], int N)
{
    for (int x=0; x<N-1; x++) {
        // 改行切りで出力
        std::cout << A[x] << std::endl;
    }
    std::cout << A[N-1] << std::endl;
}

// 配列出力関数
void OutputArray2(int A[], int N)
{
    for (int x=N-1; x>0; x--) {
        // 改行切りで出力
        std::cout << A[x] <<" ";
    }
    std::cout << A[0] << std::endl;
}

// 挿入ソート実行関数
int InsertionSort(int A[], int N, int g)
{
    int i = 0, cnt =0;
    for (int i=g; i<N; i++) {
        //cnt = 0;
        int v = A[i];
        int j = i-g;
        while(j>=0 && A[j] > v) {
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g] = v;
    }
    return cnt;
}

// シェルソート実行関数
void ShellSort(int A[], int N)
{
    int m = 0, i =  0, cnt = 0;
    int G[N];
    G[0] = 1;

    // A[N] = A[N-1]*3 +1
    // が計算効率が良いらしい
    while (G[i]<=N)
    {
        i++;
        G[i] = G[i-1]*3 + 1;
    }

    for (int k = i-1; k >= 0; k--)
    {
        cnt += InsertionSort(A, N, G[k]);
    }
    std::cout<< i <<std::endl;
    OutputArray2(G, i);
    std::cout<< cnt <<std::endl;
    OutputArray(A, N);
}

int main()
{
    static const int MAX = 1000000;
    int n, R[MAX];
    std::cin >> n;
    for (int i=0; i<n; i++) std::cin >> R[i];

    ShellSort(R, n);
    return 0;
}