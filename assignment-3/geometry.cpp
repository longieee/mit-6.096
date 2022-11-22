#include <stdlib.h>
#include "geometry.h"
#include <cmath>

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(const int new_x)
{
    x = new_x;
}

void Point::setY(const int new_y)
{
    y = new_y;
}

PointArray::PointArray()
{
    size = 0;
    points = new Point[0];
}

PointArray::PointArray(const Point pointsToCopy[], const int sizeToCopy)
{
    size = sizeToCopy;
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = pointsToCopy[i];
    }
}

PointArray::PointArray(const PointArray &pv)
{
    size = pv.size;
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = pv.points[i];
    }
}

PointArray::~PointArray()
{
    delete[] points;
}

void PointArray::resize(int newSize)
{
    Point *newPoints = new Point[newSize];
    int minSize = newSize < size ? newSize : size;
    for (int i = 0; i < minSize; i++)
    {
        newPoints[i] = points[i];
    }
    delete[] points;
    points = newPoints;
    size = newSize;
}

void PointArray::push_back(const Point &p)
{
    resize(size + 1);
    points[size - 1] = p;
}

void PointArray::insert(const int pos, const Point &p)
{
    if (pos >= 0 && pos <= size)
    {
        resize(size + 1);
        for (int i = size - 1; i > pos; i--)
        {
            points[i] = points[i - 1];
        }
        points[pos] = p;
    }
}

void PointArray::remove(const int pos)
{
    if (pos >= 0 && pos < size)
    {
        for (int i = pos; i < size - 1; i++)
        {
            points[i] = points[i + 1];
        }
        resize(size - 1);
    }
}

const int PointArray::getSize() const
{
    return size;
}

void PointArray::clear()
{
    resize(0);
}

Point *PointArray::get(const int pos)
{
    return pos >= 0 && pos < size ? points + pos : NULL;
}

const Point *PointArray::get(const int pos) const
{
    return pos >= 0 && pos < size ? points + pos : NULL;
}

int Polygon::numPolygons = 0;

Polygon::Polygon(const Point pointArr[], const int length) : points(pointArr, length)
{
    numPolygons++;
}

Polygon::Polygon(const PointArray &pointArr) : points(pointArr)
{
    numPolygons++;
}

Polygon::~Polygon()
{
    --numPolygons;
}

int Polygon::getNumPolygons()
{
    return numPolygons;
}

int Polygon::getNumSides()
{
    return points.getSize();
}

const PointArray *Polygon::getPoints()
{
    return &points;
}

Point constructorPoints[4];

Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0, 0))
{
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

Rectangle::Rectangle(const Point &lowerLeft, const Point &upperRight)
    : Polygon(updateConstructorPoints(lowerLeft,
                                      Point(lowerLeft.getX(), upperRight.getY()), // upper left
                                      upperRight,
                                      Point(upperRight.getX(), lowerLeft.getY())), // lower right
              4)
{
}

Rectangle::Rectangle(const int llx, const int lly, const int urx, const int ury)
    : Polygon(
          updateConstructorPoints(
              Point(llx, lly),
              Point(llx, ury),
              Point(urx, ury),
              Point(urx, lly)),
          4) {}

double Rectangle::area() const
{
    int length = points.get(1)->getY() - points.get(0)->getY();
    int width = points.get(2)->getX() - points.get(1)->getX();
    return std::abs((double)length * (double)width);
}

Triangle::Triangle(const Point &a, const Point &b, const Point &c)
    : Polygon(updateConstructorPoints(a, b, c),
              3) {}

double Triangle::area() const
{
    int dx_01 = points.get(0)->getX() - points.get(1)->getX(),
        dx_12 = points.get(1)->getX() - points.get(2)->getX(),
        dx_20 = points.get(2)->getX() - points.get(0)->getX();
    int dy_01 = points.get(0)->getY() - points.get(1)->getY(),
        dy_12 = points.get(1)->getY() - points.get(2)->getY(),
        dy_20 = points.get(2)->getY() - points.get(0)->getY();

    double a = std::sqrt(dx_01 * dx_01 + dy_01 * dy_01),
           b = std::sqrt(dx_12 * dx_12 + dy_12 * dy_12),
           c = std::sqrt(dx_20 * dx_20 + dy_20 * dy_20),
           s = (a + b + c) / 2;

    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}