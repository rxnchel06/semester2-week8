
#include <stdbool.h>
#include <math.h>
#include "shapes.h"

// create and return a Point structure
Point makePoint(float x, float y) {
    Point new;
    new.x = x;
    new.y = y;
    return new;
}

// create and return a Line structure
Line makeLine(Point p1, Point p2) {
    Line new;
    new.p[0] = p1;
    new.p[1] = p2;
    return new;
}

// create and return a Triangle structure
Triangle makeTriangle(Point p1, Point p2, Point p3) {
    Triangle new;
    new.p[0] = p1;
    new.p[1] = p2;
    new.p[2] = p3;
    return new;
}

// calculate the length of a Line using Pythagoras
float lineLength(Line l) {
    float dx = l.p[1].x - l.p[0].x;
    float dy = l.p[1].y - l.p[0].y;
    return sqrt(dx * dx + dy * dy);
}

// calculate the area of a Triangle using Heron's formula
float triangleArea(Triangle t) {
    Line ab = makeLine(t.p[0], t.p[1]);
    Line bc = makeLine(t.p[1], t.p[2]);
    Line ca = makeLine(t.p[2], t.p[0]);

    float a = lineLength(ab);
    float b = lineLength(bc);
    float c = lineLength(ca);

    float s = (a + b + c) / 2.0f;  // semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// return true if two points are at the same location
bool samePoint(Point p1, Point p2) {
    Line l = makeLine(p1, p2);
    return fabs(lineLength(l)) < 1.0e-6f;
}

// return true if point p is one of the endpoints of line l
bool pointInLine(Point p, Line l) {
    return samePoint(p, l.p[0]) || samePoint(p, l.p[1]);
}

// return true if point p is one of the vertices of triangle t
bool pointInTriangle(Point p, Triangle t) {
    return samePoint(p, t.p[0]) || samePoint(p, t.p[1]) || samePoint(p, t.p[2]);
}
