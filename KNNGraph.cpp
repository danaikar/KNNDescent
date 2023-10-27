#include "KNNGraph.hpp"

using namespace std;


int compare_ints(Pointer a, Pointer b) {
    return *(int *)a - *(int *)b;
}


double compare_distances(Pointer a, Pointer b) {
    Neighbor *n1 = (Neighbor*)a;
    Neighbor *n2 = (Neighbor*)b;

    double *distance1 = n1->getDistance();
    double *distance2 = n2->getDistance();
    
    if(*distance1 != *distance2) 
        return 1000000*(*distance1 - *distance2);
    
    return *(int *)n1->getid() - *(int *)n2->getid();
}

DataPoint::DataPoint(int _id, void *_datapoint) : id(_id), datapoint(_datapoint) {}

int DataPoint::getId() const {
    return id;
}

void *DataPoint::getAddr() const {
    return datapoint;
}


Vertex::Vertex(DataPoint *_data) : data(_data) {
    NN = set_create(compare_distances, NULL);
    RNN = set_create(compare_distances, NULL);
    potentialNN = set_create(compare_distances, NULL);
    usedIds = set_create(compare_distances, NULL);
}

void Vertex::addNeighbor(Neighbor *neighbor) {
    set_insert(NN, neighbor);
}

void Vertex::addReverseNeighbor(Neighbor *neighbor) {
    set_insert(RNN, neighbor);
}

void Vertex::addPotentialNeighbor(Neighbor *neighbor) {
    set_insert(potentialNN, neighbor);
}

int Vertex::findNeighbor(int id) {
    if(set_find(usedIds, (void*)&id) == NULL)
        return 0;
    cout << "found the same id\n";
    return 1;
}

Set Vertex::getNeighbors() const {
    return NN;
}

Set Vertex::getReverseNeighbors() const {
    return RNN;
}

Set Vertex::getPotentialNeighbors() const {
    return potentialNN;
}

Set Vertex::getUsedIds() const {
    return usedIds;
}

DataPoint *Vertex::getData() const {
    return data;
}

Neighbor::Neighbor(int _id, double _distance) {
    id = new int;
    *id = _id;
    distance = new double;
    *distance = _distance;
    flag = 0;
    // cout << "Constructed neighbor no:" << _id << " with distance:" << _distance << " \n";
}

int *Neighbor::getid() {
    return id;
}

double *Neighbor::getDistance() {
    return distance;
}
