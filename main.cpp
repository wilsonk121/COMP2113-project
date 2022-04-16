#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstdlib>      
#include <ctime>        


void print_layout(int grid_size_row, int grid_size_col){
    for(int i = 0; i < grid_size_row; i++){
        for (int j = 0; j < grid_size_col; j++){
            cout << "╔" << "═" << "╬" << "═" << "╗";
        }
        cout << endl;
        for (int j = 0; j < grid_size_col; j++){
            cout << "╬" << " " << " " << " " << "╬";
        }
        cout << endl;
        for (int j = 0; j < grid_size_col; j++){
            cout<<"╚"<<"═"<<"╬"<<"═"<<"╝";
        }
        cout << endl;
    }
}

void random_start_and_finish_points(int &start_row, int &start_col, int &finish_row, int &finish_col, int grid_size_row, int grid_size_col){
    srand(time(NULL));	// initialize the seed for rand()
    start_row = rand() % grid_size_row;
    start_col = rand() % grid_size_col;
    finish_row = rand() % grid_size_row;
    finish_col = rand() % grid_size_col;
    
    while (start_row == finish_col && start_col == finish_col){
        finish_row = rand() % grid_size_row;
        finish_col = rand() % grid_size_col;
    }
    cout << "Starting position: Row " << start_row + 1 << " Column " << start_col + 1 << endl;
    cout << "Finishing position: Row " << finish_row + 1 << " Column " << finish_col + 1 << endl;
}


int main(){
    
    //take in user input of grid size and generate a respective map
    int grid_size_row, grid_size_col;
    cin >> grid_size_row >> grid_size_col;
    char ** grid  = new char *[grid_size_row];
    for (int i = 0; i < grid_size_row; i++){
       grid[i] = new char[grid_size_col];
    }
    
    //randomly generate starting position and finishing position
    int start_row, start_col, finish_row, finish_col;
    random_start_and_finish_points(start_row, start_col, finish_row, finish_col, grid_size_row, grid_size_col);
    
    //initialize the starting position as the current position
    int current_row = start_row, current_col = start_col;
    
    grid[current_row][current_col] = 'C';
    
    int distance_start_finish = abs(start_row - finish_row) + abs(start_col - finish_col);
    int distance_current_finish = abs(current_row - finish_row) + abs(current_col - finish_col);
    int steps_walked = 0;
    
    
    
    
    
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Shortest steps from current point to exit point: " << distance_current_finish << endl;
    cout << "Total steps walked from the starting point: " << steps_walked << endl;
    
    for (int i = 0; i < grid_size_row; i++){
        for (int j = 0; j < grid_size_col; j++){
            if (grid[grid_size_row][grid_size_col]=='C')
                cout << "X" << " ";
            else 
                cout << "H  ";
            if (j = grid_size_col - 1)
                cout << endl;
        }
    }
    
    return 0;
}
