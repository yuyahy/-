#include <bits/stdc++.h>
using namespace std;

// 与えられる点の数
constexpr int NUM_POINTS = 4;

// 二次元座標を表す構造体(整数のみ)
struct Point
{
    int x;
    int y;

    Point () {
        x = 0;
        y = 0;
    }
    Point(int px, int py) {
        x = px;
        y = py;
    }
    Point operator+(Point p2)
    {
        Point P_Add = Point(0, 0);
        
        P_Add.x = x + p2.x;
        P_Add.y = y + p2.y;
        return P_Add;
    }
    Point operator-(Point p2)
    {
        Point P_Min = Point(0, 0);

        P_Min.x = x - p2.x;
        P_Min.y = y - p2.y;
        return P_Min;
    }

    // 自身との内積を計算する
    int InnerProduct(Point p2)
    {
        return (x*p2.x + y*p2.y);
    }

    // 2点のベクトルの外積を計算する
    int OuterProduct(Point p2)
    {
        return (x*p2.y - y*p2.x);
    }
};

// 位置関係を表す
enum POSITION {
    PARALLELL = 1,
    ORTHOGONAL,
    NONE,
};

// 2直線が直交または平行しているか調べる
POSITION IsParallelorOrthogonal(Point p1, Point p2, Point p3, Point p4)
{
    int Res(0);
    Point vec1 = p2-p1;
    Point vec2 = p4-p3;
    // 直交判定
    if(!vec1.InnerProduct(vec2)) return ORTHOGONAL;
    // 平行判定
    else if(!vec1.OuterProduct(vec2)) return PARALLELL;
    // どちらでもなかった
    else return NONE;
}

int main() {
    int n;
    cin >> n;
    vector<Point> vecPnts;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < NUM_POINTS; j++)
        {
            int x(0), y(0);
            cin >> x >> y;
            Point pnt = Point(x, y);
            vecPnts.push_back(pnt);
        }
        // 平行・直行かを判定する
        POSITION Res = IsParallelorOrthogonal(vecPnts[0], vecPnts[1], vecPnts[2], vecPnts[3]);
        switch (Res)
        {
        case PARALLELL:
            cout << "2" << "\n";
            break;
        case ORTHOGONAL:
            cout << "1" << "\n";
            break;
        default:
            cout << "0" << "\n";
            break;
        }
        vecPnts.clear();
    }
    return 0;
}