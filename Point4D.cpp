#include<iostream>
#include<iomanip>
#include<array>
#include<stdexcept>
#include<cstdlib>
#include<cmath>
#include "Point4D.h"

using std::cout;
using std::endl;

//default constructor:
Point4D::Point4D(double x1, double x2, double x3, double x4) {
	point[0] = x1;
	point[1] = x2;
	point[2] = x3;
	point[3] = x4;

}

//defining the static methods:
double Point4D::tolerance = 1.0E-6;
void Point4D::setTolerance(double tol)
{
	tolerance = std::abs(tol);
}
double Point4D::getTolerance()
{
	return tolerance;
}

//defining the inverse() function:
Point4D Point4D::inverse() const
{
	double beta = this->point[0] * this->point[2] - this->point[1] * this->point[3];

	if (abs(beta) < tolerance)
	{
		throw std::overflow_error("Encountered division by zero while inverting Point4D");
	}

	double invertedBeta = 1 / beta;

	Point4D temp = *this;
	temp.point[0] = invertedBeta * point[2];
	temp.point[1] = invertedBeta * (point[1] * (-1));
	temp.point[2] = invertedBeta * point[0];
	temp.point[3] = invertedBeta * (point[3] * (-1));

	return temp;
}

//operators overloaded as member functions:

//overloading compound assignment operators:
Point4D& Point4D:: operator+= (const Point4D& newPoint)
{
	this->point[0] += newPoint.point[0];
	this->point[1] += newPoint.point[1];
	this->point[2] += newPoint.point[2];
	this->point[3] += newPoint.point[3];

	return *this;
}

Point4D& Point4D:: operator-= (const Point4D& newPoint)
{
	this->point[0] -= newPoint.point[0];
	this->point[1] -= newPoint.point[1];
	this->point[2] -= newPoint.point[2];
	this->point[3] -= newPoint.point[3];

	return *this;
}
Point4D& Point4D:: operator*= (const Point4D& newPoint)
{
	this->point[0] *= newPoint.point[0];
	this->point[1] *= newPoint.point[1];
	this->point[2] *= newPoint.point[2];
	this->point[3] *= newPoint.point[3];

	return *this;
}
Point4D& Point4D:: operator/= (const Point4D& newPoint)
{
	this->point[0] /= newPoint.point[0];
	this->point[1] /= newPoint.point[1];
	this->point[2] /= newPoint.point[2];
	this->point[3] /= newPoint.point[3];

	return *this;
}

Point4D& Point4D:: operator+= (const double number)
{
	this->point[0] += number;
	this->point[1] += number;
	this->point[2] += number;
	this->point[3] += number;

	return *this;
}

Point4D& Point4D:: operator-= (const double number)
{
	this->point[0] -= number;
	this->point[1] -= number;
	this->point[2] -= number;
	this->point[3] -= number;

	return *this;
}

Point4D& Point4D:: operator*= (const double number)
{

	this->point[0] *= number;
	this->point[1] *= number;
	this->point[2] *= number;
	this->point[3] *= number;

	return *this;
}

Point4D& Point4D:: operator/= (const double number)
{

	this->point[0] /= number;
	this->point[1] /= number;
	this->point[2] /= number;
	this->point[3] /= number;

	return *this;
}

//unary operators:

Point4D Point4D:: operator+ ()
{
	Point4D temp{ *this };
	return temp;
}
Point4D Point4D:: operator- ()
{
	Point4D temp{ *this };
	temp = temp * (-1);
	return temp;
}

Point4D& Point4D:: operator++ ()
{
	++this->point[0];
	++this->point[1];
	++this->point[2];
	++this->point[3];

	return *this;
}
Point4D& Point4D:: operator-- ()
{
	--this->point[0];
	--this->point[1];
	--this->point[2];
	--this->point[3];

	return *this;
}

Point4D Point4D:: operator++ (int dummy)
{
	Point4D temp{ *this };
	++(*this);
	return temp;

}
Point4D Point4D:: operator-- (int dummy)
{
	Point4D temp{ *this };
	--(*this);
	return temp;

}

//overloaded subscript operators (both const and non-const):
double& Point4D:: operator[] (int subscript)
{
	if ((subscript > 4) || (subscript < 1)) {
		try {
			point.at(subscript);

		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Index out of bounds. \n" << oor.what() << endl;
			exit(EXIT_FAILURE);
		}
	}

	return point[subscript - 1];
}

const double Point4D:: operator[] (int subscript) const
{
	if ((subscript > 4) || (subscript < 1)) {
		try {
			point.at(subscript);

		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Index out of bounds. \n" << oor.what() << endl;
			exit(EXIT_FAILURE);
		}
	}

	return point[subscript - 1];
}

