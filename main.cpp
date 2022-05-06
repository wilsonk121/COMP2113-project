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

void load_map(char ** &grid, int &grid_size_row, int &grid_size_col, int & current_row, int &current_col){	
    grid  = new char *[grid_size_row + 1];
    for (int i = 1; i <= grid_size_row ; i++){
       grid[i] = new char[grid_size_col + 1];
    } 
}

void input_record(char ** &grid,int &xfin,int &yfin,int &xcurr,int &ycurr){
    string name;
    ifstream fin;
    string line;

    char c;
    int x,y;
    cout<<"Input the file name: ";
    cin>>name;
    fin.open(name);
    if(fin.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fin>>grid_size_row>>grid_size_col>>xfin>>yfin>>xcurr>>ycurr;

    load_map(grid, grid_size_row, grid_size_col, xcurr, ycurr);
    while(fin>>c>>x>>y){
    grid[x][y]=c;
    }

}

void output_record(char ** grid, int grid_size_row, int grid_size_col, int finish_row, int finish_col){
    string name;
    ofstream fout;
    cout<<"Input the file name: ";
    cin>>name;
    fout.open(name);
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<grid_size_row<<endl;
    fout<<grid_size_col<<endl;
    fout<<finish_row<<endl;
    fout<<finish_col<<endl;

    for(int i=1;i<=grid_size_row;i++){
        for(int j=1;j<=grid_size_col;j++){
            if(grid[i][j]=='C'){
                fout<<i<<endl;
                fout<<j<<endl;

            }
        }
    }
    for(int i=1;i<=grid_size_row;i++){
        for(int j=1;j<=grid_size_col;j++){
            if(grid[i][j]=='U'||grid[i][j]=='D'||grid[i][j]=='L'||grid[i][j]=='R'||grid[i][j]=='C'){
                fout<<grid[i][j]<<endl;
                fout<<i<<endl;
                fout<<j<<endl;
            }

        }
    }

    fout.close();
    cout<<"game saved in "<<name<<endl;
    savegame=1;



}

void display(char ** grid, int grid_size_row, int grid_size_col, int current_row, int current_col, int finish_row, int finish_col, 
	     int distance_start_finish, int steps_walked){   
	cout << endl;
	for(int i=1;i<=grid_size_row;i++){
            for(int j=1;j<=grid_size_col;j++){
                cout<<"-"<<"-"<<"-"<<"-"<<"-";
            }
            cout<<endl;
            for(int j=1;j<=grid_size_col;j++){
                    switch(grid[i][j]){
                            case 'L':
                            cout<<"|"<<" < "<<"|";
                            break;
                            case 'R':
                            cout<<"|"<<" > "<<"|";
                            break;
                            case 'U':
                            cout<<"|"<<" ^ "<<"|";
                            break;
                            case 'D':
                            cout<<"|"<<" ! "<<"|";
                            break;
                            case 'C':
                            cout<<"|"<<" x "<<"|";
                            break;
                            default:
                            cout<<"|"<<"   "<<"|";
                            break;
                }
            }

            
            cout<<endl;
            for(int j=1;j<=grid_size_col;j++){
                cout<<"-"<<"-"<<"-"<<"-"<<"-";
            }
            cout<<endl;
        }
    //to provide statistics and hint to the player 
    distance_current_finish = abs(current_row - finish_row) + abs(current_col - finish_col);
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Shortest steps from current point to exit point: " << distance_current_finish << endl;
    cout << "Total steps walked from the starting point: " << steps_walked << endl;
}


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
        output_record(grid, grid_size_row, grid_size_col, finish_row, finish_col);    
}

int main(){
    
    char *temp=new char;
    cout << "Welcome you to the Mysterious Maze!" << endl;
    cout << "Do you want to start a new game (S) or load from a saved game (L): ";
    cin >> *temp;
    if (*temp=='S'){
        //to generate map with input size
        generate_map(grid, grid_size_row, grid_size_col, current_row, current_col);
        //to generate starting and finishing positions randomly
        random_start_and_finish_points(start_row, start_col, finish_row, finish_col, grid_size_row, grid_size_col, distance_start_finish);
        //to update the starting point as the current position	
        current_row = start_row;
        current_col = start_col;
        grid[current_row][current_col] = 'C';
    }
    else if (*temp=='L')
            input_record(grid, finish_row, finish_col, current_row, current_col);
    delete temp;
    
    //to ask the play to move his/her direction until reaching the finishing point or to save the game progress
    while ((current_row != finish_row || current_col != finish_col) && (savegame == 0)){
        display(grid, grid_size_row, grid_size_col, current_row, current_col, finish_row, finish_col, distance_start_finish, steps_walked);
        move_action(grid, steps_walked, current_row, current_col, grid_size_row, grid_size_col);
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
