#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 9999999;

enum Vertex_State {
    NOT_VISIT = 0,
    VISITING,
    COMPLETE,
};

// 各頂点の情報を管理する構造体
struct VertexInfo {
    // 頂点番号
    int id_vertex;
    // 最初に訪問した時刻
    int time_found;
    // 隣接リストを調べ終えた時刻
    int time_complete;
    // 隣接している頂点群
    vector<int> vecNextVertex;
    // 頂点の状態を表す
    Vertex_State state;

    VertexInfo(){
        id_vertex = 0;
        time_found = 0;
        time_complete = 0;
        state = NOT_VISIT;
    }
};

bool
IsAnyNoVisitNextVertex(map<int, VertexInfo>& mapGraph, int num_vertex)
{
    auto itr = mapGraph.find(num_vertex);
    for(auto vertex : itr->second.vecNextVertex)
    {
        auto tgtitr = mapGraph.find(vertex);
        // まだ訪問していない隣接頂点が見つかった
        if(tgtitr->second.state == Vertex_State::NOT_VISIT) {
            return true;
        }
    }
    // 訪問していない隣接頂点が見つからなかった
    return false;
}

// 深さ優先でグラフを探索し、
// 発見時刻と完了時刻を記録する
void
DepthFirstSearch(map<int, VertexInfo>& mapGraph, const int num_start_vertex)
{
    // 探索中の頂点群を保持するスタック
    stack<int> stkVertex;
    int time(1);
    auto itr = mapGraph.find(num_start_vertex);
    itr->second.time_found = time;
    stkVertex.push(itr->second.id_vertex);

    while (stkVertex.size() > 0)
    {
        time++;
        // 隣接する頂点が無かった場合
        if(!IsAnyNoVisitNextVertex(mapGraph,stkVertex.top())) {
            itr->second.time_complete = time;
            itr->second.state = Vertex_State::COMPLETE;
            stkVertex.pop();
        }
        else
        {
            // 次に訪問する頂点を決定する
            // 候補が複数ある場合は最小の物を優先する
            // 訪問済みの物は候補から除外する
            int min(MAX);
            for(auto vertex : itr->second.vecNextVertex)
            {
                auto nextitr = mapGraph.find(vertex);
                if (nextitr->second.state != Vertex_State::NOT_VISIT) continue;
                if (min > nextitr->second.id_vertex) min = nextitr->second.id_vertex;
            }
            itr = mapGraph.find(min);
            itr->second.state = Vertex_State::VISITING;
            itr->second.time_found = time;
            stkVertex.push(min);
        }
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

    DepthFirstSearch(mapGraph, num_start_vertex);

    // 結果の出力
    return 0;
}
