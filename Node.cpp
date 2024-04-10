/*
David Poiner - S3579878
COSC - Assignment1
*/

#include "Node.h"
#include <iostream>


Node::Node(int row, int col, int dist_traveled)
{
    this->row = row;
    this->col = col;
    this->dist_traveled = dist_traveled;
}

Node::~Node(){
    // TODO
}

int Node::getRow(){
    return row;
}

int Node::getCol(){
    return col;
}

int Node::getDistanceTraveled(){
    return dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{
    dist_traveled = this->dist_traveled;
}

//Calculate the estimate distance to the goal for use in deciding the shortest path from Start to Goal
int Node::getEstimatedDist2Goal(Node* goal){
    /*
    NOTE: This is not currently working properly. I believe this is what is holding back the robots ability
    to calculate the shortest pathway from the Start to the Goal. This is covered in 3.2.2 of the assignment sheet where 
    the Manhatta_Distance is introduced to finish the algorithm correctly but I was not able to implement this in time. 
    */
    int estRow = std::abs(this->row - goal->getRow());
    int estCol = std::abs(this->col - goal->getCol());
    int estimatedDistance = std::abs(dist_traveled + estRow + estCol);
    return estimatedDistance;
}   

//Read the character of the node above, below, left or right of the current Node.
//The direction requested is provided as a Char, then a switch case is used to return the x,y coordinates.
char Node::readNearbyNode(Env env, char direction) {

    int row = this->row;
    int col = this->col;

    switch (direction) {
        case 'U':
            row = this->row - 1;
            break;
        case 'D':
            row = this->row + 1;
            break;
        case 'L':
            col = this->col - 1;
            break;
        case 'R':
            col = this->col + 1;
            break;
    }

    return env[row][col];
}

//Collect the information of the node above, below, left or right
//TThe direction requested is provided as a Char, then a switch case is used to return the row, col and distance travelled. 
Node Node::getNearbyNode(Env env, char direction) {
    int rowRead = this->row;
    int colRead = this->col;

    switch (direction) {
        case 'U':
            rowRead = this->row - 1;
            break;
        case 'D':
            rowRead = this->row + 1;
            break;
        case 'L':
            colRead = this->col - 1;
            break;
        case 'R':
            colRead = this->col + 1;
            break;
    }

    return Node(rowRead, colRead, this->dist_traveled + 1);
}

//Basic boolean function to check whether the node provided is the same as the current Node. 
//Returns either true or false.
bool Node::isEqualTo(Node node){

    if( (this->row == node.getRow()) && (this->col == node.getCol()) ){
        return true;
    }
    else{
        return false;
    }

}