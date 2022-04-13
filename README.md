# COMP2113-project
Group No.: 36
hi
Group members:
Kwok Yuet Wai, Wilson 3035921899
Shum Wing Yan, Selina 303580014

Topic: Maze

Description:
“Find Your Way Out Mazes” is a single player maze game with one goal: to find a way to the exit point to escape from the Mysterious Maze. You can adjust the level of the challenge at the beginning of the game. Then, you will be placed at a random start point and you can start figuring your way to get out. There’ll be some dangerous places with some monster. If you unfortunately stepped on those places, you’ll have to battle with the monster to pass through it! Otherwise you’ll have to waste more time and face more monsters in find another way out. Let’s get started! Good luck with your adventure!


Rules:
1.	Enter the grid size that you want to play in (increase the grid size if you want to challenge yourself!)
2.	The map with your current location is revealed
3.	Try to move by entering “upward”, “downward”, “leftward” and “rightward”
4.	After you enter a move, the map with your walking direction will be shown.
5.	If you land on a dangerous place, you will have to win a mini-game in order to pass through it. Follow the instruction on the screen. You'll go one step backward if you fail to win.
6.	Try to get to the destination! (You will see “Congratulations! You have escaped from the Mysterious Maze!!!”)



 Features : 
1. The first feature is Monster encountering. Players have to battle with the monster if they step into a particular grid. Those grids are randomly assigned.(Generation of random game sets or events)
2. There will be various arrays used to store the game status. One of the significant statuses is the position of the player. We will use an int array to store it,  '1' represents the player, and '0' represents an empty grid. The status will be changed once the player moves.(Data structures for storing game status)
3. When memory is no longer required in the program, we will return it to the system . This can prevent the shortage of memory (Dynamic memory management)
4. Though our game has a default map, players can change it by inputting a file (need to follow a certain format), then players can play on their customized map.(File input/output (e.g. for loading/saving game status))
5. The program will be divided into several files to facilitate game development. For example, we will define a function map(), and it will be separated from the main function to increase readability and reusability.(Program codes in multiple files)
6. The user will be randomly placed in the maze , to increase the replay value (Generation of random game sets or events)
7. the player can input their user name and grid size into a file, and input the file to the program(File input/output (e.g. for loading/saving game status))


