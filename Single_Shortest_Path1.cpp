#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
constexpr int MAX = 999999;

struct NodeInfo {
  // このノードから伸びるエッジの情報
  vector<int> edges_to;    // 各エッジの接続先のノード番号
  vector<int> edges_cost;  // 各エッジのコスト

  // ダイクストラ法のためのデータ
  bool done;  // 確定ノードか否か
  int cost;   // このノードへの現時点で判明している最小コスト
  NodeInfo() {
      done = false;
      cost = MAX;
  }
};

// 頂点0から各頂点への最短経路を求める
void CalcMinimumShortestPath(vector<NodeInfo> vecNodes)
{
    // スタートは頂点0
    int nextidx = 0;
    vecNodes[nextidx].cost = 0;
    vecNodes[nextidx].done = true;

    while(true)
    {
        // 最短ノードを更新していく
        int min(0);
        

    }    
}

int main()
{
    int n(0);
    cin >> n;

    // 各ノードの情報を管理する配列
    vector<NodeInfo> vecNodes(n);
    for (int i = 0; i < n; i++)
    {
        int vertex_num(0),next_num(0), next_vertex(0), weight(0);
        cin >> vertex_num;
        cin >> next_num;
        
        for (int j = 0; j < next_num; j++)
        {
            cin >> next_vertex >> weight;
            vecNodes[vertex_num].edges_to.push_back(next_vertex);
            vecNodes[vertex_num].edges_cost.push_back(weight);
        }
    }

    // 頂点0から他の頂点への最短コストを求める
    

    return 0;
}