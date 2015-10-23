//PA2
//Todd Labo
//
#include <iostream>
#include "point.h"
#include "cluster.h"
using namespace std;
using namespace Clustering;

//Function Prototypes (Point Class)
void test_CopyConstructor();
void test_Assignment_Operator();
void test_Overloaded_OS_operator();
void test_DistanceTo();
void test_Times_Equal();
void test_Division_Equal_Operator();
void test_Overloaded_Times_Operator();
void test_Overloaded_Division_Operator();
void test_Overloaded_Add_Equal_Operator();
void test_Overloaded_Minus_Equal_Operator();
void test_Overloaded_Addition_Operator();
void test_Overloaded_Subtraction_Operator();
void test_Overloaded_Equal_Operator();
void test_Overloaded_Not_Equal_Operator();
void test_Overloaded_Less_Than_Operator();
void test_Overloaded_Greater_Than_Operator();
void test_Overloaded_Less_Than_Equal_Operator();
void test_Overloaded_Greater_Than_Equal_Operator();

//Function Prototypes (Cluster Class)
void test_add();
void test_remove();
void test_Cluster_Assignment_Operator();
void test_Cluster_Copy_Constructor();

int main() {
    //Point Class Testing
    cout << "\nTesting Point class functions...\n\n";
    test_CopyConstructor();
    test_Assignment_Operator();
    test_Overloaded_OS_operator();
    test_DistanceTo();
    test_Times_Equal();
    test_Division_Equal_Operator();
    test_Overloaded_Times_Operator();
    test_Overloaded_Division_Operator();
    test_Overloaded_Add_Equal_Operator();
    test_Overloaded_Minus_Equal_Operator();
    test_Overloaded_Addition_Operator();
    test_Overloaded_Subtraction_Operator();
    test_Overloaded_Equal_Operator();
    test_Overloaded_Not_Equal_Operator();
    test_Overloaded_Less_Than_Operator();
    test_Overloaded_Greater_Than_Operator();
    test_Overloaded_Less_Than_Equal_Operator();
    test_Overloaded_Greater_Than_Equal_Operator();

//Cluster Class Testing
    cout << "\n\nNow testing Cluster Class function...\n\n";
    test_add();
    test_remove();
    test_Cluster_Assignment_Operator();
    test_Cluster_Copy_Constructor();

    return 0;

}


//Function Definitions

//Point Class
//testCopyConstructor
void test_CopyConstructor(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1,2,3};
    Point p2(NUM_DIMENSIONS, array_p2);

    cout << "\nTesting copy constructor...\n";
    cout << "Copying {p2]: {" << p2 << "} into new point [p4].\n";
    Point p4(p2);
    cout << "Point [p4] now contains the point: " << p4 << endl;
}
//Test Overloaded Operator=
void test_Assignment_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1,2,3};
    Point p2(NUM_DIMENSIONS, array_p2);

    cout << "\nTesting overloaded operator=...\n";
    cout << "Assigning [p2]: {" << p2 << "} into new point [p5].\n";
    Point p5 = p2;
    cout << "Point [p5] now contains the point: " << p5 << endl;

}//Test overloaded << operator
void test_Overloaded_OS_operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p5[] = {6,7,8};
    Point p5(NUM_DIMENSIONS, array_p5);

    cout << "\nTesting the overloaded << ...\n";
    cout << "Printing the point [p5]...\n";
    cout << "Point [p5] contains the point: " << p5 << endl;
}

//Test distanceTo function
void test_DistanceTo(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1,2,3};
    double array_p3[] = {3,4,5};

    Point p2(NUM_DIMENSIONS, array_p2); // Using Constructor #2
    Point p3(NUM_DIMENSIONS, array_p3); // Using Constructor #2
    cout << "\nTesting distanceTo function...\n";
    cout << "The distance between [p3] and [p2] is: " << p3.distanceTo(p2) << endl;
}

//Testing overloaded *=
void test_Times_Equal() {
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1,2,3};
    Point p2(NUM_DIMENSIONS, array_p2); // Using Constructor #2

    cout << "\nTesting overloaded *= ...\n";
    cout << "Point [p2]: " << p2 << " times 2 = ";
    p2 *= 2;
    cout <<  p2 << endl;
}

//Test overloaded /=
void test_Division_Equal_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p3[] = {3,4,5};
    Point p3(NUM_DIMENSIONS, array_p3);

    cout << "\nTesting overloaded /= ...\n";
    cout << "Point [p3]: " << p3 << " times 2 = ";
    p3 *= 2;
    cout <<  p3 << endl;
}

