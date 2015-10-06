Compiler: G++,  Clion(1.1)

Final commit of UCD CSCI 2321 PA-2

Overview

PA-2 contains two classes, Point and Cluster.

Point Class:
The point class  can take in arbitrary dimension of doubles.
i.e.  (1,2), (1,2,3), (1,2,3,4), (1,2,3,4,5) etc.
Comparisons of points can be done using overloaded operators (<, >, ==,  !=)
Point arithmetic can be done using overloaded operators (+=,  -=,  *=, /=,  *,  /,  +, -) 
However, comparisons must be made within points of the same dimension. Points of different dimension cannot be compared.

Cluster Class
Points are stored in Clusters using Link Lists. 
Clusters can hold any number of points and are stored in a link list in lexicographic order, (Lowest to highest).
