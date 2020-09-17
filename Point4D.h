#ifndef Point4D_h
#define Point4D_h

#include<iostream>
#include<iomanip>
#include<array>

using std::ostream;
using std::istream;

class Point4D
{
public:

    //default constructor:
    explicit Point4D(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

    //defaulted copy constructor:
    Point4D(const Point4D&) = default;

    //defaulted destructor:
    virtual ~Point4D() = default;

    //members to represent a classwide tolerance:
    static void setTolerance(double tol);
    static double getTolerance();

    //defaulted assignment operator:
    Point4D& operator= (const Point4D&) = default;
    
    //inverse() function:
    Point4D inverse() const;

    //write() function to use the non-member<< operator function:
    void write(ostream& output) const;

    //operators overloaded as member functions:

    //overloaded subscript operators (both const and non-const):
    double& operator[] (int);
    const double operator[] (int) const;

    //overloaded compound assignment operators:
    Point4D& operator+= (const Point4D&);
    Point4D& operator-= (const Point4D&);
    Point4D& operator*= (const Point4D&);
    Point4D& operator/= (const Point4D&);

    Point4D& operator+= (const double);
    Point4D& operator-= (const double);
    Point4D& operator*= (const double);
    Point4D& operator/= (const double);

    //unary operators:
    Point4D operator+ ();
    Point4D operator- ();

    Point4D& operator++ ();
    Point4D& operator-- ();
    Point4D operator++ (int);
    Point4D operator-- (int);

    //absoluteValue() function
    double absoluteValue() const;

    //function call operator overload:
    double operator() ();

//private data members:

// a private data member to represent the classwide tolerance:
private:
    static double tolerance;

//the data member storing 4 elements (represented by the standard array class)
private:
    std::array<double, 4> point;
};

//operators overloaded as non-member functions:

//insertion and extraction operators
ostream& operator<< (ostream&, const Point4D&);
istream& operator>> (istream&, Point4D&);

//basic arithmetic operators:
Point4D operator+ (const Point4D&, const Point4D&);
Point4D operator- (const Point4D&, const Point4D&);
Point4D operator* (const Point4D&, const Point4D&);
Point4D operator/ (const Point4D&, const Point4D&);

Point4D operator+ (const double, const Point4D&);
Point4D operator- (const double, const Point4D&);
Point4D operator* (const double, const Point4D&);
Point4D operator/ (const double, const Point4D&);

Point4D operator+ (const Point4D&, const double);
Point4D operator- (const Point4D&, const double);
Point4D operator* (const Point4D&, const double);
Point4D operator/ (const Point4D&, const double);

//relational operators:
bool operator== (const Point4D&, const Point4D&);
bool operator!= (const Point4D&, const Point4D&);
bool operator< (const Point4D&, const Point4D&);
bool operator<= (const Point4D&, const Point4D&);
bool operator> (const Point4D&, const Point4D&);
bool operator>= (const Point4D&, const Point4D&);

#endif /* Point4D_h */
