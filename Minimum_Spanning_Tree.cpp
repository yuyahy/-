#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
constexpr int MAX = 999999;

// 与えられた重み付きグラフから
// 最小全域木の辺の重みの総和を計算する
int CalcMinimumSpanningTree(vector<vector<int>> vecGraph)
{
    int sum(0);
    // 辺の選択状態を管理するmap
    map<int,bool> mapGraph;
    // 閉路にならない限り
    // 最小コストの辺を選択していく
    for (int i = 0; i < vecGraph.size(); i++)
    {
        int min = MAX;
        pair<int,int> min_pair(-1,-1);

        if ( mapGraph.size() >= vecGraph.size()-1) return sum;

        for (int j = 0; j < vecGraph.size(); j++)
        {
            // 閉路にならないかチェックする
            // 閉路になる条件は、
            // 両辺が選択済みの場合
           // if (mapGraph.count(i) && mapGraph.count(j)) {
            if (mapGraph.count(j)) {
                continue;
            }

            if(vecGraph[i][j] >0 && min > vecGraph[i][j]) {
                min_pair = make_pair(i,j);
                min = vecGraph[i][j];
            }
        }
        // 最小コストとなる辺を記録する
        // auto regpair1 = make_pair(min_pair.first,true);
        // mapGraph.insert(regpair1);
        auto regpair2 = make_pair(min_pair.second,true);
        mapGraph.insert(regpair2);
        //if (min_pair.first >= 0 && min_pair.second >= 0) {
        if (min_pair.second >= 0) {
            sum += min;
        }
    }
    return sum;
}

int main() {
    int n(0),tmp(0);
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

    cout << CalcMinimumSpanningTree(vecGraph) << "\n";
}