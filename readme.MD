David Poiner
S3579878
COSC - Advanced Programming Techniques - Assignment 1

Note:
Late submission was permitted by Ali on 28/12/2022 for a new due date of the 08/01/2023.
Email proof of this can be provided upon request.

Breif:
Implement a simplified algorithm for Path Planning, and use it with a simple simulated 2D robot moving around a room

Tests: 
Tests can be found in the 'testEnvs' folder and are labelled env1-10 with the .out file showing the solution to the shortest pathway to the Goal node. The tests progress in difficulty with 'env1.env' being the easiest and 'env10.env' beng the hardest.

MileStones Attempted:
Milestones 1-3 with milestone 3 only being partially implemented.

Compiling code:

Method1 - Launch from Terminal: Enter the following command into the terminal.
        " g++ -Wall -Werror -std=c++14 -O -o assign1 Node.cpp NodeList.cpp PathSolver.cpp main.cpp "

You can then launch by entering the following command into the terminal
        " ./assign1 <testEnvs/**TestEnv**.env  >testEnvs/**TestEnv**actual.out "


Method2 - Launch from VsCode: Open the program in VsCode and go to the launch.json file. When thereinclude the following command in the "args' section.

        "<", "${workspaceFolder}/testEnvs/**TestEnv**.env", ">", "${workspaceFolder}/testEnvs/**TestEnv**actualout.out"

Compile from terminal using the same command as above
        " g++ -Wall -Werror -std=c++14 -O -o assign1 Node.cpp NodeList.cpp PathSolver.cpp main.cpp "

Press F5 to Launch


Reflection:
I found this assignment quite hard to do as I have always found C++ a difficult language to learn. 
I made a mistake in 3.2.2 and this was because I did not read the assignment sheet thoroughly enough and let myself continue to code without referencing the sheet as often as I should have. 