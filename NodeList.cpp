/*
David Poiner - S3579878
COSC - Assignment1
*/

#include "NodeList.h"
#include <iostream>

// Constructor for the NodeList
NodeList::NodeList()
{
    this->length = 0;
}

// Destructor for the NodeList
NodeList::~NodeList()
{
    // ForEach node in nodes, delete node
    for (Node* node : nodes)
    {
        delete node;
    }
}

// Copy the constructor and create a DEEP COPY of the NodeList
// References NodeList and creates 'other;
NodeList::NodeList(NodeList &other)
{

    this->length = other.length;

    // Add new Nodes to DEEP COPY of NodeList
    for (int i = 0; i < other.length; i++)
    {
        Node* otherNode = other.getNode(i);
        Node* newNode = new Node(otherNode->getRow(), otherNode->getCol(), otherNode->getDistanceTraveled());
        nodes[i] = newNode;
    }
}

// Get current length
int NodeList::getLength()
{
    return length;
}

// Add the node provided to the NodeList being used for future reference
void NodeList::addElement(Node *newPos)
{
    int newRow = newPos->getRow();
    int newCol = newPos->getCol();
    int newDistanceTraveled = newPos->getDistanceTraveled();

    if (length < NODE_LIST_ARRAY_MAX_SIZE)
    {
        Node* newNode = new Node(newRow, newCol, newDistanceTraveled);
        nodes[length] = newNode;
        length++;
    }
}

// Get and return the node for the NodeList being used at position ' i '
Node* NodeList::getNode(int i)
{
    return nodes[i];
}

// Check of the node passed is already in the NodeList being used and rteturn the boolean result
bool NodeList::nodeExists(Node node)
{
    for (int i = 0; i < this->length; i++)
    {
        if (this->getNode(i)->isEqualTo(node))
        {
            return true;
        }
    }
    return false;
}