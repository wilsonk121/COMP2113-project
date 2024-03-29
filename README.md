# COMP2113-project
Group No.: 36
Group members:
Kwok Yuet Wai, Wilson 3035921899
Shum Wing Yan, Selina 3035800514

Topic: Maze Escape

Description:
“Find Your Way Out Mazes” is a single player maze game with one goal: to find a way to the exit point to escape from the Mysterious Maze. You can adjust the level of the challenge at the beginning of the game. Then, you will be placed at a random starting point and you can start figuring your way to get out using the hints given through random guesses. Let’s get started and good luck with your adventure!

Game Instrucions:
1. Start a new game: Input "S", and input a grid size for both the row and column sizes. Increase the grid size if you want to challenge yourself!
   Or, Load a saved game: Input "L", and input the file name of the saved game.
2. A map with your current location is revealed and the minimum required number of steps to the destination is shown.
3. Move your current position by entering 'U' for upwards, "D" for downwards, "L" for leftwards and "R" for rightwards. 
4. Enter the number of steps you wanted to take in the inputed direction. 
5. Your new current direction along with you walking path is shown.
6. Try to get to the destination! You will see “Congratulations! You have successfully escaped from the Mysterious Maze!!!” at the end of the game.
7. You cannot restart a game until you get to the destination, but you can save the game and continue to play next time by entering "S" towards the question "Which direction do you want to walk towards?".

Problem Statements:
1. In case the randomly generated starting point and exit point are the same, exit point will be automatically generated randomly again.
2. The index of row (starting from 1) is counted downwards and the index of column (starting from 1) is counted rightwards.
3. The minimum row size and column size is 2, and the maximum size is 30 to ensure the map show properly, and the inputs have to be integers.
4. The minimum number of steps each time is 1, and the input has to be integer.
5. Walking outside the boundaries is not allowed.


Compilation and Execution Instructions:
1. All the files must be in the same directory
2. Input "g++ -pedantic-errors -std=c++11 main.cpp initialization.cpp move.cpp display.cpp -o main" 
3. Input "./main"

Features : 
1. Player will be spawned in random starting position, also the exit location will be ramdomly assigned. (Generation of random game sets or events)
2. There will be a 2D-array used to store the game status. One of the significant statuses is the position of the player. An char in the specific indexes of the is being stored, i.e. 'C' represents the current position of the player, other chars are used to record the path walked by the player. The status will be changed once the player moves.(Data structures for storing game status)
3. Dynamic memory management is appiled in the array that used to store the map, as the size of the array storing the map depends on player's inputs. When memory is no longer required in the program, we will return it to the system. This can prevent the shortage of memory (Dynamic memory management)
4. Players can save game and load game. System will output a file storing the game status and the player can load it by inputting the file name when playing the game next time. (For loading/saving game status)
5. The program will be divided into several files to facilitate game development, such as initialization.cpp, display.cpp and move.cpp, they will be separated from the main function to increase readability and reusability.(Program codes in multiple files)
6. The program uses indentation properly especially in multidimensional arrays. Readable name are used in assigning to variable (Proper indentation and naming styles)
7. Comments are written to explain how the functions work. (In-code documentation)



