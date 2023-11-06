sdi2000067 - Δανάη Καραγεωργοπούλου
sdi2000261 - Μυρτώ Παράφορου

K23α - Ανάπτυξη Λογισμικού Για Πληροφοριακά Συστήματα
Άσκηση 1

- CONSEPT:
Nearest neighbor search (NSS) is an optimization problem that aims to find the point in a given dataset that is closest to a specific data point, by measuring the distance using a metric function.
The project consists of 2 KNSS methods, Brute-Force and NN-Descent.


1. KNN_BruteForce class for K-Nearest Neighbors Search:
The KNNBruteForce method computes the K-nearest neighbors for every data point within the dataset by calculating the distance between itself and every other data point. The class is templated, so that the user can work with various data types and distance metrics. 

2. NN_Descent class for K-Nearest Neighbors Search:
KNNDescent is a graph-based algorithm for approximate k-Nearest Neighbor Search (KNN). It constructs a K-nearest neighbors graph (KNNG) to find K-nearest neighbors for each data point in a dataset. The algorithm begins by creating a random graph where each vertex is connected to K random neighbors. Then, it  updates the graph by computing potential neighbors based on their distance and adding them to the graph, so at the end it has the K-nearest neighbors for each vertex.
The calculatePotentialNewNeighbors method computes the potential neighbors for each vertex by considering both neighbors and reverse neighbors of a vertex, based on their distances. Specifically, for each pair of potential neighbor:
It calculates the distance between two vertices using the specified metric.
It checks if the calculated distance is greater than the distance to the furthest neighbor. 
If the distance is greater, the comparison is skipped, as the new potential neighbor is not closer than the current farthest neighbor.
Otherwise, a new potential neighbor is found to be closer so it adds it to the set of potential neighbors and updateGraph is being called .
UpdateGraph deletes the farthest neighbor, inserts the needed one and finally updates the reverse neigbors accordingly. This process is being repeated for each vertex, so that we ensure that the whole graph has been updated.



- CLASSES:
1. KNNDescent:
KNNDescent class keeps the number of neighbors to be found (K), the size of the dataset (size), the dimensions of the dataset (dimensions) and the distance metric between datapoints (distanceFunction). Lastly, it keeps an array of pointers to Vertex objects, where each Vertex represents a datapoint in the dataset (vertexArray). 

2. Vertex:
Vertex class keeps a pointer to the actual data (datapoint), and 3 sets - Nearest Neighbors of this vertex (NN), Reverse Nearest Neighbors of this vertex (RNN) and potential neighbors that might replace other neighbors of this vertex in the future (PN).
Finaly, it keeps a map that stores distances to other vertices (distances).

3. Neighbor:
Neighbor class keeps a pointer to an integer representing the ID of the neighbor vertex (id) and a pointer to a double representing the distance between the current vertex and this neighbor.



- DISCLAIMER: 
ADTSet is based on the open-source code of the k08 class (https://github.com/chatziko-k08/lecture-code).

- HOW TO RUN:
make run ARG=X : Runs the main function for K = X
make test : Runs the tests