//Test Overloaded*
void test_Overloaded_Times_Operator() {
    const int NUM_DIMENSIONS = 3;
    double array_p3[] = {3,4,5};
    Point p3(NUM_DIMENSIONS, array_p3);

    cout << "\nTesting overloaded * ...\n";
    cout << "Point [p3]: " << p3 << " times 3 = ";
    p3 = p3 * 3;
    cout << p3 << endl;
}

//Test Overloaded /
void test_Overloaded_Division_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p3[] = {3,4,5};
    Point p3(NUM_DIMENSIONS, array_p3);

    cout << "\nTesting overloaded / ...\n";
    cout << "Point [p3]: " << p3 << " divided by 0 = ";
    p3 = p3 / 0;

    cout << "Point [p3]: " << p3 << " divided by 2 = ";
    p3 = p3 / 2;
    cout << p3 << endl;
}

//Test Overloaded +=
void test_Overloaded_Add_Equal_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1,2,3};
    double array_p3[] = {3,4,5};
    Point p2(NUM_DIMENSIONS, array_p2);
    Point p3(NUM_DIMENSIONS, array_p3);

    cout << "\nTesting overloaded += ...\n";
    cout << "When [p2]: " << p2 << " is subtracted from [p3]: " << p3 << endl;
    cout << "Point [p3] equals ";
    p3 += p2;
    cout <<  p3 << endl;
}

//Test Overloaded -=
void test_Overloaded_Minus_Equal_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1,2,3};
    double array_p3[] = {3,4,5};
    Point p2(NUM_DIMENSIONS, array_p2);
    Point p3(NUM_DIMENSIONS, array_p3);

    cout << "\nTesting overloaded -= ...\n";
    cout << "When [p2]: " << p2 << " is added to [p3]: " << p3 << endl;
    cout << "Point [p3] equals ";
    p3 -= p2;
    cout <<  p3 << endl;
}

//Test Overloaded +
void test_Overloaded_Addition_Operator(){
    const int NUM_DIMENSIONS = 3;
    Point p8(NUM_DIMENSIONS);
    double array_p2[] = {1,2,3};
    double array_p3[] = {3,4,5};
    Point p2(NUM_DIMENSIONS, array_p2);
    Point p3(NUM_DIMENSIONS, array_p3);

    cout << "\nTesting overloaded + ...\n";
    cout << "When [p2]: " << p2 << " is added to [p3]: " << p3 <<  " to form [p8]\n";
    p8 = p2 + p3;
    cout << "The result is [p8] =  " << p8 << endl;
}

//Test Overloaded -
void test_Overloaded_Subtraction_Operator(){
    const int NUM_DIMENSIONS = 3;
    Point p8(NUM_DIMENSIONS);
    double array_p2[] = {1,2,3};
    double array_p3[] = {3,4,5};
    Point p2(NUM_DIMENSIONS, array_p2);
    Point p3(NUM_DIMENSIONS, array_p3);

    cout << "\nTesting overloaded - ...\n";
    cout << "When [p3]: " << p3 << " is subtracted from [p2]: " << p2 <<  " to form [p8]\n";
    p8 = p2 - p3;
    cout << "The result is [p8] = " << p8 << endl;
}

//Test overloaded ==
void test_Overloaded_Equal_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1,2,3};
    double array_p3[] = {3,4,5};
    Point p2(NUM_DIMENSIONS, array_p2);
    Point p3(NUM_DIMENSIONS, array_p3);
    Point p4(NUM_DIMENSIONS, array_p2);
    cout << "\nTesting overloaded == ...\n";

    if (p2 == p3)
    {cout << "When points [p2]: " << p2 << " and [p3]: " << p3 << " are compared, they ARE equal.\n";}
    else
    {cout << "When points [p2]: " << p2 << " and [p3]:" << p3 << " are compared, they are NOT equal.\n";}

    if (p2 == p4)
    {cout << "When points [p2]: " << p2 << " and [p4]: " << p4 << " are compared, they ARE equal.\n";}
    else
    {cout << "When points [p2]: " << p2 << " and [p4]: " << p4 << " are compared, they are NOT equal.\n";}
}

