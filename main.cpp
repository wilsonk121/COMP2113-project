#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>      
#include <ctime>  
#include <fstream>
#include "other.h"

using namespace std;

void input_record(char ** grid){}

void output_record(char ** grid){
    ofstream fout;
    fout.open("saving.txt");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<""<<endl;
    fout.close();

}

void display(char ** grid,int grid_size_row,int grid_size_col,int current_row,int current_col){    
        char direction;
        direction=grid[current_row][current_col];
        grid_size_row=5;
        grid_size_col=5;
        current_row=1;
        current_col=2;
        for(int i=1;i<=grid_size_row;i++){
            for(int j=1;j<=grid_size_col;j++){
                cout<<"╔"<<"═"<<"╬"<<"═"<<"╗";
            }
            cout<<endl;
            for(int j=1;j<=grid_size_col;j++){
                    switch(grid[i][j]){
                            case 'L':
                            cout<<"╬"<<" ◄ "<<"╬";
                            break;
                            case 'R':
                            cout<<"╬"<<" ► "<<"╬";
                            break;
                            case 'U':
                            cout<<"╬"<<" ▲ "<<"╬";
                            break;
                            case 'D':
                            cout<<"╬"<<" ▼ "<<"╬";
                            break;
                            case 'C':
                            cout<<"╬"<<" x "<<"╬";
                            default:
                            cout<<"╬"<<"   "<<"╬";
                }
            }

            
            cout<<endl;
            for(int j=1;j<=grid_size_col;j++){
                cout<<"╚"<<"═"<<"╬"<<"═"<<"╝";
            }
            cout<<endl;
        }
}


//to take in user input of grid size (row and column) and generate a respective map in a 2D dynamic array
void generate_map(char ** &grid, int &grid_size_row, int &grid_size_col, int & current_row, int &current_col){
    
    cout << "Input map size row: ";
    cin >> grid_size_row;
    cout << "Input map column: ";
    cin >> grid_size_col;
	
    grid  = new char *[grid_size_row + 1];
    for (int i = 1; i <= grid_size_row ; i++){
       grid[i] = new char[grid_size_col + 1];
    }
    
}

//to generate the random starting point and finishing point
void random_start_and_finish_points(int &start_row, int &start_col, int &finish_row, int &finish_col, int grid_size_row, int grid_size_col){
    srand(time(NULL));	// initialize the seed for rand()
	
    start_row = rand() % grid_size_row + 1;
    start_col = rand() % grid_size_col + 1;
    finish_row = rand() % grid_size_row + 1;
    finish_col = rand() % grid_size_col + 1;
	
    //to generate a new random finish point if the generated starting point is same as the finishing point	
    while (start_row == finish_row && start_col == finish_col){
        finish_row = rand() % grid_size_row + 1;
    	finish_col = rand() % grid_size_col + 1;
    }
    cout << "\nStarting position: Row " << start_row << " Column " << start_col << endl;
    cout << "Finishing position: Row " << finish_row  << " Column " << finish_col << endl;
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
void move_action(char ** &grid, int &steps_walked, int &current_row, int &current_col, int grid_size_row, int grid_size_col){
    
    char direction;
    int number_of_step;
    
    //to get valid players' input of direction and number of step
    do {
    cout << "\nWhich direction you want to walk towards?" << endl;
    cout << "Enter 'U' for upwards, 'D' for downwards, 'L' for leftwarda, 'R' for rightwards"<< endl;
    cin >> direction;
    cout << "How many steps do you want to take? ";
    cin >> number_of_step;
    }
    while (move_action_valid(direction,number_of_step, current_row, current_col, grid_size_row, grid_size_col) == false);
    
    //to update the walking path
    int next_row = current_row, next_col = current_col;
    move_action_path(grid, direction, number_of_step, next_row, next_col, current_row, current_col);
	
    //to update the total steps walked and the current position
    if (current_row != next_row || current_col != next_col){
        steps_walked += number_of_step;
        current_row = next_row;
        current_col = next_col;
        grid[current_row][current_col] = 'C';
    }
        
}

int main(){
    
    int grid_size_row, grid_size_col, current_row, current_col;
    int start_row, start_col, finish_row, finish_col;
    
    char ** grid;
    
    cout << "Welcome you to the Mysterious Maze!" << endl;
    //to generate map with input size
    generate_map(grid, grid_size_row, grid_size_col, current_row, current_col);
    
    //to generate starting and finishing positions randomly
    random_start_and_finish_points(start_row, start_col, finish_row, finish_col, grid_size_row, grid_size_col);
    //to update the starting point as the current position	
    current_row = start_row;
    current_col = start_col;
    grid[current_row][current_col] = 'C';

    //to provide game statistics and hint  
    int distance_start_finish = abs(start_row - finish_row) + abs(start_col - finish_col);
    int distance_current_finish = abs(current_row - finish_row) + abs(current_col - finish_col);
    int steps_walked = 0;
    
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Shortest steps from current point to exit point: " << distance_current_finish << endl;
    cout << "Total steps walked from the starting point: " << steps_walked << endl;
    
    //to ask the play to move his/her direction until reaching the finishing point
    while (current_row != finish_row || current_col != finish_col) {
        display(grid, grid_size_row, grid_size_col, current_row, current_col);
        move_action(grid, steps_walked, current_row, current_col, grid_size_row, grid_size_col);
    }
	
    //to indicate the finish of the game
    cout << "Congratulation! You've successfully escaped from the Mysterious Maze!!!" << endl;

    //to provide game record
    cout << "\nGame statistics: " << endl;
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Total steps walked: " << steps_walked << endl;
    
    delete[] grid;
    
    return 0;
}
