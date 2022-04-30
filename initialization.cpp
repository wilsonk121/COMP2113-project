#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>  
#include <ctime>
#include "other.h"

using namespace std;

//to take in user input of grid size (row and column) and generate a respective map in a 2D dynamic array
void generate_map(char ** &grid, int &grid_size_row, int &grid_size_col, int & current_row, int &current_col){
    
    cout << "Please enter the size of the map row (minimum: 3)that you want to challenge: ";
    cin >> grid_size_row;
    cout << "Please enter the size of the map column (minimum: 3) that you want to challenge: ";
    cin >> grid_size_col;
	
    grid  = new char *[grid_size_row + 1];
    for (int i = 1; i <= grid_size_row ; i++){
       grid[i] = new char[grid_size_col + 1];
    }
    
}

//to generate the random starting point and finishing point
void random_start_and_finish_points(int &start_row, int &start_col, int &finish_row, int &finish_col, int grid_size_row, int grid_size_col){
    srand(time(NULL));	// initialize the seed for rand()
	
    start_row = rand() % (grid_size_row+1);
    start_col = rand() % (grid_size_col+1);
    finish_row = rand() % (grid_size_row+1);
    finish_col = rand() % (grid_size_col+1);
	
    //to generate a new random finish point if the generated starting point is same as the finishing point	
    while (start_row == finish_row && start_col == finish_col){
        finish_row = rand() % (grid_size_row+1);
        finish_col = rand() % (grid_size_col+1);
    }
    cout << "Starting position: Row " << start_row << " Column " << start_col << endl;
    cout << "Finishing position: Row " << finish_row  << " Column " << finish_col << endl;
}