//write() function to use the non-member<< operator function:
void Point4D::write(ostream& output) const
{
	output << this->point[0] << ", "
		<< this->point[1] << ", "
		<< this->point[2] << ", "
		<< this->point[3] << endl;
}

//absoluteValue() function
double Point4D::absoluteValue() const
{
	double firstElement{ static_cast<double> (abs(point[0])) };
	double secondElement{ static_cast<double> (abs(point[1])) };
	double thirdElement{ static_cast<double> (abs(point[2])) };
	double fourthElement{ static_cast<double> (abs(point[3])) };

	return (firstElement + secondElement + thirdElement + fourthElement);
}

//function call operator overload:
double Point4D:: operator() ()
{
	return (this->absoluteValue());
}

//operators overloaded as non-member functions:

//insertion operator
ostream& operator<< (ostream& output, const Point4D& newPoint)
{
	newPoint.write(output);
	return output;
}

//extraction operator
istream& operator>> (istream& input, Point4D& newPoint)
{
	input >> newPoint[1];
	input.ignore(2);
	input >> newPoint[2];
	input.ignore(2);
	input >> newPoint[3];
	input.ignore(2);
	input >> newPoint[4];
	return input;
}

//basic arithmetic operators:
Point4D operator+ (const Point4D& point1, const Point4D& point2)
{
	Point4D temp{ point1 };
	temp += point2;
	return temp;
}

Point4D operator- (const Point4D& point1, const Point4D& point2)
{
	Point4D temp{ point1 };
	temp -= point2;
	return temp;
}

Point4D operator* (const Point4D& point1, const Point4D& point2)
{
	Point4D temp;
	temp[1] = point1[1] * point2[1] + point1[2] * point2[4];
	temp[2] = point1[1] * point2[2] + point1[2] * point2[3];
	temp[3] = point1[4] * point2[2] + point1[3] * point2[3];
	temp[4] = point1[4] * point2[1] + point1[3] * point2[4];
	return temp;
}

Point4D operator/ (const Point4D& point1, const Point4D& point2)
{
	Point4D temp;
	temp = point1 * point2.inverse();
	return temp;
}

Point4D operator+ (const double number, const Point4D& point)
{
	Point4D temp{ point };
	temp += number;
	return temp;
}

Point4D operator- (const double number, const Point4D& point)
{
	Point4D temp{ point };
	temp[1] = number - temp[1];
	temp[2] = number - temp[2];
	temp[3] = number - temp[3];
	temp[4] = number - temp[4];
	return temp;
}

Point4D operator* (const double number, const Point4D& point)
{
	Point4D temp{ point };
	temp *= number;
	return temp;
}

Point4D operator/ (const double number, const Point4D& point)
{
	return (number * point.inverse());
}

Point4D operator+ (const Point4D& point, const double number)
{
	Point4D temp;
	temp = number + point;
	return temp;
}

Point4D operator- (const Point4D& point, const double number)
{
	Point4D temp{ point };
	temp -= number;
	return temp;
}

Point4D operator* (const Point4D& point, const double number)
{
	return number * point;
}

Point4D operator/ (const Point4D& point, const double number)
{
	if (number == 0)
	{
		throw std::overflow_error("Encountered division by zero while inverting Point4D");
	}
	else
	{
		return point * (1 / number);
	}
}

//relational operators:
bool operator== (const Point4D& point1, const Point4D& point2)
{
	if (
		// We do not need to test for the number of elements in point1 and point2
		//because any Point4D object has exactly 4 elements 
		//thanks to the default constructor: if we enter fewer elements, it initializes all the missing ones to 0; 
		//if we enter more, an exception is thrown
		(point1 - point2).absoluteValue() <= Point4D::getTolerance())
	{
		return true;
	}
	else {
		return false;
	}
}

bool operator!= (const Point4D& point1, const Point4D& point2)
{
	if (!(point1 == point2)) { return true; }
	else { return false; }
}
bool operator< (const Point4D& point1, const Point4D& point2)
{
	if ((point1 != point2) && (point1.absoluteValue() < point2.absoluteValue())) { return true; }
	else { return false; }
}
bool operator<= (const Point4D& point1, const Point4D& point2)
{
	if ((point1 == point2) || (point1.absoluteValue() < point2.absoluteValue())) { return true; }
	else { return false; }
}
bool operator> (const Point4D& point1, const Point4D& point2)
{
	if (point2.absoluteValue() < point1.absoluteValue()) { return true; }
	else { return false; }
}
bool operator>= (const Point4D& point1, const Point4D& point2)
{
	if (!(point1.absoluteValue() < point2.absoluteValue())) { return true; }
	else { return false; }
}
