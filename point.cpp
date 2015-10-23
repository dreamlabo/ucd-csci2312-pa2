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
    Point::Point(int dimensions)
    {
        m_Dim = dimensions;
        m_Values = new double[m_Dim];

        //Initialize m_Value array to 0.0
        for (int index = 0; index < m_Dim; index++)
        {
            m_Values[index] = 0.0;
        }

    }

//Constructor #2
//Precondition: User has entered amount of dimensions for their points and actual point values
//PostCondition: points are entered into the class
    Point::Point(int dimensions, double *arrayOfPoints)
    {
        m_Dim = dimensions;
        m_Values = new double[m_Dim];

        for (int index = 0; index < dimensions; index++)
        {
            m_Values[index] = arrayOfPoints[index];
        }
    }

//Copy constructor  //Seems to be working
    Point::Point(const Point &rightSide)
    {
        m_Dim = rightSide.m_Dim;
        m_Values = new double[m_Dim];
        for ( int index = 0; index < m_Dim; index++)
        {
            m_Values[index] = rightSide.m_Values[index];
        }
    }

//Overloaded = operator  //Seems to be working
    Point &Point::operator=(const Point &rightSide)
    {
        if (*this == rightSide)
        { return *this; }
        else
        {
            delete[] m_Values;
            m_Dim = rightSide.m_Dim;
            m_Values = new double[m_Dim];
            for (int index = 0; index < m_Dim; index++)
            {
                m_Values[index] = rightSide.m_Values[index];
            }
            return *this;
        }
    }


//Destructor // Seems to be working
//PreCondition: Array needs to be destroyed.
//PostCondition: Array is deleted from the heap.
    Point::~Point() {
        //std::cout << "Hello from the destructor.\n";
        delete[] m_Values;
    }


//Mutators
    void Point::setValue(int index, double axisPoint) {
        m_Values[index] = axisPoint;
    }

//Accessors
    double Point::getValue(int numDimensions) const {
        for (int index = 0; index< numDimensions; index++)
            return m_Values[index];
    }

// Calculate the distance from one point to another point.
    double Point::distanceTo(const Point &array) const {
        if (m_Dim == array.m_Dim) {
            double sum;
            double distance;

            for (int index = 0; index < m_Dim; index++) {
                sum += pow((m_Values[index] - array.m_Values[index]), 2);
            }
            return sqrt(sum);
        }
        else
            std::cout << "Distance of different dimension points can't be measured.\n";



    }

