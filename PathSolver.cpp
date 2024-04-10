/*
David Poiner - S3579878
COSC - Assignment1
*/
#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver()
{
    // TODO
}

PathSolver::~PathSolver()
{
    delete this->nodesExplored;
}

// Provides the robot with instuctions on how to move through the maze, know its current position and map its route
void PathSolver::forwardSearch(Env env)
{

    // Declare Nodes and NodeLists for use in the movement
    NodeList* openList = new NodeList();
    NodeList* finalList = new NodeList();
    Node* goalNode = findSymbol(env, SYMBOL_GOAL);
    Node* currentNode = findSymbol(env, SYMBOL_START);

    // If the current node is not null, enter the starting point in both the Open and Final NodeList
    if (currentNode != nullptr)
    {
        openList->addElement(currentNode);
        finalList->addElement(currentNode);
    }

    // Do - While loop for reading through the maze provided
    do
    {

        // Declare new nodes to use for tracking and flagging avaliable nodes for future movement
        Node* trackingNode = nullptr;
        Node* avaliableNode = nullptr;
        Node viableNode = Node(0, 0, 0);

        // Boolean to chheck whether the node provided exists in the NodeList or matched the current node position of the robot.
        bool nodeExistsInFinalList;
        bool newNodeMatchesCurrentNode;

        // Create char variables to read the nodes above, below, left and right of the current node.
        char up = currentNode->readNearbyNode(env, 'U');
        char down = currentNode->readNearbyNode(env, 'D');
        char left = currentNode->readNearbyNode(env, 'L');
        char right = currentNode->readNearbyNode(env, 'R');

        // If the viable node above, below, left or right of the currentNode is SYMBOL_EMPTY or SYMBOL_GOAL and if this node
        // does not exist in the openList, set the tracking node to the nearest viable node and add this node to the openList.
        // Then reset the viable node for re-use.
        if ((up == SYMBOL_EMPTY) || (up == SYMBOL_GOAL))
        {
            viableNode = currentNode->getNearbyNode(env, 'U');
            if (!openList->nodeExists(viableNode))
            {
                trackingNode = new Node(viableNode);
                openList->addElement(trackingNode);
            }
            viableNode = Node(0, 0, 0);
        }
        if ((down == SYMBOL_EMPTY) || (down == SYMBOL_GOAL))
        {
            viableNode = currentNode->getNearbyNode(env, 'D');
            if (!openList->nodeExists(viableNode))
            {
                trackingNode = new Node(viableNode);
                openList->addElement(trackingNode);
            }
            viableNode = Node(0, 0, 0);
        }
        if ((left == SYMBOL_EMPTY) || (left == SYMBOL_GOAL))
        {
            viableNode = currentNode->getNearbyNode(env, 'L');
            if (!openList->nodeExists(viableNode))
            {
                trackingNode = new Node(viableNode);
                openList->addElement(trackingNode);
            }
            viableNode = Node(0, 0, 0);
        }
        if ((right == SYMBOL_EMPTY) || (right == SYMBOL_GOAL))
        {
            viableNode = currentNode->getNearbyNode(env, 'R');
            if (!openList->nodeExists(viableNode))
            {
                trackingNode = new Node(viableNode);
                openList->addElement(trackingNode);
            }
            viableNode = Node(0, 0, 0);
        }

        // Open the open list, iterate through and set the avaliableNode to i
        // Retrieve the boolean for wither the node exists in the finalList or whether it is equal to the current node
        // If both are false, set the current node to the avaliable node and reset the avaliable node.
        for (int i = 0; i < openList->getLength(); i++)
        {

            avaliableNode = new Node(*(openList->getNode(i)));
            nodeExistsInFinalList = finalList->nodeExists(*avaliableNode);
            newNodeMatchesCurrentNode = avaliableNode->isEqualTo(*currentNode);

            if ((!newNodeMatchesCurrentNode &&
                 !nodeExistsInFinalList))
            {
                currentNode = avaliableNode;
                avaliableNode = nullptr;
            }
        }

        // Add the current node to the finalList
        finalList->addElement(currentNode);

    }

    // Do the above while the current node is not equal to the goalNode
    while (!currentNode->isEqualTo(*goalNode));

    // Create a node list for all the successfully mapped nodes for use in finding the path
    // Delets the other Nodes/NodeLists
    mappedNodes = new NodeList(*finalList);
    delete goalNode;
    delete openList;
    delete finalList;
}

// Get the mappedNodes NodeList
NodeList* PathSolver::getNodesExplored()
{
    return mappedNodes;
}

// Get the path from the mappedNodes NodeList
NodeList* PathSolver::getPath(Env env)
{

    // Delcare the NodeList and Node. Set the Node to the final position of the mappedNodes NodeList
    NodeList* finalPath = new NodeList();
    Node* goalNode = mappedNodes->getNode(mappedNodes->getLength() - 1);

    while (goalNode->getDistanceTraveled() > 0)
    {

        // Add the goalNode location to the finalPath NodeList
        finalPath->addElement(goalNode);

        // Declare the Nodes above, below, left and right of the goalNode
        Node top = goalNode->getNearbyNode(env, 'U');
        Node bottom = goalNode->getNearbyNode(env, 'D');
        Node left = goalNode->getNearbyNode(env, 'L');
        Node right = goalNode->getNearbyNode(env, 'R');

        // For loop to iterate over every Node in mappedNodes and check the distance travelled
        for (int i = 0; i < mappedNodes->getLength(); i++)
        {
            Node* currentNode = mappedNodes->getNode(i);

            // If the conditions are met, set the goal node to the current node
            if (currentNode->getDistanceTraveled() == goalNode->getDistanceTraveled() - 1 &&
                (top.isEqualTo(*currentNode) || bottom.isEqualTo(*currentNode) ||
                 left.isEqualTo(*currentNode) || right.isEqualTo(*currentNode)))
            {
                goalNode = currentNode;
                break;
            }
        }
    }

    // Return the final path mapped out
    return finalPath;
}

// Function used to find the Start and Goal symbol in the env file provided to the program.
Node* PathSolver::findSymbol(Env env, char c)
{
    Node* nodeSymbolPosition = nullptr;

    for (int row = 0; row < ENV_DIM; row++)
    {
        for (int col = 0; col < ENV_DIM; col++)
        {
            if (env[row][col] == c)
            {
                nodeSymbolPosition = new Node(row, col, 0);
            }
        }
    }

    return nodeSymbolPosition;
}