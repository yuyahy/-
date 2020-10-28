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

    // 自身をスカラーで割算する
    Point operator/(double scal)
    {
        x /= scal;
        y /= scal;
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

    // 自身と点p2からなる線分と点p3、p4からなる線分の距離を求める
    double CalcDistanceLineToLine(Point p2, Point p3, Point p4)
    {
        Point p1 = Point(x, y);
        if(p1.IsInterSection(p2, p3, p4)) return 0.0;
        return min(min(p3.CalcDistanceLineToP(p1, p2), p4.CalcDistanceLineToP(p1, p2)),
                    min(p1.CalcDistanceLineToP(p3, p4), p2.CalcDistanceLineToP(p3, p4)));
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

    //  自身と点p2からなる線分と点p3、p4からなる線分の交点を求める
    Point RetriveCrossPoint(Point p2, Point p3, Point p4)
    {
        Point p1(x, y);
        Vector vec1 = p4 - p3;
        double d1 = std::abs(vec1.OuterProduct(p1-p3));
        double d2 = std::abs(vec1.OuterProduct(p2-p3));
        double ratio = d1 / (d1 + d2);
        return p1 + (p2 - p1) * ratio;
    }
    
    using Vector = Point;
    using Line = Point;
};

struct Circle {
    double m_Center_x;
    double m_Center_y;
    double m_radius;
    Point m_Center;

    Circle()
    {
        m_Center_x = 0;
        m_Center_y = 0;
        m_radius = 0;
        m_Center = Point();
    }

    Circle(double px, double py, double r)
    {
        m_Center_x = px;
        m_Center_y = py;
        m_radius = r;
        m_Center = Point(m_Center_x, m_Center_y);
    }

    // 自身の円と点p1、p2からなる線分の交点を求める
    void RetriveCrossPointCircleToLine(Point p1, Point p2, vector<Point>& vecRes)
    {
        // 円の中心を線分に射影した点を求める
        //Point p_proj = p1.Projection(p2, m_Center);
        Point p_proj = p1.Projection(p2, m_Center);
        // 線分p1p2の単位ベクトルを求める
        Vector vecUnit = (p2-p1) / (p2-p1).Magnitude();
        // 円に含まれる線分の長さの半分を求める
        double base = sqrt(m_radius * m_radius - (p_proj - m_Center).Norm());
        // 交点を求める
        Point p_cross1, p_cross2;
        p_cross1 = p_proj + (vecUnit * base);
        p_cross2 = p_proj - (vecUnit * base);
        // x座標が小さいものから先頭に詰める
        // x座標が同じの場合はy座標が小さい点から詰める
        if(p_cross1.x > p_cross2.x) {
            vecRes.push_back(p_cross2);
            vecRes.push_back(p_cross1);
        } else if(p_cross2.x > p_cross1.x) {
            vecRes.push_back(p_cross1);
            vecRes.push_back(p_cross2);
        } else {
            if(p_cross1.y > p_cross2.y) {
                vecRes.push_back(p_cross2);
                vecRes.push_back(p_cross1);
            } else {
                vecRes.push_back(p_cross1);
                vecRes.push_back(p_cross2);
            }
        }
    }

    Point Polar(double a, double r)
    {
        return Point(std::cos(r) * a, std::sin(r) * a);
    }

    // 自身の円と与えられた円の交点を求める
    void RetriveCrossPointCircles(Circle cir2, vector<Point>& vecRes)
    {
        Circle cir1(m_Center_x, m_Center_y, m_radius);
        double dCenterDist = (cir1.m_Center - cir2.m_Center).Magnitude();
        // 余弦定理を用いて中心と交点を通るベクトルがなす角度を求める
        double dIntersectAng = std::acos((cir1.m_radius * cir1.m_radius + dCenterDist * dCenterDist
                                            - cir2.m_radius * cir2.m_radius) / (2 * cir1.m_radius * dCenterDist));
        double dtangentAng = std::atan2(cir2.m_Center.y - cir1.m_Center.y,
                                             cir2.m_Center.x - cir1.m_Center.x);
        
        Point p_cross1 = cir1.m_Center + Polar(cir1.m_radius, dtangentAng + dIntersectAng);
        Point p_cross2 = cir1.m_Center + Polar(cir1.m_radius, dtangentAng - dIntersectAng);

        // x座標が小さいものから先頭に詰める
        // x座標が同じの場合はy座標が小さい点から詰める
        if (p_cross1.x > p_cross2.x)
        {
            vecRes.push_back(p_cross2);
            vecRes.push_back(p_cross1);
        }
        else if (p_cross2.x > p_cross1.x)
        {
            vecRes.push_back(p_cross1);
            vecRes.push_back(p_cross2);
        }
        else
        {
            if (p_cross1.y > p_cross2.y)
            {
                vecRes.push_back(p_cross2);
                vecRes.push_back(p_cross1);
            }
            else
            {
                vecRes.push_back(p_cross1);
                vecRes.push_back(p_cross2);
            }
        }
    }
    using Vector = Point;
};

int main() {
    int x(0), y(0), r(0), x2(0), y2(0), r2(0);
    cin >> x >> y >> r;
    Circle cir1(x, y, r);
    cin >> x2 >> y2 >> r2;
    Circle cir2(x2, y2, r2);

    // 小数点以下の桁数を指定する
    vector<Point> vecRes;
    cir1.RetriveCrossPointCircles(cir2, vecRes);
    cout << std::fixed << std::setprecision(8) << vecRes[0].x <<
    " " << vecRes[0].y << " " << vecRes[1].x << " " << vecRes[1].y << "\n";

    return 0;
}