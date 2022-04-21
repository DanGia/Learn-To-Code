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
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    string toString() const
    {
        return "<Point[" + to_string(x) + "," + to_string(y) + "]>";
    }

    int distanceTo(const Point &otherPoint) const
    {
        return ceil(sqrt(pow(otherPoint.x - x, 2) + pow(otherPoint.y - y, 2)));
    }
};

class Node
{
private:
    Point point;
    Node *next;

    friend class Path;

public:
    Node(const Point &point = Point(), Node *next = NULL)
    {
        this->point = point;
        this->next = next;
    }
    string toString() const
    {
        return "<Node[" + point.toString() + "]>";
    }
};
class Path
{
private:
    Node *head;
    Node *tail;
    int count;
    int length;

public:
    Path()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
        this->length = -1;
    }
    ~Path()
    {
        for (int i = 0; i < this->count; i++)
        {
            Node *p = this->head;
            this->head = p->next;
            delete p;
        }
        this->tail = NULL;
        this->head = NULL;
    }
    void setLength()
    {
        this->length = length;
    }
    int getLength()
    {
        return length;
    }
    void addPoint(int x, int y)
    {
        Node *r = new Node(Point(x, y));
        if (this->head == NULL)
        {
            this->head = r;
            this->tail = r;
            this->length = 0;
        }
        else
        {
            this->length += this->tail->point.distanceTo(r->point);
            this->tail->next = r;
            this->tail = r;
        }
        count++;
    }
    string toString() const
    {
        string res = "<Path[count:" + to_string(count) + ",length:" + to_string(length) + ",[";
        Node *w = head;
        for (int i = 0; i < count; i++)
        {
            res += w->toString() + ",";
            w = w->next;
        }
        if (res.back() == ',')
            res.pop_back();
        res += "]]>";
        return res;
    }
    Point getLastPoint() const
    {
        Point res = tail->point;
        return res;
    }
};

class Character
{
private:
    string name;
    Path *path;

public:
    Character(const string &name = "")
    {
        this->name = name;
        this->path = new Path;
    }
    ~Character()
    {
        delete path;
    }

    string getName() const
    {
        return name;
    }
    void setName(const string &name)
    {
        this->name = name;
    }
    Path *getPath() const
    {
        return path;
    }
    void setPath()
    {
        this->path = path;
    }
    void moveToPoint(int x, int y)
    {
        path->addPoint(x, y);
    }
    string toString() const
    {
        string res = "<Character[name:" + name + ",path:" + path->toString() + "]>";
        return res;
    }
};

bool rescueSherlock(
    const Character &chMurderer,
    const Character &chWatson,
    int maxLength,
    int maxDistance,
    int &outDistance)
{
    int l1 = chWatson.getPath()->getLength();
    int l2 = chMurderer.getPath()->getLength();
    if (l1 - l2 <= maxLength)
    {
        outDistance = chWatson.getPath()->getLastPoint().distanceTo(chMurderer.getPath()->getLastPoint());
        if (outDistance <= maxDistance)
            return true;
        return false;
    }
    outDistance = -1;
    return false;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */