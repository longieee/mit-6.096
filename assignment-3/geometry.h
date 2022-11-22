#ifndef GEOMETRY_H
#define GEOMETRY_H

class Point
{
private:
    int x, y;

public:
    Point(int u = 0, int v = 0) : x(u), y(v) {}
    int getX() const;
    int getY() const;
    void setX(const int new_x);
    void setY(const int new_y);
};

class PointArray
{
private:
    Point *points;
    int size;
    void resize(int n);

public:
    PointArray();
    PointArray(const Point points[], const int size);
    PointArray(const PointArray &pv);
    ~PointArray();

    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    const int getSize() const;
    void clear();
    Point *get(const int position);
    const Point *get(const int position) const;
    // We need the const versions so that we can return read-only pointers for const PointArray objects.
    // (If the PointArray object is read-only,
    // we don’t want to allow someone to modify a Point it contains just by using these functions.)
    // However, many times we will have a non-const PointArray object, for which we may want to allow modifying
    // the contained Point objects. If we had only const accessor functions, then even in such a case we would be
    // returning a const pointer. To allow returning a non-const pointer in situations where we might want one,
    // we need non-const versions of these
};

class Polygon
{
protected:
    PointArray points;
    static int numPolygons;

public:
    Polygon(const Point points[], const int length);
    Polygon(const PointArray &points);
    ~Polygon();

    virtual double area() const = 0;
    static int getNumPolygons();
    int getNumSides();
    const PointArray *getPoints();
};

class Rectangle : public Polygon
{
public:
    Rectangle(const Point &lowerLeft, const Point &upperRight);
    Rectangle(const int a, const int b, const int c, const int d);
    virtual double area() const;
};

class Triangle : public Polygon
{
public:
    Triangle(const Point &a, const Point &b, const Point &c);
    virtual double area() const;
};

#endif