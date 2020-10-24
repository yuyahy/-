#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

// 二次元座標を表す構造体
// ベクトル演算も扱う
struct Point
{
    double x;
    double y;

    // 他の直線との関係を表す
    // 交差判定にも使用する
    enum PositonRelate {
        COUNTER_CLOCKWISE = 1,
        CLOCKWISE = -1,
        ONLINE_BACK = 2,
        ONLINE_FRONT = -2,
        ON_SEGMENT = 0,
        NONE = -999,
    };

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

    // 自身ともう一点の距離を求める
    double CalcDistancePtoP(Point p)
    {
        Point tmp = p - Point(x, y);
        return tmp.Magnitude();
    }

    // 自身と2点を通る直線間の距離を求める
    double CalcDistanceLineToP(Point p2, Point p3)
    {
        Point tmp = Point(x, y); 
        Vector vec1 = p3-p2; 
        Vector vec2 = tmp - p2;
        return vec1.OuterProduct(vec2) / vec1.Magnitude();
    }

    // 自身と2点を通る線分間の距離を求める
    double CalcDistanceSegmentToP(Point p2, Point p3)
    {
        Point p = Point(x, y);
        if((p3-p2).InnerProduct(p-p2) < 0.0) return (p-p2).Magnitude();
        if((p2-p3).InnerProduct(p-p3) < 0.0) return (p-p3).Magnitude();
        return p.CalcDistanceLineToP(p2, p3);
    }

    // 自身と他の2点の位置関係を調べる
    PositonRelate JudgePosition3Points(Point p2, Point p3)
    {
        // 外積・内積を利用して3点の位置関係を調べる
        Point p1 = Point(x, y);
        Vector vec1 = p2-p1;
        Vector vec2 = p3-p1;

        double res_outer = vec1.OuterProduct(vec2);
        double res_inner = vec1.InnerProduct(vec2);
        // 反時計回り
        if (res_outer > 0)
        {
            return COUNTER_CLOCKWISE;
        }
        // 時計回り
        else if (res_outer < 0)
        {
            return CLOCKWISE;
        }
        // p3→p1→p2の順番で一直線上
        else if (res_inner < 0)
        {
            return ONLINE_BACK;
        }
        // p1→p1→p3の順番で一直線上
        else if (res_inner >= 0 && vec1.Magnitude() < vec2.Magnitude())
        {
            return ONLINE_FRONT;
        }
        // p3線分p1p2上に存在する
        else if (res_inner >= 0 && vec1.Magnitude() >= vec2.Magnitude())
        {
            return ON_SEGMENT;
        } else {
            ;assert(0);
            return NONE;
        }
    }

    // 自身と点p2からなる線分と点p3、p4からなる線分が交差するか判定する
    bool IsInterSection(Point p2, Point p3, Point p4)
    {
        Point p1(x, y);
        return (p1.JudgePosition3Points(p2,p3) * p1.JudgePosition3Points(p2,p4) <= 0 &&
                    p3.JudgePosition3Points(p4,p1) * p3.JudgePosition3Points(p4,p2) <= 0);
    }
    
    using Vector = Point;
    using Line = Point;
};

int main()
{
    int q(0);
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x1(0), y1(0), x2(0), y2(0), x3(0), y3(0), x4(0), y4(0);
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Point p1(x1, y1);
        Point p2(x2, y2);
        Point p3(x3, y3);
        Point p4(x4, y4);
        int res = p1.IsInterSection(p2, p3, p4)? 1 : 0;
        cout << res << "\n";
    }
    return 0;
}