//Test overloaded !=
void test_Overloaded_Not_Equal_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1,2,3};
    double array_p3[] = {3,4,5};
    Point p2(NUM_DIMENSIONS, array_p2);
    Point p3(NUM_DIMENSIONS, array_p3);
    Point p4(NUM_DIMENSIONS, array_p2);
    cout << "\nTesting overloaded != ...\n";

    if (p2 != p3)
    {cout << "When points [p2]: " << p2 << " and [p3]: " << p3 << " are compared, they are NOT equal.\n";}
    else
    {cout << "When points [p2]: " << p2 << " and [p3]: " << p3 << " are compared, they are equal.\n";}

    if (p2 == p4)
    {cout << "When points [p2]: " << p2 << " and [p4]: " << p4 << " are compared, they ARE equal.\n";}
    else
    {cout << "When points [p2]: " << p2 << " and [p4]: " << p4 << " are compared, they are NOT equal.\n";}
}

//Test overloaded <
void test_Overloaded_Less_Than_Operator() {
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1, 2, 3};
    double array_p5[] = {6, 7, 8};
    Point p2(NUM_DIMENSIONS, array_p2);
    Point p12(NUM_DIMENSIONS, array_p5);
    cout << "\nTesting overloaded < ...\n";

    if (p12 < p2) {
        cout << "When comparing [p12]: " << p12 << " with [p2]: " << p2 << endl;
        cout << "[p12] is less that [p2]\n";
    }
    else {
        cout << "When comparing [p12]: " << p12 << " with [p2]: " << p2 << endl;
        cout << "[p12] is greater that [p2]\n";
    }
}

//Test Overloaded >
void test_Overloaded_Greater_Than_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1, 2, 3};
    double array_p5[] = {6, 7, 8};
    Point p2(NUM_DIMENSIONS, array_p2);
    Point p12(NUM_DIMENSIONS, array_p5);
    cout << "\nTesting overloaded > ...\n";

    if (p12 > p2) {
        cout << "When comparing [p12]: " << p12 << " with [p2]: " << p2 << endl;
        cout << "[p12]: " << p12 << " is greater than [p2]: " << p2 << endl;
    }
    else {
        cout << "When comparing [p12]: " << p12 << " with [p2]: " << p2 << endl;
        cout << "[p12]: " << p12 << " is less that [p2]: " << p2 << endl;
    }
}

//Test Overloaded <=
void test_Overloaded_Less_Than_Equal_Operator(){
    const int NUM_DIMENSIONS = 3;
    double array_p3[] = {3,4,5};
    double array_p5[] = {6,7,8};
    Point p3(NUM_DIMENSIONS, array_p3);
    Point p12(NUM_DIMENSIONS, array_p5);

    cout << "\nTesting overloaded <= ...\n";
    if (p12<= p3)
    { cout << "[p3]: " << p3 << " is less than or equal to [p12]: " << p12 << endl;}
    else
    {cout << "Unfortunatly, [p12]: " << p12 << " is NOT less than or equal to [p3]: " << p3 << endl;}
}

//Test Overloaded >=
void test_Overloaded_Greater_Than_Equal_Operator() {
    const int NUM_DIMENSIONS = 3;
    double array_p3[] = {3, 4, 5};
    double array_p5[] = {6, 7, 8};
    Point p3(NUM_DIMENSIONS, array_p3);
    Point p12(NUM_DIMENSIONS, array_p5);

    cout << "\nTesting overloaded >= ...\n";
    if (p12 >= p3)
    {   cout << "[p12]: " << p12 << " is greater than or equal to [p3]: " << p3 << endl; }
    else
    {cout << "Unfortunatly, [p12]: " << p12 << " is NOT greater than or equal to [p3]: " << p3 << endl; }
}

//Function Definitions
//Cluster Class

//Test add  function
void test_add(){
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1, 2, 3};
    double array_p3[] = {3, 4, 5};
    double array_p4[] = {6, 7, 8};
    PointPtr clusterPoint2 = new Point(NUM_DIMENSIONS, array_p2);
    PointPtr clusterPoint3 = new Point(NUM_DIMENSIONS, array_p3);
    PointPtr clusterPoint4 = new Point(NUM_DIMENSIONS, array_p4);
    Cluster c1;

    cout << "\nTesting Cluster add function...\n";
    cout << "Adding point (6,7,8)...\n";
    c1.add(clusterPoint4);
    cout << "Adding point (3,4,5)...\n";
    c1.add(clusterPoint3);
    cout << "Adding point (1,2,3)...\n";
    c1.add(clusterPoint2);

    cout << "Three points have been added to cluster [c1] and arranged in order (lowest to highest):\n";
    cout << "Cluster [c1]: " << c1 << endl;
}

