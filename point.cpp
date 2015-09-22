//
// Created by Owner on 9/19/2015.
//
#include <iostream>
#include <cmath>
#include "point.h"
namespace Clustering {


//Constructor #1
//Precondition: User has entered amount of dimensions for their points
//PostCondition: *values is initialized to 0
    Point::Point(int dimensions) {
        int dim = getDims();
        m_Values = new double[dim];

        //Initialize m_Value array to 0.0
        for (int index = 0; index < dim; index++) {
            m_Values[index] = 0.0;
        }
    }

//Constructor #2
//Precondition: User has entered amount of dimensions for their points and actual point value
//PostCondition: points are entered into the class
    Point::Point(int dimensions, double *arrayOfPoints) {
        m_Dim = dimensions;
        m_Values = new double[m_Dim];

        for (int index = 0; index < dimensions; index++) {
            m_Values[index] = arrayOfPoints[index];
        }
    }
//Point::Point(const Point &array)
//{
//    double *a;
//    a = new double[m_Dim];
//    for (int index = 0; index < m_Dim; index++)
//        a[index] = array[index];
//}

//Destructor
//PreCondition: Array needs to be destroyed.
//PostCondition: Array is deleted from the heap.
    Point::~Point() {
        delete[] m_Values;
    }


//Mutators

    void Point::setValue(int index, double axisPoint) {
        m_Values[index] = axisPoint;
    }

//Accessors
    double Point::getValue(int index) const {
        return m_Values[index];
    }

// Calculate the distance from one point to another point.
    double Point::distanceTo(const Point &array) const {
        std::cout << "hello from distanceTo function\n";
        for (int index = 0; index < m_Dim; index++)
            std::cout << m_Values[index];
//    double xDistance = m_Values[index] - array[index];
//    //double yDistance = y - point.y;
//    //double zDistance = z - point1.z;
//    return xDistance;
        //return sqrt(xDistance * xDistance + yDistance * yDistance + zDistance * zDistance);
    }

//Overloaded Operators
//Members
    Point &Point::operator*=(double d) {
        for (int index = 0; index < m_Dim; index++) {
            m_Values[index] * d;
        }
        return *this;
    }


    Point &Point::operator/=(double d) {
        for (int index = 0; index < m_Dim; index++)
            m_Values[index] / d;
    }


    const Point Point::operator*(double d) const {
        return Point(m_Dim) * d;
    }

    const Point Point::operator/(double d) const {
        return Point(m_Dim) / d;
    }

    std::ostream &operator<<(std::ostream &os, const Point &array)
    {
        for (int index = 0; index < array.m_Dim; index++) {
            os << array.m_Values[index] << " ";
        }
        return os;
    }
}
