#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long llong;

// 完全二分木の子の数(葉以外)
#define BINARY_CHILDREN_NUM 2

// 空きノードを示す定数
#define NIL 2100000000
// 要素の最大数
#define MAX 300


// 完全二分木ヒープの定義
struct BinaryHeap {
    int key, left, right, parent;
    };

struct BinaryHeap Heap[MAX];

// 完全二分木ヒープを出力する
void PrintHeap(int size)
{
    for (int i = 1; i < size+1; i++)
    {
        // 範囲外のキーは出力しない
        cout << "node " << i << ": key = "<< Heap[i].key << ", ";
        if(Heap[i].parent != NIL) cout << "parent key = " << Heap[Heap[i].parent].key << ", ";
        if(Heap[i].left != NIL) cout << "left key = " << Heap[Heap[i].left].key << ", ";
        if(Heap[i].right != NIL) cout << "right key = " << Heap[Heap[i].right].key << ", ";
        cout << "\n";
    }
}

int main()
{
    // 節点の個数
    int n = 0;
    // 次数
    int iDeg = 0;
    int iNodeIdx = 0;
    int left, node, root;

    cin >> n;

    // 初期化
    for (int i = 0; i < MAX; i++)
    {
        Heap[i].parent = Heap[i].left = Heap[i].right = NIL;
    }
    
    // 各ノードに対して、
    // その節点番号、子の情報を、
    // 記憶していく
    for (int i = 1; i < n+1; i++)
    {
        //キーを取得
        cin >> iNodeIdx;
        Heap[i].key = iNodeIdx;
        int tmp = 0;

        // 親・子を取得
        double ParentIdx = floor(i/2);
        if(ParentIdx > 0 && ParentIdx < n+1) Heap[i].parent = ParentIdx;

        tmp = 2 * i;
        if (tmp > 0 && tmp < n+1) Heap[i].left = tmp;
        
        tmp = 2 * i + 1;
        if (tmp > 0 && tmp < n+1) Heap[i].right = tmp;
    }

    // Nodeのindexごとに出力する
    PrintHeap(n);
    return 0;
}