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

        // Big three: copy constuctor, overloaded operator=, destructor
        //Copy Constructor
        Point(const Point &); //DONE?  self Assignment using assert?

        Point &operator=(const Point &); //DONE


        // Destructor
        ~Point();//DONE

        // Accessors & mutators
        int getDims() const { return m_Dim; } //Declared inline. DONE

        void setValue(int, double); //DONE

        double getValue(int) const; //DONE

        // Functions
        double distanceTo(const Point &) const; //DONE



        // Overloaded operators
        // Members
        Point &operator*=(double); //DONE
        Point &operator/=(double); //DONE
        const Point operator*(double) const; // DONE prevent (p1*2) = p2;
        const Point operator/(double) const; //DONE

        double &operator[](int index) { return m_Values[index - 1]; } // TODO out-of-bds?

        // Friends
        friend Point &operator+=(Point &, const Point &); //Done
        friend Point &operator-=(Point &, const Point &); //DONE
        friend const Point operator+(const Point &, const Point &); //DONE
        friend const Point operator-(const Point &, const Point &);//DONE
        friend bool operator==(const Point &, const Point &); //DONE
        friend bool operator!=(const Point &, const Point &); //DONE
        friend bool operator<(const Point &, const Point &); //DONE
        friend bool operator>(const Point &, const Point &); //Done
        friend bool operator<=(const Point &, const Point &); //DONE
        friend bool operator>=(const Point &, const Point &); //Done
        friend std::ostream &operator<<(std::ostream &, const Point &); //Done
        friend std::istream &operator>>(std::istream &, Point &); //NOT DONE
    };

}
#endif //PA2_POINT_H