include <iostream>
#include <vector>
#include <string>
#include <type_traits>

using namespace std;

class Point
{
public:
    int x, y;
};

class Figure
{
protected:
    std::vector<Point> points;

public:
    Figure(std::vector<Point> points) : points(points){};

    std::vector<Point> getPoints()
    {
        return points;
    }
};

class Circle
{
public:
    static Circle &getInstance()
    {
        static Circle instance; //// Guaranteed to be destroyed.

        return instance;
    };
    string template(Point point)
    {
        if (pow(point.x - circleOrigin.x, 2) + pow(point.y - circleOrigin.y, 2) == pow(rad, 2))
        {
            std::cout << "The figure is inside the circle.";
        }
        else
        {
            std::cout << "The figure is outside the circle.";
        }
    };

private:
    int rad;
    Point circleOrigin;
    Circle(){};
    Circle(Circle const &);
    void operator=(Circle const &);
};

class Square : public Figure
{
protected:
    std::vector<Point> points;

public:
    Square(std::vector<Point> points) : Figure(points){};
};

class Triangle : public Figure
{
protected:
    std::vector<Point> points;

public:
    Triangle(std::vector<Point> points) : Figure(points){};
};

class Rectangle : public Figure
{
protected:
    std::vector<Point> points;

public:
    Rectangle(std::vector<Point> points) : Figure(points){};
};

template <typename T>
float getSlope(T &figure)
{
    static_assert(std::is_base_of<Figure, T>::value, "Must be of type Figure");

    std::vector<Point> localPoints = figure->getPoints();

    if (localPoints.size() >= 2)
    {
        return (localPoints[1].y - localPoints[0].y) / (localPoints[1].x - localPoints[0].x);
    }

    else
    {
        cout << "Nu se poate frate, nu s destule puncte\n ";
        return 0;
    }
}

int main()
{

    int c;
    Square *s;
    Triangle *t;
    Rectangle *r;

    while (1)
    {
        cout << "Choose an option\n";
        cout << "1 -> Add square\n";
        cout << "2 -> Add triangle\n";
        cout << "3 -> Add rectangle\n";
        cout << "4 -> Add circle\n";
        cout << "5 -> Panta square\n";
        cout << "6 -> Panta triangle\n";
        cout << "7 -> Panta rectangle\n";
        cout << "5 -> Afiseaza panta dreptei\n";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            std::vector<Point> sPoints;
            for (int i = 0; i < 4; i++)
            {
                int x, y;
                cout << "x for point is: ?\n";
                cin >> x;
                cout << "y for point is: ?\n";
                cin >> y;
                Point p;
                p.x = x;
                p.y = y;
                sPoints.push_back(p);
            }
            s = new Square(sPoints);
        }

        break;
        case 2:
        {
            std::vector<Point> tPoints;
            for (int i = 0; i < 3; i++)
            {
                int x, y;
                cout << "x for point is: ?\n";
                cin >> x;
                cout << "y for point is: ?\n";
                cin >> y;
                Point p;
                p.x = x;
                p.y = y;
                tPoints.push_back(p);
            }
            t = new Triangle(tPoints);
            break;
        }

        case 3:
        {
            std::vector<Point> rPoints;
            for (int i = 0; i < 3; i++)
            {
                int x, y;
                cout << "x for point is: ?\n";
                cin >> x;
                cout << "y for point is: ?\n";
                cin >> y;
                Point p;
                p.x = x;
                p.y = y;
                rPoints.push_back(p);
            }
            r = new Rectangle(rPoints);
            break;
        }

        case 4:
            cout << "Not implemented";
            break;

        case 5:
        {
            cout << "Panta este: ";
            cout << getSlope(s) << "\n";
        }
        break;

        case 6:
        {
            cout << "Panta este: ";
            cout << getSlope(s) << "\n";
        }
        break;

        case 7:
        {
            cout << "Panta este: ";
            cout << getSlope(s) << "\n";
        }
        break;

        default:
            break;
        }
    }

    return 0;
}