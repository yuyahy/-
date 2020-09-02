#include <bits/stdc++.h>
using namespace std;
// 比較用に十分大きい数値とする
constexpr int MAX = 9999999;

// 頂点の探索状態を表す
enum Vertex_State {
    // 未訪問
    NOT_VISIT = 0,
    // 訪問中(行きだけ)
    VISITING,
    // 訪問完了(行き・帰り)
    COMPLETE,
};

// 各ユーザの情報を管理する構造体
struct UserInfo {
    // 自身のユーザID
    int user_id;
    // 友達のリスト
    vector<int> vecFriend;
    UserInfo(){
        user_id = 0;
    }
};

// 指定された頂点に隣接する頂点群に
// 未訪問の頂点が存在するかを返す
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
    itr->second.state = Vertex_State::VISITING;
    stkVertex.push(itr->second.id_vertex);

    while (stkVertex.size() > 0)
    {
        time++;
        itr = mapGraph.find(stkVertex.top());

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

        // スタックのサイズが0でも、開始点から直接行けないが
        // まだ訪問していない頂点が残っている可能性があるので調べる
        if(stkVertex.size() == 0)
        {
            // 頂点の移動が必要なので時間を加算する
            time++;
            for(auto& vertex : mapGraph)
            {
                // 未訪問の頂点が残っていたら
                // 状態を訪問中に切り替えて、
                // スタックに詰めて再開する
                if(vertex.second.state == Vertex_State::NOT_VISIT) {
                    stkVertex.push(vertex.second.id_vertex);
                    vertex.second.state = Vertex_State::VISITING;
                    vertex.second.time_found = time;
                    break;
                }
            }
        }
    }
}

// 各頂点の訪問開始・終了時刻を出力する
void
PrintResult(map<int, VertexInfo> mapGraph)
{
    for(auto vertex : mapGraph)
    {
        cout << vertex.second.id_vertex << " " << vertex.second.time_found << " "
        << vertex.second.time_complete << "\n";
    }
}

int
main()
{
    // ユーザ数
    int num_user(0);
    // 有効関係の数
    int num_relation(0);

    cin >> num_user >> num_relation;

    map<int, UserInfo> mapGraph;
    int num_vertex(0), cnt_exit_vertex(0);

    int num_start_vertex(0);

    // 友人関係を保持する
    for (int i = 0; i < num_relation; i++)
    {
        int friend_id(0), self_id(0);
        cin >> self_id >> friend_id;
        // 既にユーザIDが登録されていたら
        // 友達リストに追加する
        if(mapGraph.count(self_id)) {
            auto itr = mapGraph.find(self_id);
            itr->second.vecFriend.push_back(friend_id);
        } else {
            UserInfo tmpUserInfo;
            tmpUserInfo.user_id = self_id;
            tmpUserInfo.vecFriend.push_back(friend_id);
            // 登録されていないユーザだったら新規追加する
            auto regPair = make_pair(self_id, tmpUserInfo);
            mapGraph.insert(regPair);
        }
    }

    // 質問を取得
    int num_question(0),start_user_id(0), end_user_id(0);
    for (int i = 0; i < num_question; i++)
    {
        cin >> start_user_id >> end_user_id;
        // たどり着けるかを判定する
    }
    

    // 深さ優先探索
    //DepthFirstSearch(mapGraph, num_start_vertex);

    // 結果の出力
    //PrintResult(mapGraph);

    return 0;
}
