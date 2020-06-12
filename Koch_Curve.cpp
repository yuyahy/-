#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long llong;
static const double pi = 3.141592653589793;

// 再帰的にコッホ曲線の座標を求める
// 関数の初めでdepthを-1するよりも
// 再帰で渡すときに-1しておけばよい
void CalcKochPoint(vector<pair<long double, long double>> point, int depth) {
    vector<pair<long double, long double>> nextpoint(100);
    pair<long double, long double> s, t, u;

    if (depth == 0) return;

    s.first = (2 * point[0].first + point[1].first) / 3;
    s.second = (2 * point[0].second + point[1].second) / 3;

    t.first = (point[0].first + 2 * point[1].first) / 3;
    t.second = (point[0].second + 2 * point[1].second) / 3;

    u.first = (t.first - s.first) * cos(pi/3) - (t.second - s.second) * sin(pi/3) + s.first;
    u.second = (t.first - s.first) * sin(pi / 3) + (t.second - s.second) * cos(pi / 3) + s.second;

    // // 線分(P1,s)について求める
    nextpoint[0].first = point[0].first;
    nextpoint[0].second = point[0].second;
    nextpoint[1].first = s.first;
    nextpoint[1].second = s.second;
    CalcKochPoint(nextpoint, depth-1);

    std::cout << s.first << setprecision(15) << " " << s.second << setprecision(15) <<"\n";

    // 線分(s,u)について求める
    nextpoint[0].first = s.first;
    nextpoint[0].second = s.second;
    nextpoint[1].first = u.first;
    nextpoint[1].second = u.second;
    CalcKochPoint(nextpoint, depth-1);

    std::cout << u.first << setprecision(15) <<" " << u.second << setprecision(15) <<"\n";

    // 線分(u,t)について求める
    nextpoint[0].first = u.first;
    nextpoint[0].second = u.second;
    nextpoint[1].first = t.first;
    nextpoint[1].second = t.second;
    CalcKochPoint(nextpoint, depth-1);

    std::cout << t.first << setprecision(15) <<" " << t.second <<setprecision(15) << "\n";

    // 線分(t,p2)について求める
    nextpoint[0].first = t.first;
    nextpoint[0].second = t.second;
    nextpoint[1].first = point[1].first;
    nextpoint[1].second = point[1].second;
    CalcKochPoint(nextpoint, depth-1);
}

int main() {
  vector<pair<long double, long double>> point(100);
  // 始点座標
  point[0].first = 0;
  point[0].second = 0;

  // 終点座標
  point[1].first = 100;
  point[1].second = 0;

  int n, k;
  cin >> n;

  std::cout << point[0].first << " " << point[0].second << "\n";
  CalcKochPoint(point, n);
  std::cout << point[1].first << " " << point[1].second << "\n";
}