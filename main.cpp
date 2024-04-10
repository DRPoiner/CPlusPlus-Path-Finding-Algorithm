/*
David Poiner - S3579878
COSC - Assignment1
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

// Helper test functions
void testNode();
void testNodeList();

// Read a environment from standard input.
void readEnvStdin(Env env);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList *solution);

int main(int argc, char **argv)
{
    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    // std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    // testNode();
    // testNodeList();
    // std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Environment
    Env env;
    readEnvStdin(env);

    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    PathSolver* pathSolver = new PathSolver();
    pathSolver->forwardSearch(env);

    NodeList *exploredPositions = nullptr;
    exploredPositions = pathSolver->getNodesExplored();

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    NodeList* solution = pathSolver->getPath(env);

    printEnvStdout(env, solution);

    delete pathSolver;
    delete exploredPositions;
    delete solution;
}

void readEnvStdin(Env env)
{
    // Read the environment into a 2D array
    for (int row = 0; row < ENV_DIM; row++)
    {
        for (int col = 0; col < ENV_DIM; col++)
        {
            std::cin >> env[row][col];
        }
    }
}

void printEnvStdout(Env env, NodeList *solution)
{
    // Create for loop to look through the solution
    for (int i = solution->getLength() - 1; i >= 0; i--)
    {

        // Create node track while stepping through the solution
        Node* currentNode = solution->getNode(i);

        // Create the immediate node above, below, left and right of the current node
        Node topNode = currentNode->getNearbyNode(env, 'U');
        Node bottomNode = currentNode->getNearbyNode(env, 'D');
        Node leftNode = currentNode->getNearbyNode(env, 'L');
        Node rightNode = currentNode->getNearbyNode(env, 'R');

        // Enter the nodes above, below, left and right of the current node into a Node to iterate in a forEach loop
        Node potentialNodes[] = {topNode, bottomNode, leftNode, rightNode};

        // Create char variables to read the nodes above, below, left and right of the current node.
        char up = currentNode->readNearbyNode(env, 'U');
        char down = currentNode->readNearbyNode(env, 'D');
        char left = currentNode->readNearbyNode(env, 'L');
        char right = currentNode->readNearbyNode(env, 'R');

        // For each node in potential nodes
        for (Node node : potentialNodes)
        {

            // If the solution contains the node in potentialNodes enter the If statement
            // Then match the nodes character to see whether it matches SYMBOL_EMPTY or SYMBHOL_GOAL
            // If it does, add the corresponding symbol (found in Types.h) to the env at the row/col coordinates.
            if (solution->nodeExists(node))
            {
                if (((up == SYMBOL_EMPTY) || (up == SYMBOL_GOAL)))
                {
                    env[currentNode->getRow()][currentNode->getCol()] = UPWARD;
                }
                else if (((down == SYMBOL_EMPTY) || (down == SYMBOL_GOAL)))
                {
                    env[currentNode->getRow()][currentNode->getCol()] = DOWNWARD;
                }
                else if (((left == SYMBOL_EMPTY) || (left == SYMBOL_GOAL)))
                {
                    env[currentNode->getRow()][currentNode->getCol()] = LEFTWARD;
                }
                else if (((right == SYMBOL_EMPTY) || (right == SYMBOL_GOAL)))
                {
                    env[currentNode->getRow()][currentNode->getCol()] = RIGHTWARD;
                }
                break;
            }
        }
    }

    // Create a for loop to iterate through the rows and cols
    for (int row = 0; row < ENV_DIM; row++)
    {

        // Print the character at the coordinates.
        for (int col = 0; col < ENV_DIM; col++)
        {
            std::cout << env[row][col];
        }
        if (row != ENV_DIM - 1)
        {
            std::cout << std::endl;
        }
    }
}

void testNode()
{
    std::cout << "TESTING Node" << std::endl;

    // Make a Node and print out the contents
    Node* node = new Node(1, 1, 2);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;

    // Change Node and print again
    node = new Node(4, 2, 3);
    std::cout << node->getRow() << ",";
    std::cout << node->getCol() << ",";
    std::cout << node->getDistanceTraveled() << std::endl;
    delete node;
}

void testNodeList()
{
    std::cout << "TESTING NodeList" << std::endl;

    // Make a simple NodeList, should be empty size
    NodeList* nodeList = new NodeList();
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add a Node to the NodeList, print size
    Node* b1 = new Node(1, 1, 1);
    nodeList->addElement(b1);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Add second Nodetest
    Node* b2 = new Node(0, 0, 1);
    nodeList->addElement(b2);
    std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Test Get-ith - should be 0,0,1
    Node* getB = nodeList->getNode(1);
    std::cout << getB->getRow() << ",";
    std::cout << getB->getCol() << ",";
    std::cout << getB->getDistanceTraveled() << std::endl;

    // Print out the NodeList
    std::cout << "PRINTING OUT A NODELIST IS AN EXERCISE FOR YOU TO DO" << std::endl;
}