#include <iostream>
#include <string>
#include <cstdlib>  
#include "other.h"

//to move the player's direction and update the map with walking record and current position
//input: the direction that the player want to move toward and the number of steps want to take in that direction

void move_action(char ** &grid, int &steps_walked, int &current_row, int &current_col, int grid_size_row, int grid_size_col){
    
    char direction;
    int number_of_step;
    
    cout << "\nWhich direction you want to walk towards?" << endl;
    cout << "Enter 'U' for upwards, 'D' for downwards, 'L' for leftwarda, 'R' for rightwards ";
    cin >> direction;
    cout << "How many steps do you want to take? ";
    cin >> number_of_step;
    
    int next_row = current_row, next_col = current_col;
    
    if (number_of_step <= 0)
        cout << "Invalid number of steps. Please input again." << endl;
    else if (direction =='U' && number_of_step < current_row){
        grid[current_row][current_col] = 'U';
        next_row -= number_of_step;
    }
    else if (direction == 'D' && number_of_step <= (grid_size_row - current_row)){
        grid[current_row][current_col] = 'D';
        next_row += number_of_step;
    }
    else if (direction == 'L' && number_of_step < current_col){
        grid[current_row][current_col] = 'L';
        next_col -= number_of_step;
    }
            
    else if (direction == 'R' && number_of_step <= (grid_size_col - current_col)){
        grid[current_row][current_col] = 'R';
        next_col += number_of_step;
    }
    else 
        cout << "Walking outside of the map boundary. please input again" << endl;
	
    //to update the total steps walked and the current position
    if (current_row != next_row || current_col != next_col){
        steps_walked += number_of_step;
        current_row = next_row;
        current_col = next_col;
        grid[current_row][current_col] = 'C';
    }
        
}
