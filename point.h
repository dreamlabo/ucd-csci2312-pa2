//
// Created by Owner on 9/19/2015.
//

#ifndef PA2_POINT_H
#define PA2_POINT_H
#include <iostream>

namespace Clustering {

    class Point {
        int m_Dim;        // number of dimensions of the point
        double *m_Values; // values of the point's dimensions

    public:
        Point(int); //DONE // Create at least one constructor which takes an int for the dimension
        Point(int, double *); // second constructor which takes an int and an array of doubles.

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &);

        Point &operator=(const Point &);

        ~Point();

        // Accessors & mutators
        int getDims() const { return m_Dim; }

        void setValue(int, double);

        double getValue(int) const;

        // Functions
        double distanceTo(const Point &) const;

        // Overloaded operators

        // Members
        Point &operator*=(double);

        Point &operator/=(double);

        const Point operator*(double) const; // DONE prevent (p1*2) = p2;
        const Point operator/(double) const; //DONE

        double &operator[](int index) { return m_Values[index - 1]; } // TODO out-of-bds?

        // Friends
        friend Point &operator+=(Point &, const Point &);
        friend Point &operator-=(Point &, const Point &);
        friend const Point operator+(const Point &, const Point &);
        friend const Point operator-(const Point &, const Point &);
        friend bool operator==(const Point &, const Point &);
        friend bool operator!=(const Point &, const Point &);
        friend bool operator<(const Point &, const Point &);
        friend bool operator>(const Point &, const Point &);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);
        friend std::ostream &operator<<(std::ostream &, const Point &);
        friend std::istream &operator>>(std::istream &, Point &);
    };

}
#endif //PA2_POINT_H