#include <bits/stdc++.h>
using namespace std;

// 深さ優先でグラフを探索
void DFS(int current, int prev, vector<int>& prenum, vector<int>& lowest,
vector<bool>& visted, vector<vector<int>> vecGraph, vector<int>& parent, int timer)
{
    // currentを訪問した処理
    prenum[current] = lowest[current] = timer;
    timer++;
    visted[current] = true;

    int next(0);
    for (int i = 0; i < vecGraph.size(); i++)
    {
        next = vecGraph[current][i];
        if(!visted[next]) {
            // 現在のノードから次のノードへ移動
            parent[next] = current;
            DFS(next, current, prenum, lowest, visted, vecGraph, parent, timer);

            // 次のノードが見つかった後の処理
            lowest[current] = min(lowest[current], lowest[next]);
        } else if(next != prev) {
            // 現在から次の頂点がBack Edgeの場合
            lowest[current] = min(lowest[current], prenum[next]);
        }
    }
}

void ArtPoints(vector<vector<int>> vecGraph)
{
    int size = vecGraph.size();
    vector<int> prenum(size), lowest(size), parent(size);
    vector<bool> visted(size);

    for(int i=0; i<visted.size(); i++) visted[i] = false;
    int timer = 1;
    // 根からのルートを記録する
    DFS(0, -1, prenum, lowest, visted, vecGraph, parent, timer);

    set<int> ap;
    int np = 0;
    for (int i = 1; i < parent.size(); i++)
    {
        int p = parent[i];
        if(p == 0) np++;
        else if(prenum[p] <= lowest[i]) ap.insert(p);
    }
    if(np > 1) ap.insert(0);
    for (auto itr = ap.begin(); itr != ap.end(); itr++)
    {
        cout << *itr << "\n";
    }
}

int main()
{
    int num_vertex(0),num_edge(0);
    cin >> num_vertex >> num_edge;

    // 各ノードの情報を管理する配列
    vector<vector<int>> vecGraph(num_vertex);

    for (int i = 0; i < num_edge; i++)
    {
        int edge1(0), edge2(0);
        cin >> edge1 >> edge2;

        // 無向グラフなので両方追加する
        vecGraph[edge1].push_back(edge2);
        vecGraph[edge2].push_back(edge1);
    }

    ArtPoints(vecGraph);

    return 0;
}