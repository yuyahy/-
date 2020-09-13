#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
constexpr int MAX = 999999;

// 与えられた重み付きグラフから
// 最小全域木の辺の重みの総和を計算する(プリム法)
int CalcMinimumSpanningTree(vector<vector<int>> vecGraph, int size)
{
    int sum(0);
    // 訪問した頂点を格納する集合
    set<int> setVistedVertexs;

    // 適当な開始点からスタート
    // ここでは頂点0とする
    setVistedVertexs.insert(0);

    // これまでに訪問した頂点から行ける
    // 未訪問の頂点の中で最小コストな頂点を選択する
    // これを全ての頂点を訪問するまで繰り返す
    while (setVistedVertexs.size() != size)
    {
        // <頂点番号、コスト>のペア
        pair<int, int> min;
        min.first = MAX;
        for (auto vertex : setVistedVertexs)
        {
            for (int i = 0; i < size; i++)
            {
                // 訪問済みの辺の場合はスキップ
                if(setVistedVertexs.count(i)) continue;
                if (vecGraph[vertex][i] >= 0 && min.first > vecGraph[vertex][i])
                {
                    // 最小値ならその値と新規頂点を保持しておく
                    min.first = vecGraph[vertex][i];
                    min.second = i;
                }
            }
        }
        // 訪問済み頂点リストに追加
        setVistedVertexs.insert(min.second);
        sum += min.first;
    }
    return sum;
}

int main()
{
    int n(0), tmp(0);
    cin >> n;
    vector<vector<int>> vecGraph(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            vecGraph[i][j] = tmp;
        }
    }

    cout << CalcMinimumSpanningTree(vecGraph, n) << "\n";
}