#include "KNNGraph.hpp"
#include "classes.hpp"

using namespace std;

double compare_ints(Pointer a, Pointer b)
{
    return *(int *)a - *(int *)b;
}

void delete_int(void *a)
{
    delete (int *)a;
}

void delete_neighbor(void *a)
{
    delete (Neighbor *)a;
}

int *create_int(int n)
{
    int *x = new int;
    *x = n;
    return x;
}

void delete_data(float **data, uint32_t N)
{
    for (uint32_t i = 0; i < N; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

double compare_distances(Pointer a, Pointer b)
{
    Neighbor *n1 = (Neighbor *)a;
    Neighbor *n2 = (Neighbor *)b;

    double *distance1 = n1->getDistance();
    double *distance2 = n2->getDistance();

    if (*distance1 != *distance2)
        return 1000000 * (*distance1 - *distance2);

    return *(int *)n1->getid() - *(int *)n2->getid();
}

DataPoint::DataPoint(int _id, void *_datapoint) : id(_id), datapoint(_datapoint) {}

int DataPoint::getId() const
{
    return id;
}

void *DataPoint::getAddr() const
{
    return datapoint;
}

Vertex::Vertex(DataPoint *_data) : data(_data)
{
    NN = set_create(compare_distances, delete_neighbor);
    RNN = set_create(compare_distances, delete_neighbor);
    potentialNN = set_create(compare_distances, delete_neighbor);
}

void Vertex::addNeighbor(Neighbor *neighbor)
{
    set_insert(NN, neighbor);
}

void Vertex::addReverseNeighbor(Neighbor *neighbor)
{
    set_insert(RNN, neighbor);
}

void Vertex::addPotentialNeighbor(Neighbor *neighbor)
{
    set_insert(potentialNN, neighbor);
}

Set Vertex::getNeighbors() const
{
    return NN;
}

Set Vertex::getReverseNeighbors() const
{
    return RNN;
}

Set Vertex::getPotentialNeighbors() const
{
    return potentialNN;
}

Neighbor *Vertex::furthest_neighbor(Set s)
{
    SetNode lastNode = set_last(s);
    if (lastNode != NULL)
        return (Neighbor *)set_node_value(s, set_last(s));
    return NULL;
}

Neighbor *Vertex::closest_neighbor(Set s)
{
    SetNode firstNode = set_first(s);
    if (firstNode != NULL)
        return (Neighbor *)set_node_value(s, set_first(s));
    return NULL;
}

void Vertex::replaceNNSet(Set NewSet)
{
    set_destroy(NN);
    NN = NewSet;
}

void Vertex::replaceRNNSet(Set NewSet)
{
    set_destroy(RNN);
    RNN = NewSet;
}

void Vertex::resetPNNSet()
{
    set_destroy(potentialNN);
    potentialNN = set_create(compare_distances, delete_neighbor);
}

DataPoint *Vertex::getData() const
{
    return data;
}

Vertex::~Vertex()
{
    set_destroy(NN);
    set_destroy(RNN);
    set_destroy(potentialNN);
    delete data;
}

Neighbor::Neighbor(int _id, double _distance)
{
    id = new int;
    *id = _id;
    distance = new double;
    *distance = _distance;
}

int *Neighbor::getid()
{
    return id;
}

double *Neighbor::getDistance()
{
    return distance;
}

Neighbor::~Neighbor()
{
    delete id;
    delete distance;
}
