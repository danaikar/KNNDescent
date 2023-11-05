#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <chrono>
#include "ADTSet.h"
#include "ADTMap.h"

using namespace std;

class Neighbor;

double compare_ints(Pointer a, Pointer b);
double compare_distances(Pointer a, Pointer b);
int *create_int(int n);
void delete_data(float **data, uint32_t N);
void delete_int(void *a);
void delete_neighbor(void *a);
Neighbor *furthest_neighbor(Set s);
Neighbor *closest_neighbor(Set s);

void compare_results(int **array1, int **array2, int N, int K);

class Vertex
{
private:
    void *datapoint;
    Set NN;
    Set RNN;
    Set potentialNN;
    Map distances;

public:
    Vertex(void *_data);

    void *getData() const;
    void addNeighbor(Neighbor *neighbor);
    void addReverseNeighbor(Neighbor *neighbor);
    void addPotentialNeighbor(Neighbor *neighbor);
    void addDistance(int id, double dist);

    Set getNeighbors() const;
    Set getReverseNeighbors() const;
    Set getPotentialNeighbors() const;
    Map getDistances() const;

    void replaceNNSet(Set set);
    void replaceRNNSet(Set set);
    void resetPNNSet();
    void resetRNNSet();

    ~Vertex();
};

class Neighbor
{
private:
    int *id;
    double *distance;

public:
    Neighbor(int _id, double _distance);
    int *getid();
    double *getDistance();
    ~Neighbor();
};