#include <bits/stdc++.h>
using namespace std;
typedef long long llong;
constexpr int MAX = 999999;

struct NodeInfo {
    // このノードから伸びるエッジの情報

    // 各エッジの接続先のノード番号
    vector<int> edges_to;
    // 各エッジのコスト
    vector<int> edges_cost;

    // ダイクストラ法のためのデータ

    // 最小コストが確定したか
    bool done;
    // このノードへの現時点で判明している最小コスト
    int cost;
    NodeInfo()
    {
        done = false;
        cost = MAX;
    }
};

// ダイクストラ法で頂点0から各頂点への最短経路を求める
// ※今回の問題では常に頂点番号 = 配列のインデックス
//  が成り立っているので、それを前提として動く作りになっている
//  より厳密に処理するなら、構造体で自身の頂点番号を保持する様にし、
//  その値を参照して処理する様に修正する必要がある
void CalcMinimumShortestPath(vector<NodeInfo>& vecNodes)
{
    // スタートは頂点0
    int nextidx = 0;
    vecNodes[nextidx].cost = 0;
    vecNodes[nextidx].done = true;
    bool isAnyVertex = true;

    while(isAnyVertex)
    {
        int min(MAX);
        int tmpnextidx(0);

        // 今いる頂点に隣接する頂点群の最小値が更新できれば更新する
        for (int i = 0; i < vecNodes[nextidx].edges_to.size(); i++)
        {
            int tmpcost = vecNodes[nextidx].cost + vecNodes[nextidx].edges_cost[i];
            int tmpidx = vecNodes[nextidx].edges_to[i];
            // 最小コストを更新
            if(vecNodes[tmpidx].cost > tmpcost){
                vecNodes[tmpidx].cost = tmpcost;
            }
        }

        // 最小値が確定していない頂点の中で
        // コストが最小の頂点を探す
        for(int j=0; j<vecNodes.size(); j++) {
            // 最小値が確定済 or 一回も最小値が更新されていない物は対象外
            if(vecNodes[j].done == true || vecNodes[j].cost == MAX) continue;
            if(min > vecNodes[j].cost) {
                min = vecNodes[j].cost;
                tmpnextidx = j;
            }
        }

        // 最小値が確定した頂点のフラグを立てる
        nextidx = tmpnextidx;
        vecNodes[nextidx].done = true;

        // 次の頂点が見つからなければ終了
        isAnyVertex = tmpnextidx == 0? false : true;
    }    
}

int main()
{
    int n(0);
    cin >> n;

    // 各ノードの情報を管理する配列
    vector<NodeInfo> vecNodes(n);
    
    // 各頂点の情報を記録する
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
    CalcMinimumShortestPath(vecNodes);

    // 結果を出力する
    for (int i = 0; i < vecNodes.size(); i++)
    {
        cout << i << " " << vecNodes[i].cost << "\n";
    }
    
    return 0;
}