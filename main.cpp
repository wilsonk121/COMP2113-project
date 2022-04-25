#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>      
#include <ctime>   
using namespace std;

void display(int grid_size_row,int grid_size_col,int current_row,int current_col){
    for(int i=0;i<grid_size_row;i++){
        for(int j=0;j<grid_size_col;j++){
            cout<<"╔"<<"═"<<"╬"<<"═"<<"╗";
        }
        cout<<endl;
        for(int j=0;j<grid_size_col;j++){
			if(i==current_row&&j==current_col){
				cout<<"╬"<<" "  <<"x"<<" "<<"╬";
			}
			else{
				cout<<"╬"<<" "  <<" "<<" "<<"╬";
			}
        }
        cout<<endl;
        for(int j=0;j<grid_size_col;j++){
            cout<<"╚"<<"═"<<"╬"<<"═"<<"╝";
        }
        cout<<endl;

    }
}

//take in user input of grid size and generate a respective random map
void generate_map(char ** grid, int &grid_size_row, int &grid_size_col, int & current_row, int &current_col){
    cout << "Input map size row: ";
    cin >> grid_size_row;
    cout << "Input map column: ";
    cin >> grid_size_col;

    grid  = new char *[grid_size_row + 1];
    for (int i = 1; i <= grid_size_row ; i++){
       grid[i] = new char[grid_size_col + 1];
    }
    
}


void random_start_and_finish_points(int &start_row, int &start_col, int &finish_row, int &finish_col, int grid_size_row, int grid_size_col){
    srand(time(NULL));	// initialize the seed for rand()
    start_row = rand() % (grid_size_row+1);
    start_col = rand() % (grid_size_col+1);
    finish_row = rand() % (grid_size_row+1);
    finish_col = rand() % (grid_size_col+1);

    

    while (start_row == finish_row && start_col == finish_col){
        finish_row = rand() % (grid_size_row+1);
        finish_col = rand() % (grid_size_col+1);
    }
    cout << "Starting position: Row " << start_row << " Column " << start_col << endl;
    cout << "Finishing position: Row " << finish_row  << " Column " << finish_col << endl;
}

void move_action(char **grid, int &steps_walked, int &current_row, int &current_col, int grid_size_row, int grid_size_col){
    
    cout << "Current position: Row " << current_row << " Column " << current_col << endl;
    
    char direction;
    int number_of_step;
    
    cout << "\nWhich direction you want to walk towards? ";
    cin >> direction;
    cout << "How many steps do you want to take? ";
    cin >> number_of_step;
    
    int next_row = current_row, next_col = current_col;
    
    if (number_of_step <= 0)
        cout << "Invalid number of step" << endl;
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
        cout << "Walking outside of the boundary, please input again" << endl;
    
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
    
    // generate map with input size
    generate_map(grid, grid_size_row, grid_size_col, current_row, current_col);
    
    //generate starting and finishing positions randomly
    random_start_and_finish_points(start_row, start_col, finish_row, finish_col, grid_size_row, grid_size_col);
    current_row = start_row;
    current_col = start_col;
    
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
        display(grid_size_row,grid_size_col,current_row,current_col);
        move_action(grid, steps_walked, current_row, current_col, grid_size_row, grid_size_col);
    }
    
    cout << "Congratulation! You've successful escaped from the maze!" << endl;
    cout << "\nGame statistics: " << endl;
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Total steps walked: " << steps_walked << endl;
    
    delete[] grid;
    
    return 0;
}
