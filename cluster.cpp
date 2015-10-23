//
// Created by Owner on 10/3/2015.
//

#include "cluster.h"
#include "point.h"
namespace  Clustering {


// Copy Constructor
    Cluster::Cluster(const Cluster &rightSide) {
        std::cout << "Hello from copy constructor\n";
        LNodePtr current = rightSide.points;
        this->size = 0;

        while (current != nullptr) {
           this->add(current ->p);
           current = current->next;
        }
    }




// Overloaded operator=
    Cluster &Cluster::operator=(const Cluster &rightSide) {

        if (*this == rightSide) {
            std::cout << "Can't Self - Assign";
            return *this;
        }
        else {
            std::cout << "Hi from operator=\n";
            LNodePtr nodePtr = points; //to traverse the list
            LNodePtr nextNode; //to point to next node

            while (nodePtr != nullptr) {
                        nextNode = nodePtr->next; //save pointer to next node
                        delete nodePtr;
                        nodePtr = nextNode; //position ptr at the next node
                        size--;
                    }
               nodePtr = nullptr; //Do I need this?
            }
            LNodePtr rightSidePtr = rightSide.points;
                for (int i = 0; i < rightSide.getSize(); i++) {
                    add(rightSidePtr->p);
                    if (rightSidePtr->next != nullptr) {
                         rightSidePtr = rightSidePtr->next;
                    }
                }

        return *this;
    }


    //Destructer
    Cluster::~Cluster() {
        std::cout << "\nHello from the destructor\n";
        LNodePtr nodePtr = points; //to traverse the list
        LNodePtr nextNode; // To point to the next node


        // While nodePtr is not at the  head of the list
        while (nodePtr != nullptr) {
            //Save a pointer to the next node
            nextNode = nodePtr->next;
            // Delete the current node
            delete nodePtr;
            //position nodePtr at the next node
            nodePtr = nextNode;
            //Check to see that nextNode is not the last node in the list
            if (nextNode != nullptr)
            {
                nextNode = nextNode->next;
            }
        }
    }


//Member Functions
    //Get size (added by me)
    int Cluster::getSize() const//( const PointPtr &cluster)
    { return size; }

//add function
//Seems to be working
    void Cluster::add(const PointPtr &addPoint) {

        LNodePtr newNode = new LNode(addPoint,NULL);
        LNodePtr nodePtr;
        LNodePtr previousNode = points;
        newNode->p = addPoint;

        // If there are no nodes in the list
        // Make newNode the first node.
        if (points == nullptr) {
            points = newNode;
            newNode->next = nullptr;
        }
        else //Otherwise insert new node
        {
            nodePtr = points; //Position nodePtr at the head of the list
            previousNode = nullptr;  //Initialize previousNode to nullPtr

            while (nodePtr != nullptr && *(nodePtr->p) <= *(addPoint)) {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
            if (previousNode == nullptr) {
                points = newNode;
                newNode->next = nodePtr;
            }
            else {
                previousNode->next = newNode;
                newNode->next = nodePtr;
            }
        }
        size++;
    }

//Remove Function
//Seems to be working
    const PointPtr &Cluster::remove(const PointPtr &removePoint) {
        //std::cout << "\nHello from remove\n";
        LNodePtr nodePtr; //To traverse the list
        LNodePtr previousNode = points; //To point to the previous node

        //If list is empty
        if (points == nullptr)
            return removePoint;

        //If point to be removed is at head of list
        if (points->p == removePoint) {
            nodePtr = points->next;
            delete points;
            points = nodePtr;
        }
        else {
            nodePtr = points;
            while (nodePtr != nullptr && *(nodePtr->p) != *(removePoint)) {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
            if (nodePtr) {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
        size--;
        return removePoint;
    }


//Overloaded Operators

//Friends
//Overloaded <<
//Seems to be working
    std::ostream &operator<<(std::ostream &os, const Cluster &cluster) {
        LNodePtr target = cluster.points;
        if ((target->next == nullptr))
            os << "Sorry, the list is empty\n";
        else {
            while (target != NULL) {
                int size = cluster.getSize();
                for (int index = 0; index < size; index++) {
                    os << *(target->p);
                    target = target->next;
                }
            }
            return os;
        }
    }

// overloaded operator ==
// seems to be working
    bool operator==(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs) {
        //Check to see if clusters are of same size, if not return false
        if (lhs.size != rhs.size) {
            std::cout << "Can't compare clusters of different sizes\n";
            return false;
        }

        else // Clusters are of same size, so continue
         {
            LNodePtr targetRight = rhs.points; //set rhs curser to head
            LNodePtr targetLeft = lhs.points;  //set lhs curser head

            //  while the end of the list hasn't been reached
            while (targetRight != nullptr) {
               // std::cout << "Hello from first while\n";

                // checks to see if nodes don't match, if they don't, return false
                if (targetLeft->p != targetRight->p) {
                    return false;
                }
                else     // otherwise move to the  next node
                    targetRight = targetRight->next;
                    targetLeft = targetLeft->next;
                } //return to beg of while loop

               //if we reach here, all points are the same and we return true
                return true;
            }
        }

// Union
    Cluster &Cluster::operator+=(const Cluster &rightSide) {
        std::cout << "Hello from union of two clusters\n";
        //if calling cluster is empty, just add rightSide values to the calling cluster
        if (this == nullptr) {
            LNodePtr current = rightSide.points;
            while (current != nullptr) {
                add(current->p);
                current = current->next;
            }
        }
        else {
            LNodePtr callingObject = points;
            LNodePtr current = rightSide.points;
            //Check to see if there is something in both clusters
            if (callingObject == nullptr && current == nullptr) {
                return *this;
            }
            std::cout << getSize() << std::endl; // just using as code trace, remove for final

            int value = getSize(); //to use in for loop

            //add all left side points
            for (int i = 0; i < value; i++) {
                std::cout << " HI\n";
                add(callingObject->p);
                if (callingObject != nullptr)
                    callingObject = callingObject->next;
            }

            //now check all leftSide points against the right side
            int rightSideSize = rightSide.getSize();

            //start with first point of right side
            for (int i = 0; i < rightSideSize; i++) {
                bool isDuplicate = false;
                int value2 = getSize(); // reset size
                callingObject = points; //set/reset calling object to the head

                //to cycle through points of the callingObject
                for (int j = 0; j < value2; j++)
                    if (callingObject->p == current->p) {
                        isDuplicate = true;
                        callingObject = callingObject->next;
                        break;
                    }
                if (callingObject->p != current->p) {
                    isDuplicate = false;
                }
                if (isDuplicate == false) {
                    add(current->p);
                }

                if (current != nullptr) {
                    current = current->next;
                }
            }
        }
            return *this;
        }




}//end Clustering

