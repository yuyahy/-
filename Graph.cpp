#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 頂点数
    int cnt_vertex(0);

    cin >> cnt_vertex;
    vector<vector<int>> vecGraph(cnt_vertex,vector<int>(cnt_vertex,0));

    int num_vertex(0), cnt_exit_vertex(0);

    // 隣接行列を求める
    for (int i = 0; i < cnt_vertex; i++)
    {
        cin >> num_vertex >> cnt_exit_vertex;
        int num_next_vertex(0);
        for (int j = 0; j < cnt_exit_vertex; j++)
        {
            cin >> num_next_vertex;
            vecGraph[i][num_next_vertex-1] = 1;
        }
    }

    // 結果の出力
    for (int i = 0; i < cnt_vertex; i++)
    {
        for (int j = 0; j < cnt_vertex; j++)
        {
            if(j == cnt_vertex-1) {
                cout << vecGraph[i][j] << "\n";
            } else {
                cout << vecGraph[i][j] << " ";
            }
        }
    }
    
    return 0;
}
