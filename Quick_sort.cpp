#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 200000
// 予想される要素の最大値以上の値(番兵)
#define INFTY 2000000000

// 与えられたvectorを最後のインデックスの
// 要素の大小で分割する
int Partition(vector<pair<string, int>>& vec_A, int p, int r)
{
    int x = vec_A[r].second;
    int i = p - 1;
    pair<string, int> tmp("", 0);
    for (int j = p; j < r; j++)
    {
        if (vec_A[j].second <= x) {
            i++;
            tmp = vec_A[i];
            vec_A[i] = vec_A[j];
            vec_A[j] = tmp;
        }
    }
    tmp = vec_A[i+1];
    vec_A[i+1] = vec_A[r];
    vec_A[r] = tmp;

    return i+1;
}

void Quick_Sort(vector<pair<string, int>>& vec_A, int p, int r)
{
    int idx = 0;
    // 末端までソートすると
    // idx + 1 = rとなり終了
    if (p < r) 
    {
        // 分割位置を取得する
        idx = Partition(vec_A, p, r);
        // 前半部分についてQuickSort
        Quick_Sort(vec_A, p, idx - 1);
        // 後半部分についてQuickSort
        Quick_Sort(vec_A, idx + 1, r);
    }
}

int merge(vector<pair<string, int>>& vec, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<pair<string, int>> vec_L;
    vector<pair<string, int>> vec_R;

    // あらかじめvectorの要素数がわかっているのなら
    // reserveで確保しておいた方が速い
    // 少し多めに確保しておく(RE対策)
    // また、reserveしておかないとREになった
    vec_L.reserve(n1 + 1000);
    vec_R.reserve(n2 + 1000);

    // 元の配列を2分割して
    // それぞれ配列に詰める
    for (int i = 0; i < n1; i++)
    {
        vec_L[i] = vec[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        vec_R[i] = vec[mid + i];
    }
    vec_L[n1].second = INFTY;
    vec_R[n2].second = INFTY;
    int i = 0;
    int j = 0;
    int cnt = 0;
    // ソート済みの分割した配列、vec_L、VecRを
    // マージして整列させる
    // 両配列の先頭要素を比較して
    // 小さい方を配列に詰めていく
    // 等しい場合は常に左側の分割配列を採用すれば
    // 安定なソートとなる
    for (int k = left; k < right; k++)
    {
        if (vec_L[i].second <= vec_R[j].second) {
            vec[k] = vec_L[i];
            i++;
        } else {
            vec[k] = vec_R[j];
            j++;
        }
        cnt++;
    }
    return cnt;
}

// マージソートを実行する
// 与えられた配列を2分割して
// merge()に渡す
// 右・左の配列の要素数が1個ずつになるまで
// 再帰的に分解したら,統合していく
void merge_sort(vector<pair<string, int>>& vec, int left, int right, int& cnt)
{
    int mid = 0;
    if (left+1 < right)
    {
        mid = (left + right) / 2;
        // 左側を整列
        merge_sort(vec, left, mid, cnt);
        // 右側を整列
        merge_sort(vec, mid, right, cnt);
        // 統合する
        cnt += merge(vec, left, mid, right);
    }
}

int main() {
    vector<pair<string, int>> vec_in, vec_out;
    vec_in.reserve(MAX);
    vec_out.reserve(MAX);

    int n = 0;
    int m = 0;
    char str[200];

    scanf("%d",&n);

    for (int i=0; i<n; i++)
    {
        scanf("%s %d",str, &m);
        vec_in[i].first = str;
        vec_in[i].second = m;
        vec_out[i].first = str;
        vec_out[i].second = m;

    }

    // nを渡すと範囲オーバーになるので注意
    Quick_Sort(vec_in, 0, n-1);

    int cnt = 0;
    merge_sort(vec_out, 0, n, cnt);

    // 安定なソートか調べる
    // mergesortと結果が同じなら安定
    string res = res = "Stable";;
    for (int i = 0; i < n; i++)
    {
        if (vec_in[i].first != vec_out[i].first)
        {
            res = "Not stable";
        }
    }

    printf("%s\n", res.c_str());

    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", vec_in[i].first.c_str(), vec_in[i].second);
    }
}