//Overloaded Operators
//Members
    Point &Point::operator*=(double d) {
        for (int index = 0; index < m_Dim; index++) {
            m_Values[index] *= d;
        }
        return *this;
    }

    Point &Point::operator/=(double d) {
        for (int index = 0; index < m_Dim; index++){
            m_Values[index] /= d;
        }
        return *this;

    }

    const Point Point::operator*(double d) const {
        if( d == 0) {
            std::cout << "Sorry, division by 0 is not allowed\n";
            return *this;
        }
        Point temp(this->m_Dim);
        int dim = this->m_Dim;
        for (int index = 0; index < dim; index++){
            temp.m_Values[index] = this->m_Values[index] * d;
        }
        return temp;
    }

    const Point Point::operator/(double d) const {
        if( d == 0) {
            std::cout << "Sorry, division by 0 is not allowed\n";
            return *this;
        }
        Point temp(this->m_Dim);
        int dim = this->m_Dim;
        for (int index = 0; index < dim; index++){
            temp.m_Values[index] = this->m_Values[index] / d;
        }
        return temp;
    }

    //FRIENDS
    //Overloaded +=
    //Seems to be working
    Point &operator+=(Point &leftSide, const Point &rightSide)
    {
        if(leftSide.m_Dim != rightSide.m_Dim)
        { std::cout << "Sorry, cant add points of different dimension\n";}

        for (int index = 0; index < leftSide.m_Dim; index++){
            leftSide.m_Values[index] += rightSide.m_Values[index];
        }
        return leftSide;
    }

    //Overloaded +-
    Point &operator-=(Point &leftSide, const Point &rightSide)
    {
        if(leftSide.m_Dim != rightSide.m_Dim)
        { std::cout << "Sorry, cant add points of different dimension\n";}

        for (int index = 0; index < leftSide.m_Dim; index++){
            leftSide.m_Values[index] -= rightSide.m_Values[index];
        }
        return leftSide;
    }

    //Overloaded +
    //Seems to be working
    const Point operator+(const Point &leftSide, const Point &rightSide)
    { if (leftSide.m_Dim != rightSide.m_Dim)
        { std::cout << "Can't add points of different dimensions\n";
            return leftSide;
        }

        Point temp(leftSide.m_Dim);
        int dim = leftSide.m_Dim;

        for (int index = 0; index < dim; index++) {
            temp.m_Values[index] = leftSide.m_Values[index] + rightSide.m_Values[index];
        }
        return temp;
    }


    //Overloaded  -
    const Point operator-(const Point &leftSide, const Point &rightSide)
    { if (leftSide.m_Dim != rightSide.m_Dim)
        { std::cout << "Can't add points of different dimensions\n";
            return leftSide;
        }

        Point temp(leftSide.m_Dim);
        int dim = leftSide.m_Dim;

        for (int index = 0; index < dim; index++) {
            temp.m_Values[index] = leftSide.m_Values[index] - rightSide.m_Values[index];
        }
        return temp;
    }


    //Overloaded ==
    //Seems to be working, need to test
    bool operator==(const Point &leftSide, const Point &rightSide)
    {
        int dim = rightSide.m_Dim;
        for (int index = 0; index < dim; index++) {
            if (leftSide.m_Values[index] == rightSide.m_Values[index])
                return true;
        }
        return false;
    }

    //Overloaded !=
    //Seems to be working
    bool operator!=(const Point &leftSide, const Point &rightSide)
    {
        if ( leftSide.m_Dim != rightSide.m_Dim)
        { std::cout << "Can't compare points of different dimensions\n";}
        else
        {
            int dim = leftSide.m_Dim;
            for (int index = 0; index < dim; index++)
                if (leftSide.m_Values[index] != rightSide.m_Values[index])
                    return true;
        }
        return false;
    }

    //Overloaded <
    //Seems to be working
    bool operator<(const Point &leftSide, const Point &rightSide)
    {
        int dim = leftSide.m_Dim;
        for (int index = 0; index < dim; index++) {
            if (leftSide.m_Values[index] < rightSide.m_Values[index])
                return true;
        }
        return false;
    }
    //Overloaded >
    //Seems to be working
    bool operator>(const Point &leftSide, const Point &rightSide)
    {
        int dim = leftSide.m_Dim;
        for (int index = 0; index < dim; index++) {
            if (leftSide.m_Values[index] > rightSide.m_Values[index])
                return true;
        }
        return false;
    }

    //Overloaded <=
    //Seems to be working
    bool operator<=(const Point &leftSide, const Point &rightSide)
    {
        int dim = leftSide.m_Dim;
        for (int index = 0; index < dim; index++) {
            if (leftSide.m_Values[index] <= rightSide.m_Values[index])
                return true;
        }
        return false;
    }

    //Overloaded >=
    //Seems to be working
    bool operator>=(const Point &leftSide, const Point &rightSide) {
        int dim = leftSide.m_Dim;
        for (int index = 0; index < dim; index++) {
            if (leftSide.m_Values[index] >= rightSide.m_Values[index])
                return true;
        }
        return false;
    }


    //Overloaded <<
    //Seems to be working
    std::ostream &operator<<(std::ostream &os, const Clustering::Point &point)
    {
        os << "(" << point.m_Values[0];
        for (int  index = 1; index < point.m_Dim; index++) {
            os << "," << point.m_Values[index];
        }
        os << ")";
        return os;
    }

    //Overloaded >>
    std::istream &operator>>(std::istream &is, Clustering::Point &point) {
        int numberOfDimensions;
        double arrayOfPoints;
        std::cout << "How many dimensions are in your point? ";
        is >> numberOfDimensions;
        for (int index = 0; index < numberOfDimensions; index++) {
            is >> point.m_Values[index];
        }
        return is;
    }



}
