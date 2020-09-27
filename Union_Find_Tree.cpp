#include <bits/stdc++.h>
using namespace std;

// クエリを表す
constexpr int UnionCmd = 0;
constexpr int IsSameCmd = 1;
// IsSameCmdの結果を表す
constexpr int SameCmdResNo = 0;
constexpr int SameCmdResYes = 1;

// Union-Findの構造体
//
// ※縦に長い木構造になっていた場合は
// このコードのままだと処理に時間がかかってしまう。
// 高速化したい場合は、
// ・経路圧縮
// ・ランク
// の処理を追加すること
struct UnionFind {
    // par[i] = jなら
    // データ:iの親はjであるの意
    vector<int> par;

    // データtgtの属する木の根を返す
    int root(int tgt) {
        if (par[tgt] == tgt) return tgt;
        int nextdata = par[tgt];
        // 再帰的に根を探す
        return root(nextdata);
    }

    // 同じ木でない2つの木を併合する
    void Unite(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        // 既に同じ木に属しているなら併合する必要はない
        if(root_x == root_y) return;
        // 異なる木に属していた場合は片方の根に付け替える
        par[root_x] = root_y;
    }

    // 2つのデータが同じ木に属しているか判定する
    bool IsSameTree(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        return root_x == root_y? true : false;
    }

    UnionFind(int N) : par(N) {
        // 最初は全て自分が根として初期化する
        for (int i = 0; i < N; i++) par[i] = i;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind Union(n);
    for (int i = 0; i < q; i++)
    {
        int command(0), x(0), y(0);
        cin >> command >> x >> y;
        if(command == UnionCmd) {
            Union.Unite(x, y);
        } else if(command == IsSameCmd) {
            int res = Union.IsSameTree(x, y)? SameCmdResYes : SameCmdResNo;
            cout << res << "\n";
        } else {
            // この処理に来ることはありえないはず
            ;assert(0);
        }
    }

    return 0;
}