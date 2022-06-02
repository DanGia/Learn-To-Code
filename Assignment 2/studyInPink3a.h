/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
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
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
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
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
string Point::toString() const
{
    string str;

    str = "<Point[" + to_string(this->x) + "," + to_string(this->y) + "]>";
    return str;
}
int Point::distanceTo(const Point &otherPoint) const
{
    int a = otherPoint.x;
    int b = otherPoint.y;
    int d = (int)ceil(sqrt((this->x - a) * (this->x - a) + (this->y - b) * (this->y - b)));
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
Node::Node(const Point &point, Node *next)
{
    this->point = point;
    this->next = next;
}
string Node::toString() const
{
    return "<Node[" + point.toString() + "]>";
}

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
        this->head = NULL;
        this->tail = NULL;
        this->count = 0;
        this->length = -1;  
    }
    ~Path()
    {
        for (int i = 0; i < this->count; i++)
        {
            Node *p = this->head;
            if (p != nullptr)
            {
                this->head = p->next;
                delete p;
            }
        }

        // this->head = NULL;
        this->tail = NULL;
    }
    void setLength()
    {
        this->length = length;
    }
    int getLength()
    {
        return length;
    }
    void addPoint(int x, int y);
    string toString() const;
    Point getLastPoint() const;
};

void Path::addPoint(int x, int y)
{
    Node *pt = new Node(Point(x, y));
    if (this->head == NULL)
    {
        this->head = pt;
        this->tail = pt;
        this->length = 0;
    }
    else
    {
        this->length = this->length + this->tail->point.distanceTo(pt->point);
        this->tail->next = pt;
        this->tail = pt;
    }
    this->count += 1;
}

string Path::toString() const
{
    string ans = "<Path[count:" + to_string(this->count) + ",length:" + to_string(this->length) + ",[";

    Node *node = head;
    for (int i = 0; i < count; i++)
    {
        ans += node->toString() + ",";
        node = node->next;
    }
    if (ans.back() == ',')
        ans.pop_back();
    ans = ans + "]]>";

    return ans; // done test
}

Point Path::getLastPoint() const
{
    Point p = tail->point;
    return p; // take the last point in the linked list
}

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
        //(*path).~Path();
        delete path; // xoa node path
    }
    void setPath()
    {
        this->path = path;
        return;
    }
    Path *getPath() const
    {
        return path;
    }

    string getName() const;
    void setName(const string &name);

    void moveToPoint(int x, int y);
    string toString() const;
};

string Character::getName() const
{
    return this->name;
}

void Character::setName(const string &name)
{
    this->name = name;
}

void Character::moveToPoint(int x, int y)
{
    path->addPoint(x, y);
}

string Character::toString() const
{
    string str_path = path->toString();
    string ans = "<Character[name:" + this->name + ",path:" + str_path + "]>";
    return ans;
}
bool rescueSherlock(
    const Character &chMurderer,
    const Character &chWatson,
    int maxLength,
    int maxDistance,
    int &outDistance)
{
    Path *pathWatson = chWatson.getPath();
    Path *pathMurder = chMurderer.getPath();
    int l1 = pathWatson->getLength();
    int l2 = pathMurder->getLength();

    if ((l1 - l2) <= maxLength)
    {
        outDistance = pathWatson->getLastPoint().distanceTo(pathMurder->getLastPoint());
        if (outDistance > maxDistance)
            return false;
    }
    else
        return false;
    return true;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */