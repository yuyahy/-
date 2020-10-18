#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

// 二次元座標を表す構造体
// ベクトル演算も扱う
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

    // 自身を始点として点p2となす線分に、
    // 点p3を射影した時の座標を求める
    Point Projection(Point p2, Point p3)
    {
        // 始点p1→p3へのベクトル
        Vector vec1(p3.x - x, p3.y - y);
        // 始点p1→p2へのベクトル
        Vector vec2(p2.x - x, p2.y - y);

        double tmp = vec2.InnerProduct(vec1) / vec2.Norm();
        return Point(x, y) + vec2 * tmp;
    }

    // 自身を始点として点p2となす線分に対して
    // 点p3と線対称になる点の座標を求める
    Point Reflection(Point p2, Point p3)
    {
        // 点p3から線分上に射影した点までのベクトル
        Vector vec1 = Projection(p2, p3) - p3;
        return p3 + vec1 * 2;
    }
    using Vector = Point;
};

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
        Point res = p1.Reflection(p2, p3);
        // 小数点以下の桁数を指定する
        cout << std::fixed << std::setprecision(8) << res.x << " " << res.y << "\n";
    }
    return 0;
}