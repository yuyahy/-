#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

// 二次元座標を表す構造体
struct Point
{
    double x;
    double y;

    Point () {
        x = 0;
        y = 0;
    }
    Point(double px, double py) {
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

    // 自身をスカラー倍する
    Point operator*(double scal)
    {
        x *= scal;
        y *= scal;
        return Point(x,y);
    }

    // 自身との内積を計算する
    double InnerProduct(Point p2)
    {
        return (x*p2.x + y*p2.y);
    }

    // 2点のベクトルの外積を計算する
    double OuterProduct(Point p2)
    {
        return (x*p2.y - y*p2.x);
    }

    // 自身のノルム(大きさの2乗)を返す
    double Norm()
    {
        return x*x + y*y;
    }

    // 自身のベクトルの大きさを返す
    double Magnitude()
    {
        return sqrt(Norm());
    }
};

using Vector = Point;


// 点p1、p2を結んだ線分に点p3を射影した時の座標を求める
Point CalcProjection(Point p1, Point p2, Point p3)
{
    // 始点p1→p3へのベクトル
    Vector vec1(p3.x-p1.x, p3.y-p1.y);
    // 始点p1→p2へのベクトル
    Vector vec2(p2.x-p1.x, p2.y-p1.y);

    double tmp = vec2.InnerProduct(vec1) / vec2.Norm();
    return p1 + vec2*tmp;
}

int main() {
    int x1(0), y1(0), x2(0), y2(0);
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1);
    Point p2(x2, y2);

    int q(0);
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x(0),y(0);
        cin >> x >> y;
        Point p3(x,y);
        Point res = CalcProjection(p1, p2, p3);
        // 小数点以下の桁数を指定する
        cout << std::fixed << std::setprecision(8) << res.x << " " << res.y << "\n";
    }
    return 0;
}