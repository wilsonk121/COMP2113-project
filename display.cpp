#include <iostream>
#include <iomanip>
#include <string>
#include "other.h"
using namespace std;
//to display the essential information for the game such as map, user location, distance from the end point
void display(char ** grid, int grid_size_row, int grid_size_col, int current_row, int current_col, int finish_row, int finish_col, 
	     int distance_start_finish, int steps_walked){   
	cout << endl;
	for(int i = 1; i <= grid_size_row; i++){
            for(int j = 1;j <= grid_size_col; j++){
                cout << "-" << "-" << "-" << "-" << "-";
            }
            cout << endl;
            for(int j = 1; j <= grid_size_col; j++){
                    switch(grid[i][j]){
                            case 'L':
                            cout << "|" << " < " << "|";
                            break;
                            case 'R':
                            cout << "|" << " > " << "|";
                            break;
                            case 'U':
                            cout << "|" << " ^ " << "|";
                            break;
                            case 'D':
                            cout << "|" << " ! " << "|";
                            break;
                            case 'C':
                            cout << "|" << " x " << "|";
                            break;
                            default:
                            cout << "|" << "   " << "|";
                            break;
                }
            }

            
            cout<<endl;
            for(int j = 1; j <= grid_size_col; j++){
                cout << "-" << "-" << "-" << "-" << "-";
            }
            cout << endl;
        }
    //to provide statistics and hint to the player 
    distance_current_finish = abs(current_row - finish_row) + abs(current_col - finish_col);
    cout << "Shortest steps from starting point to exit point: " << distance_start_finish << endl;
    cout << "Shortest steps from current point to exit point: " << distance_current_finish << endl;
    cout << "Total steps walked from the starting point: " << steps_walked << endl;
}
