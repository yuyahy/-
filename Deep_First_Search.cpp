#include <bits/stdc++.h>
using namespace std;

// 各頂点の情報を管理する構造体
struct VertexInfo {
    // 頂点番号
    int id_vertex;
    // 最初に訪問した時刻
    int time_found;
    // 隣接リストを調べ終えた時刻
    int time_complete;
    VertexInfo(){
        id_vertex = 0;
        time_found = 0;
        time_complete = 0;
    }
};

int main()
{
    // 頂点数
    int cnt_vertex(0);
    // 時刻
    int time_stamp(0);

    cin >> cnt_vertex;

    vector<VertexInfo> vecGraph(cnt_vertex);
    // 一度訪問した頂点を詰める
    stack<int> stkVertex;

    int num_vertex(0), cnt_exit_vertex(0);

    // 隣接行列を求める
    for (int i = 0; i < cnt_vertex; i++)
    {
        cin >> num_vertex >> cnt_exit_vertex;
        int num_next_vertex(0);
        //vecGraph[i].id_vertex = 
        for (int j = 0; j < cnt_exit_vertex; j++)
        {
            cin >> num_next_vertex;
            stkVertex.push(num_next_vertex);
        }

    }

    // 結果の出力
    return 0;
}
