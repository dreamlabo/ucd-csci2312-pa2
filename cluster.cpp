//
// Created by Owner on 10/3/2015.
//

#include "cluster.h"
#include "point.h"
namespace  Clustering {


    //Destructer
    Cluster::~Cluster()
    {
        //std::cout << "\nHello from the destructor\n";
        LNode *nodePtr;
        LNode *nextNode;

        nodePtr = points;
        while (nodePtr != nullptr)
        {
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }




//Member Functions
    //Get size (added by me)
    int Cluster::getSize() const//( const PointPtr &cluster)
    { return size;}


    //add function
    //Seems to be working
    void Cluster::add(const PointPtr &addPoint) {

        LNodePtr newNode = new LNode;
        LNodePtr nodePtr;
        LNodePtr previousNode = points;
        newNode->p = addPoint;

        // If there are no nodes in the list
        // Make newNode the first node.
        if (size == 0)
        {
            points = newNode;
            newNode->next = nullptr;
        }
        else //Otherwise insert new node
        {
            nodePtr = points; //Position nodePtr at the head of the list
            previousNode = nullptr;  //Initialize previousNode to nullPtr

            while (nodePtr != nullptr && *(nodePtr->p) <= *(addPoint))
            {
                 previousNode = nodePtr;
                 nodePtr = nodePtr->next;
            }
            if (previousNode == nullptr)
            {
                points = newNode;
                newNode->next = nodePtr;
            }
            else
            {
                previousNode->next = newNode;
                newNode->next = nodePtr;
            }
        }
        size++;
    }
    //Remove
    //Seems to be working
    const PointPtr &Cluster::remove(const PointPtr &removePoint)
    {
        //std::cout << "\nHello from remove\n";
        LNodePtr nodePtr; //To traverse the list
        LNodePtr previousNode = points; //To point to the previous node

        if (size == 0)
            return removePoint;

        //If point to be removed is at head of list
        if (points->p == removePoint)
        {
            nodePtr = points->next;
            delete points;
            points = nodePtr;
        }
        else
        {
            nodePtr = points;
            while (nodePtr != nullptr && *(nodePtr->p) != *(removePoint))
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
            if (nodePtr)
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
        size --;
        return removePoint;

    }












//Overloaded Operators

    //Friends
    //Overloaded <<
    //Seems to be working
    std::ostream &operator<<(std::ostream &os, const Cluster &cluster)
    {
        LNodePtr target = cluster.points;
        if (cluster.size == 0)
            os << "Sorry, the list is empty\n";
        else
        {
            while (target != NULL)
            {
                int size = cluster.getSize();
                for (int index = 0; index < size; index++)
                {
                    os << *(target->p);
                    target = target->next;
                }
             }
        return os;
        }
    }










}//end Clustering