#include <bits/stdc++.h>
using namespace std;
// 比較用に十分大きい数値とする
constexpr int MAX = 9999999;
// 始点・訪問できない頂点用
constexpr int STARTPOINT = -1;

// 頂点の探索状態を表す
enum Vertex_State {
    // 未訪問
    NOT_VISIT = 0,
    // 訪問中(行きだけ)
    VISITING,
    // 訪問完了(行き・帰り)
    COMPLETE,
};

// 各頂点の情報を管理する構造体
struct VertexInfo {
    // 頂点番号
    int id_vertex;
    // 頂点1からの最短距離
    int numdistance;
    // 隣接している頂点群
    vector<int> vecNextVertex;
    // 頂点の状態を表す
    Vertex_State state;

    VertexInfo(){
        id_vertex = 0;
        numdistance = MAX;
        state = NOT_VISIT;
    }
};

// 幅優先でグラフを探索し、
// 発見時刻と完了時刻を記録する
void
BreadthFirstSearch(map<int, VertexInfo>& mapGraph, const int num_start_vertex, int distance)
{
    // 再帰的に隣接する辺を調べる
    auto itr = mapGraph.find(num_start_vertex);
    distance++;
    // 2回目に訪問した際に
    // 最短距離を更新できなければ
    // その先をもう一度探索する必要はない
    if (itr->second.numdistance > distance) {
        itr->second.numdistance = distance;
    } else {
        return;
    }

    itr->second.state = Vertex_State::VISITING;
    // 隣接する頂点を再帰的に探索する
    for(auto vertex : itr->second.vecNextVertex)
    {
        BreadthFirstSearch(mapGraph, vertex,distance);
    }
}

// 各頂点の訪問開始・終了時刻を出力する
void
PrintResult(map<int, VertexInfo> mapGraph)
{
    for(auto vertex : mapGraph)
    {
        cout << vertex.second.id_vertex << " " << vertex.second.numdistance << "\n";
    }
}

int
main()
{
    // 頂点数
    int cnt_vertex(0);
    // 時刻
    int time_stamp(0);

    cin >> cnt_vertex;

    map<int, VertexInfo> mapGraph;
    int num_vertex(0), cnt_exit_vertex(0);

    int num_start_vertex(0);

    // 隣接行列を求める
    for (int i = 0; i < cnt_vertex; i++)
    {
        VertexInfo tmpInfo;
        cin >> num_vertex >> cnt_exit_vertex;
        int num_next_vertex(0);
        tmpInfo.id_vertex = num_vertex;

        // 開始頂点を記録しておく
        if(i==0) num_start_vertex = num_vertex;

        for (int j = 0; j < cnt_exit_vertex; j++)
        {
            cin >> num_next_vertex;
            tmpInfo.vecNextVertex.push_back(num_next_vertex);
        }
        // mapに登録
        auto regpair = make_pair(num_vertex, tmpInfo);
        mapGraph.insert(regpair);
    }

    // 幅優先探索
    BreadthFirstSearch(mapGraph, num_start_vertex, STARTPOINT);

    // 訪問できなかった頂点の最短距離を設定する
    for (auto& vertex : mapGraph)
    {
        if(vertex.second.state == Vertex_State::NOT_VISIT) {
            vertex.second.numdistance = STARTPOINT;
        }
    }
    
    // 結果の出力
    PrintResult(mapGraph);

    return 0;
}