// test remove function
void test_remove() {
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1, 2, 3};
    double array_p3[] = {3, 4, 5};
    double array_p4[] = {6, 7, 8};
    PointPtr clusterPoint2 = new Point(NUM_DIMENSIONS, array_p2);
    PointPtr clusterPoint3 = new Point(NUM_DIMENSIONS, array_p3);
    PointPtr clusterPoint4 = new Point(NUM_DIMENSIONS, array_p4);
    Cluster c1;

    cout << "\nTesting Cluster remove function...\n";
    c1.add(clusterPoint4);
    c1.add(clusterPoint3);
    c1.add(clusterPoint2);
    cout << "Cluster [c1] contains the following points: " << c1 << endl;

    cout << "Now removing point (1,2,3)...\n";
    c1.remove(clusterPoint2);
    cout << "Cluster [c1] now contains " << c1 << endl;
}

void test_Cluster_Assignment_Operator()
{
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {1, 2, 3};
    double array_p3[] = {3, 4, 5};
    double array_p4[] = {6, 7, 8};
    double array_p5[] = {9, 10, 11};
    PointPtr clusterPoint2 = new Point(NUM_DIMENSIONS, array_p2);
    PointPtr clusterPoint3 = new Point(NUM_DIMENSIONS, array_p3);
    PointPtr clusterPoint4 = new Point(NUM_DIMENSIONS, array_p4);
    PointPtr clusterPoint5 = new Point(NUM_DIMENSIONS, array_p5);
    Cluster c1;
    cout << "\nTesting Cluster add function...\n";
    cout << "Adding point (6,7,8)...\n";
    c1.add(clusterPoint4);
    cout << "Adding point (3,4,5)...\n";
    c1.add(clusterPoint3);
    cout << "Adding point (1,2,3)...\n";
    c1.add(clusterPoint2);

    cout << "Three points have been added to cluster [c1] and arranged in order (lowest to highest):\n";
    cout << "Cluster [c1]: " << c1 << endl << endl;

//Testing overloaded operator=
    cout << "\nTesting Overloaded Operator= ...\n";
    Cluster c2;
    c2 = c1;
    cout << "Assigning [c1] " << c1 << " to [c2]\n";
    cout << "c[2] now is assigned the points " << c2 << endl;
    cout << "\nCluster size of [c2] is " << c2.getSize() << endl;

    cout << "Adding a point to c[1]...\n";
    c1.add(clusterPoint2);
    cout << "Cluster [c1] is now: " << c1 << endl;
    cout << "But c[2] remains " << c2 << endl;
    cout << "Removing a point to c[2]...\n";
    c2.remove(clusterPoint3);
    cout << "c[2] is now " << c2 << endl;
    cout << "But c[1] remains " << c1 << endl;
    cout << "Adding a point to c[2]...\n";
    c2.add(clusterPoint3);
    cout << "c[2] is now " << c2 << endl;
    cout << "But c[1] remains " << c1 << endl;

    cout << "Checking reassignment...\n";
    c2 = c1;
    cout << "c[2] is now " << c2 << endl;
    cout << "And c[1] remains " << c1 << endl;

    Cluster c3(c1);
    cout << "c[3] is now " << c3 << endl;
}

//Testing Cluster Copy Constructor
void test_Cluster_Copy_Constructor()
{
    const int NUM_DIMENSIONS = 3;
    double array_p2[] = {21, 22, 23};
    double array_p3[] = {24, 25, 26};
    double array_p4[] = {27, 28, 29};
    double array_p5[] = {30, 31, 32};
    PointPtr clusterPoint2 = new Point(NUM_DIMENSIONS, array_p2);
    PointPtr clusterPoint3 = new Point(NUM_DIMENSIONS, array_p3);
    PointPtr clusterPoint4 = new Point(NUM_DIMENSIONS, array_p4);
    PointPtr clusterPoint5 = new Point(NUM_DIMENSIONS, array_p5);
    Cluster c1;
    c1.add(clusterPoint4);
    c1.add(clusterPoint3);
    c1.add(clusterPoint2);

    cout << "Three points have been added to cluster [c1] and arranged in order (lowest to highest):\n";
    cout << "Cluster [c1]: " << c1 << endl << endl;

    Cluster c3(c1);
    cout << "c[3] has been constructed with the points from c[1]: " << c3 << endl;
    c3.remove(clusterPoint2);
    cout << "\nNow removing point (21, 22, 23) from c[3]...\n";
    cout << "c[3] is now " << c3 << endl;
    cout << "And c[1] remains " << c1 << endl;
    cout << "Now combining c[3] and c[2]  (c[3] += c[1]...\n";
   c3 += c1;
    cout << "c[3] is now " << c3 << endl;
}