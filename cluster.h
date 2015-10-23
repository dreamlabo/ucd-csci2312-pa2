#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"


namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

    struct LNode;
    typedef LNode *LNodePtr;

    struct LNode {
        PointPtr p;   //The value in this node
        LNodePtr next; //To  point to next node
        LNode (PointPtr pt, LNodePtr n) : p(pt), next(n) {}
    };


    class Cluster {
        int size;
        LNodePtr points;

    public:
        Cluster() : size(0), points(nullptr) {};

        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &); //Done

        Cluster &operator=(const Cluster &);  //Done
        ~Cluster(); //DONE?

        // Set functions: They allow calling c1.add(c2.remove(p));
        void add(const PointPtr &); //DONE
        const PointPtr &remove(const PointPtr &); //DONE?

        // Overloaded operators

        // IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &); //DONE
        friend std::istream &operator>>(std::istream &, Cluster &);

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs); //Seems to be working

        // - Members
        //getSize added by me
        int getSize() const; //DONE

        Cluster &operator+=(const Cluster &rhs); // union  //OH SO CLOSE ON THIS
        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference

        Cluster &operator+=(const Point &rhs); // add point
        Cluster &operator-=(const Point &rhs); // remove point

        // Set-destructive operators (duplicate points in the space)
        // - Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);

    };

}
#endif //CLUSTERING_CLUSTER_H
