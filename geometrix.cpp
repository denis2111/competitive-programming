#include <bits/stdc++.h>
using namespace std;

#define eps 0.000000001
#define INF 2000000000
class Point{
public:
    long double
     x, y;
    Point() : x(0), y(0){}
    Point(long double _x, long double _y) : x(_x), y(_y){}

    bool operator==(const Point &oth) const {return x == oth.x && y == oth.y;}
    bool operator< (const Point &oth) const {return x == oth.x ? y < oth.y : x < oth.x;}

    long double dist(Point B){
        return sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
    }

    friend ostream &operator<<( ostream &output, const Point &P ) {
        output << P.x << " " << P.y;
        return output;
    }

    friend istream &operator>>( istream &input, Point &P ) {
         input >> P.x >> P.y;
         return input;
    }
};

class Geom{
public:
    static long double det(Point A, Point B, Point C){
         return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
    }

    // rotate plane with angle
    static void rotate(vector<Point> &points, long double angle = 0){
        if (abs(angle) < eps){
            unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
            std::mt19937 generator(seed1);
            std::uniform_real_distribution<long double> distribution(0.0, 3.14);

            angle = distribution(generator);
        }

        for (auto &it : points){
            long double x = it.x * cos(angle) - it.y * sin(angle);
            long double y = it.x * sin(angle) + it.y * cos(angle);
            it = {x,y};
        }
    }
};

class ConvexHull{
private:
    static Point bst;

    static bool comp(Point &A, Point &B){
        if (B == bst) return false;
        int x = Geom::det(bst,A,B);
        if (abs(x) < eps) return bst.dist(A) < bst.dist(B);
        return x < 0;
    }

public:

    vector<Point> getConvexHull(vector<Point> points){
        if (points.size() <= 1) return points;

        bst = points[0];
        for (auto &it : points) bst = min(bst, it);

        sort(points.begin(),points.end(),comp);

        vector<Point> H({points[0], points[1]});
        for (int i=2;i<(int)points.size();i++){
            while (H.size() >= 2 && (Geom::det(H[H.size() - 2], H.back(), points[i]) > 0 ||
                   (Geom::det(H[H.size() - 2], H.back(), points[i]) == 0 &&
                    H[H.size() - 2].dist(H.back()) < H[H.size() - 2].dist(points[i])))){
                        H.pop_back();
                   }
            H.push_back(points[i]);
        }
        return H;
    }
};
Point ConvexHull::bst;

class Line{
public:
    long double m, b;

    Line() : m(0), b(0){}
    // line AB
    Line(Point &A, Point &B){
        m = (A.y - B.y) / (A.x - B.x);
        b = A.y - m * A.x;
    }

    // line with angle alfa with point A
    Line(Point &A, long double m){
        this->m = m;
        b = A.y - m * A.x;
    }

    // ax+by+c
    Line(long double a, long double b, long double c){
        m = -a / b;
        this->b = -c / b;
    }

    Line(long double m, long double b){
        this->m = m;
        this->b = b;
    }

    long double getX(long double y) const{
        return (y - b) / m;
    }

    long double getY(long double x) const{
        return m * x + b;
    }

    long double perpendicularAngle(){
        return -1 / m;
    }

    Point intersect(Line &oth) const{
        if (abs(m-oth.m) < eps) return {INF,INF};
        long double x = (oth.b - b) / (m - oth.m);
        long double y = getY(x);
        return {x,y};
    }

    long double dist(Line &oth) const{
        if (abs(m-oth.m) >= eps) return 0;
        return abs(oth.b-b) / sqrt(m*m+1);
    }

    bool isParalel(Line &oth){
        return abs(m - oth.m) < eps;
    }
};

class Rectangle{
private:
    void sortTrigonom(Point &A, Point &B, Point &C, Point &D){
        ConvexHull c = ConvexHull();
        vector<Point> ans = c.getConvexHull({A,B,C,D});
        A = ans[0]; B = ans[1]; C = ans[2]; D = ans[3];
    }


public:
    Point A,B,C,D;

    Rectangle(Point &A, Point &B, Point &C, Point &D){
        this->A = A; this->B = B; this->C = C; this->D = D;
        sortTrigonom(this->A,this->B,this->C,this->D);
    }

    Rectangle(Line &L1, Line &L2, Line &L3, Line &L4){
        if (L1.isParalel(L2)) swap(L2, L3);
        if (L1.isParalel(L4)) swap(L3, L4);
        A = L1.intersect(L2);
        B = L2.intersect(L3);
        C = L3.intersect(L4);
        D = L4.intersect(L1);
        sortTrigonom(A,B,C,D);
    }

    long double area(){
        return A.dist(B) * B.dist(C);
    }

    long double perimeter(){
        // to do
    }
};


int main()
{

    return 0;
}
