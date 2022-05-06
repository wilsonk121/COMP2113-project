# COMP2113-project
Group No.: 36
Group members:
Kwok Yuet Wai, Wilson 3035921899
Shum Wing Yan, Selina 303580014

Topic: Maze Runner

Description:
“Find Your Way Out Mazes” is a single player maze game with one goal: to find a way to the exit point to escape from the Mysterious Maze. You can adjust the level of the challenge at the beginning of the game. Then, you will be placed at a random starting point and you can start figuring your way to get out using the hints given through random guesses. Let’s get started and good luck with your adventure!

Game Instrucions:
1. Start a new game: Input "S", and input a grid size of minimum of 2 for both the row and column sizes. Increase the grid size if you want to challenge yourself!
   Or, Load a saved game: Input "L", and input the file name of the saved game.
2. A map with your current location is revealed and the minimum required number of steps to the destination is shown.
3. Move your current position by entering 'U' for upwards, "D" for downwards, "L" for leftwards and "R" for rightwards. You are not allowed to walk outside the boundaries.
4. Enter the number of steps you wanted to take in the inputed direction. You have to walk for a minimum of 1 steps each time.
5. Your new current direction along with you walking path is shown.
6. Try to get to the destination! You will see “Congratulations! You have successfully escaped from the Mysterious Maze!!!” at the end of the game.
7. You cannot restart a game until you get to the destination, but you can save the game and continue to play next time by entering "S" towards the question "Which direction do you want to walk towards?".


Compilation and Execution Instructions:
1. All the files must be in the same directory
2. Input "g++ -pedantic-errors -std=c++11 main.cpp initialization.cpp move.cpp display.cpp -o main" 
3. Input "./main"

Features : 
1. The first feature is Monster encountering. Players have to battle with the monster if they step into a particular grid. Those grids are randomly assigned.(Generation of random game sets or events)
2. There will be various arrays used to store the game status. One of the significant statuses is the position of the player. We will use an int array to store it,  '1' represents the player, and '0' represents an empty grid. The status will be changed once the player moves.(Data structures for storing game status)
3. When memory is no longer required in the program, we will return it to the system . This can prevent the shortage of memory (Dynamic memory management)
4. User can save game and load game. System will output a file of game status and you can load it by input the file name(e.g. for loading/saving game status))
5. The program will be divided into several files to facilitate game development. For example, we will define a function map(), and it will be separated from the main function to increase readability and reusability.(Program codes in multiple files)
6. The user will be randomly placed in the maze , to increase the replay value (Generation of random game sets or events)



