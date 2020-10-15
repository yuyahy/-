#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

// 二次元座標を表す構造体(整数のみ)
struct Point
{
    double x;
    double y;

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

Point CalcProjection()
{
    
}

int main() {
    int x1(0), y1(0), x2(0), y2(0);
    cin >> x1 >> y1 >> x2 >> y2;
    int q(0);
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x(0),y(0);
        cin >> x >> y;

    }
}