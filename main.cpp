#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>      
#include <ctime>  
#include <fstream>
#include "other.h"

using namespace std;

char ** grid;
int grid_size_row, grid_size_col, current_row, current_col;
int start_row, start_col, finish_row, finish_col;
int distance_start_finish, distance_current_finish, steps_walked = 0;
bool savegame = 0;


int main(){
    
    char *temp = new char;
    cout << "Welcome you to the Mysterious Maze!" << endl;
    cout << "Do you want to start a new game (S) or load from a saved game (L): ";
    cin >> *temp;
    if (*temp =='S'){
        //to generate map with input size
        generate_map(grid, grid_size_row, grid_size_col, current_row, current_col);
        //to generate starting and finishing positions randomly
        random_start_and_finish_points(start_row, start_col, finish_row, finish_col, grid_size_row, grid_size_col, distance_start_finish);
        //to update the starting point as the current position	
        current_row = start_row;
        current_col = start_col;
        grid[current_row][current_col] = 'C';
    }
    else if (*temp =='L')
        input_record(grid, finish_row, finish_col, current_row, current_col, grid_size_row, grid_size_col, distance_start_finish, steps_walked);
    delete temp;
    
    //to ask the play to move his/her direction until reaching the finishing point or to save the game progress
    while ((current_row != finish_row || current_col != finish_col) && (savegame == 0)){
        display(grid, grid_size_row, grid_size_col, current_row, current_col, finish_row, finish_col, distance_start_finish, steps_walked);
        move_action(grid, steps_walked, current_row, current_col, grid_size_row, grid_size_col, finish_row, finish_col, savegame, distance_start_finish);
    }
	
    if (savegame == 0){
    //to indicate the finish of the game
    cout << "Congratulation! You've successfully escaped from the Mysterious Maze!!!" << endl;

    //to provide game record
    cout << "\nGame statistics: " << endl;
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Total steps walked: " << steps_walked << endl;
    }

    delete[] grid;
    
    return 0;
}
