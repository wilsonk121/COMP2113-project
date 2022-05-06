#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>  
#include "other.h"

using namespace std;

void load_map(char ** &grid, int &grid_size_row, int &grid_size_col, int & current_row, int &current_col){	
    grid  = new char *[grid_size_row + 1];
    for (int i = 1; i <= grid_size_row ; i++){
       grid[i] = new char[grid_size_col + 1];
    } 
}

void output_record(char ** grid, int grid_size_row, int grid_size_col, int finish_row, int finish_col, bool &savegame){
    string name;
    ofstream fout;
    cout << "Input the file name: ";
    cin >> name;
    fout.open(name);
    if(fout.fail()){
        cout << "Error in file opening" << endl;
        exit(1);
    }
    fout << grid_size_row<<endl;
    fout << grid_size_col<<endl;
    fout << finish_row<<endl;
    fout << finish_col<<endl;

    for(int i = 1; i <= grid_size_row; i++){
        for(int j = 1; j <= grid_size_col; j++){
            if(grid[i][j] == 'C'){
                fout << i << endl;
                fout << j << endl;

            }
        }
    }
    for (int i = 1; i <= grid_size_row; i++){
        for (int j = 1; j <= grid_size_col; j++){
            if (grid[i][j] == 'U'|| grid[i][j] == 'D'|| grid[i][j] == 'L'|| grid[i][j] == 'R'||grid[i][j] == 'C'){
                fout << grid[i][j] << endl;
                fout << i << endl;
                fout << j << endl;
            }
        }
    }
    fout.close();
    cout << "game saved in " << name <<endl;
    savegame = 1;
}

//to check if the inputted direction and steps are valid
bool move_action_valid (char direction, int number_of_step, int current_row, int current_col, int grid_size_row, int grid_size_col){
    if (number_of_step <= 0){
        cout << "Invalid number of steps. Please input again." << endl;
        return false;
    }
    else if (direction =='U' && number_of_step < current_row)
        return true;
    else if (direction == 'D' && number_of_step <= (grid_size_row - current_row)){
        return true;
    }
    else if (direction == 'L' && number_of_step < current_col){
        return true;
    }
    else if (direction == 'R' && number_of_step <= (grid_size_col - current_col)){
        return true;
    }
    else {
        cout << "Walking outside of the map boundary. please input again" << endl;
        return false;
    }
}

// to update the grid with the latest walking path
void move_action_path(char ** &grid, char direction, int number_of_step, int &next_row, int &next_col, int current_row, int current_col){
    switch (direction) {
        case 'U':
            for (int i = 0; i < number_of_step; ++i){
                grid[current_row - i][current_col] = 'U';
            }
            next_row -= number_of_step;
            break;
        case 'D' :
            for (int i = 0; i < number_of_step; ++i){
                grid[current_row + i][current_col] = 'D';
            }
            next_row += number_of_step;
            break;
        case 'L':
            for (int i = 0; i < number_of_step; ++i){
                grid[current_row][current_col - i] = 'L';
            }
            next_col -= number_of_step;
            break;
        case 'R':
            for (int i = 0; i < number_of_step; ++i){
                grid[current_row][current_col + i] = 'R';
            }
            next_col += number_of_step;
            break;
    }
}

//to move the player's direction and update the map with walking record and current position
//input: the direction that the player want to move toward and the number of steps want to take in that direction
void move_action(char ** &grid, int &steps_walked, int &current_row, int &current_col, int grid_size_row, int grid_size_col, int finish_row, int finish_col, bool &savegame){
    
    char direction;
    int number_of_step;
    
    //to get valid players' input of direction and number of step
    do {
    cout << "\nWhich direction do you want to walk towards?" << endl;
    cout << "Enter 'U' for upwards, 'D' for downwards, 'L' for leftwards, 'R' for rightwards, 'S' for saving game"<< endl;
    cin >> direction;
    if (direction == 'S'){
        break;
    }
    cout << "How many steps do you want to take? ";
    cin >> number_of_step;
    }
    while (move_action_valid(direction,number_of_step, current_row, current_col, grid_size_row, grid_size_col) == false);
    
    if (direction!='S'){
    	//to update the walking path
    	int next_row = current_row, next_col = current_col;
    	move_action_path(grid, direction, number_of_step, next_row, next_col, current_row, current_col);
	
    //to update the total steps walked and the current position
    if (current_row != next_row || current_col != next_col){
	steps_walked += number_of_step;
	current_row = next_row;
	current_col = next_col;
	grid[current_row][current_col] = 'C';}
    	}
    else 
        output_record(grid, grid_size_row, grid_size_col, finish_row, finish_col,savegame);    
}

