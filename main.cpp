#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstdlib>      
#include <ctime>        

void random_start_and_finish_points(int &start_row, int &start_col, int &finish_row, int &finish_col, int grid_size_row, int grid_size_col){
    srand(time(NULL));	// initialize the seed for rand()
    start_row = rand() % grid_size_row;
    start_col = rand() % grid_size_col;
    finish_row = rand() % grid_size_row;
    finish_col = rand() % grid_size_col;
    
    //seems does not work
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
    
    // generate starting position and finishing position randomly
    int start_row, start_col, finish_row, finish_col;
    random_start_and_finish_points(start_row, start_col, finish_row, finish_col, grid_size_row, grid_size_col);
    
    //initialize the starting position as the current position
    int current_row = start_row, current_col = start_col;
    
    //mark the current position as 'C' in the array
    grid[current_row][current_col] = 'C';
    
    int distance_start_finish = abs(start_row - finish_row) + abs(start_col - finish_col);
    int distance_current_finish = abs(current_row - finish_row) + abs(current_col - finish_col);
    int steps_walked = 0;
    
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Shortest steps from current point to exit point: " << distance_current_finish << endl;
    cout << "Total steps walked from the starting point: " << steps_walked << endl;
    
    char direction;
    int number_of_step;
    
    while (current_row != finish_row || current_col != finish_col) {
        cout << "Which direction you want to walk towards?";
        cin >> direction;
        cout << "How many steps do you want to take?";
        cin >> number_of_step;
        if (number_of_step <= 0)
            cout << "wrong number of step" << endl;
        else if (direction =='U' && number_of_step <= current_row ){
            current_row -= number_of_step;
            grid[current_row][current_col] = 'U';
            steps_walked += number_of_step;
            }
        else if (direction == 'D' && number_of_step < (grid_size_row - current_row)){
            current_row += number_of_step;
            grid[current_row][current_col] = 'D';
            steps_walked += number_of_step;
        }
        else if (direction == 'L' && number_of_step <= current_col){
            current_col -= number_of_step;
            grid[current_row][current_col] = 'L';
            steps_walked += number_of_step;
        }
            
        else if (direction == 'R' && number_of_step < (grid_size_col - current_col)){
            current_col += number_of_step;
            grid[current_row][current_col] = 'R';
            steps_walked += number_of_step;
        }
        else 
            cout << "Walking outside of the boundary, please input again" << endl;
        
        grid[current_row][current_col] = 'C';
    }
    
    cout << "Congratulation! You've successful escaped from the maze!" << endl;
    cout << "\nGame statistics: " << endl;
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Total steps walked: " << steps_walked << endl;
    
    delete[] grid;
    
    return 0;
}
