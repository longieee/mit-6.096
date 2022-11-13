#include <stdlib.h>
#include "geometry.h"

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

Polygon::Polygon(const Point pointArr[], const int length) : points(pointArr, length)
{
    numPolygons++;
}

Polygon::Polygon(const PointArray &pointArr) : points(pointArr)
{
    numPolygons++;
}