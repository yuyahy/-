#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 3000000
#define VALMAX 20000

// 計数ソート実行関数
void CountingSort(vector<int>& vecA, vector<int>& vecB, int k, int n)
{
    vector<int> vecC;
    vecC.reserve(VALMAX);

    for (int i = 0; i < k; i++)
    {
        vecC[i] = 0;
    }
    
    // vecC[i]にiの出現数を記録する
    for (int j = 1; j <= n; j++)
    {
        vecC[vecA[j]] = vecC[vecA[j]] + 1;
    }

    // vecC[i]にi以下の数の出現数を記録する
    for (int i = 1; i <= k; i++)
    {
        vecC[i] = vecC[i] + vecC[i-1];
    }

    for (int j = n; j >= 1; j--) {
        vecB[vecC[vecA[j]]] = vecA[j];
        vecC[vecA[j]] = vecC[vecA[j]] - 1;
    }
}

int main() {
    vector<int> vec_in, vec_out;
    vec_in.reserve(MAX);
    vec_out.reserve(MAX);

    int n = 0;
    int m = 0;
    char str[200];

    scanf("%d",&n);

    for (int i=0; i<n; i++)
    {
        scanf("%d",&m);
        vec_in[i] = m;
        //printf("%d\n", vec_in[i]);
    }

    CountingSort(vec_in, vec_out, VALMAX, n);

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d\n", vec_out[i]);
        }
        else
        {
            printf("%d ", vec_out[i]);
        }
    }

}