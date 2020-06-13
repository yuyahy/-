#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
#define MAX 600000
// 予想される要素の最大値以上の値(番兵)
#define INFTY 2000000000

// 
int merge(vector<int>& vec, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> vec_L;
    vector<int> vec_R;

    // あらかじめvectorの要素数がわかっているのなら
    // reserveで確保しておいた方が速い
    // 少し多めに確保しておく(RE対策)
    // また、reserveしておかないとREになった
    vec_L.reserve(n1 + 1);
    vec_R.reserve(n2 + 1);

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
    vec_L[n1] = INFTY;
    vec_R[n2] = INFTY;
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
        if (vec_L[i] <= vec_R[j]) {
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
void merge_sort(vector<int>& vec, int left, int right, int& cnt)
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

int main()
{
    vector<int> vec;
    vec.reserve(MAX);
    int n = 0;
    int m = 0;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&m);
        vec.push_back(m);
    }

    int cnt = 0;
    merge_sort(vec, 0, n, cnt);

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d\n", vec[i]);
        }
        else
        {
            printf("%d ", vec[i]);
        }
    }
    printf("%d\n", cnt);
}