/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2022
 * Author: Vu Van Tien
 * Date: 15.02.2022
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point
{
private:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0);

    string toString() const;

    int distanceTo(const Point &otherPoint) const;
};
Point::Point(int X, int Y)
{
    x = X;
    y = Y;
}
string Point::toString() const
{
    string str;

    str = "<Point[" + to_string(x) + "," + to_string(y) + "]>";
    return str;
}
int Point::distanceTo(const Point &otherPoint) const
{
    int d;
    int a = otherPoint.x;
    int b = otherPoint.y;
    d = (int)ceil(sqrt((x - a) * (x - a) + (y - b) * (y - b)));
    return d;
}

class Node
{
private:
    Point point;
    Node *next;

    friend class Path;

public:
    Node(const Point &point = Point(), Node *next = NULL);
    string toString() const;
};

class Path
{
private:
    Node *head;
    Node *tail;
    int count;
    int length;

public:
    Path();
    ~Path();

    void addPoint(int x, int y);
    string toString() const;
    Point getLastPoint() const;
};

// class Character
// {
// private:
//     string name;
//     Path *path;

// public:
//     Character(const string &name = "");
//     ~Character();

//     string getName() const;
//     void setName(const string &name);

//     void moveToPoint(int x, int y);
//     string toString() const;
// };

// bool rescueSherlock(
//     const Character &chMurderer,
//     const Character &chWatson,
//     int maxLength,
//     int maxDistance,
//     int &outDistance)
// {

//     return true;
// }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */