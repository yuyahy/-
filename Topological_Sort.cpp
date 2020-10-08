#include <bits/stdc++.h>
using namespace std;

// トポロジカルソートを実行する
vector<int> TopologicalSort(vector<vector<int>> vecGraph, vector<int> vecEdges)
{
    // 処理する頂点のインデックス
    int idx(0);

    // 処理待ちの頂点を詰める
    queue<int> edgeque;

    // 入次数が0の頂点を集める
    for (int i = 0; i < vecEdges.size(); i++)
    {
      if (vecEdges[i] == 0)
      {
        edgeque.push(i);
      }
    }

    // 出力する配列
    vector<int> vecTopo;

    while (!edgeque.empty())
    {
      // 出次数0の頂点を取り出す
      idx = edgeque.front();
      edgeque.pop();
      // 隣接する頂点の出次数を減算する
      for(auto edge : vecGraph[idx]) {
          vecEdges[edge] -= 1;
          if(vecEdges[edge] == 0) edgeque.push(edge);
      }
      vecTopo.push_back(idx);
    }

  return vecTopo;
}

int main() {
    int num_vertex(0),num_edge(0);
    cin >> num_vertex >> num_edge;

    // 各ノードの情報を管理する配列
    vector<vector<int>> vecGraph(num_vertex);
    // 各頂点の入次数を記録する配列
    vector<int> vecEdges(num_vertex,0);

    for (int i = 0; i < num_edge; i++)
    {
      int edge1(0), edge2(0);
      cin >> edge1 >> edge2;
      vecGraph[edge1].push_back(edge2);
      vecEdges[edge2] += 1;
    }

    vector<int> vecRes = TopologicalSort(vecGraph, vecEdges);
    for (auto edge : vecRes)
    {
      cout << edge << "\n";
    }
    return 0;
}