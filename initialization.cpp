#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>  
#include <ctime>
#include "other.h"

using namespace std;

//to take in user input of grid size (row and column) and generate a respective map in a 2D dynamic array
void generate_map(char ** &grid, int &grid_size_row, int &grid_size_col, int & current_row, int &current_col){
    
    cout << "Input map size row: ";
    cin >> grid_size_row;
    while (grid_size_row < 2) {
        cout << "Please input an integer greater than 1" << endl;
        cout << "Input map size row: ";
        cin >> grid_size_row;
    }

    cout << "Input map column: ";
    cin >> grid_size_col;
    while (grid_size_row < 2) {
        cout << "Please input an integer greater than 1" << endl;
        cout << "Input map size column: ";
        cin >> grid_size_row;
    }

    grid  = new char *[grid_size_row + 1];
    for (int i = 1; i <= grid_size_row ; i++){
       grid[i] = new char[grid_size_col + 1];
    }
    
}

//to generate the random starting point and finishing point
void random_start_and_finish_points(int &start_row, int &start_col, int &finish_row, int &finish_col, int grid_size_row, int grid_size_col, int &distance_start_finish){
    
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
    distance_start_finish = abs(start_row - finish_row) + abs(start_col - finish_col);
    cout << "\nStarting position: Row " << start_row << " Column " << start_col << endl;
    cout << "Finishing position: Row " << finish_row  << " Column " << finish_col << endl;
}

void input_record( char ** &grid, int &xfin, int &yfin, int &xcurr, int &ycurr, int &grid_size_row , int &grid_size_col){
    string name;
    ifstream fin;
    string line;

    char c;
    int x, y;
    cout << "Input the file name: ";
    cin >> name;
    fin.open(name);
    if(fin.fail()){
        cout << "Error in file opening"<<endl;
        exit(1);
    }
    fin >> grid_size_row >> grid_size_col >> xfin >> yfin >> xcurr >> ycurr;

    load_map(grid, grid_size_row, grid_size_col, xcurr, ycurr);
    while(fin >> c >> x >> y){
    grid[x][y] = c;
    }

}


