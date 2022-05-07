#ifndef OTHER_H
#define OTHER_H

//functions in initialization.cpp
void generate_map(char ** &grid, int &grid_size_row, int &grid_size_col, int & current_row, int &current_col);
void random_start_and_finish_points(int &start_row, int &start_col, int &finish_row, int &finish_col, int grid_size_row, int grid_size_col, int &distance_start_finish);
void input_record(char ** &grid, int &xfin, int &yfin, int &xcurr, int &ycurr, int &grid_size_row , int &grid_size_col, int &distance_start_finish, int &steps_walked);

//functions in move.cpp
bool move_action_valid (char direction, int number_of_step, int current_row, int current_col, int grid_size_row, int grid_size_col);
void move_action_path(char ** &grid, char direction, int number_of_step, int &next_row, int &next_col, int current_row, int current_col);
void move_action(char ** &grid, int &steps_walked, int &current_row, int &current_col, int grid_size_row, int grid_size_col, int finish_row, int finish_col, bool &savegame,int distance_start_finish);
void load_map(char ** &grid, int &grid_size_row, int &grid_size_col, int & current_row, int &current_col);
void output_record(char ** grid, int grid_size_row, int grid_size_col, int finish_row, int finish_col, bool &savegame, int distance_start_finish, int steps_walked);

//functions in display.cpp
void display(char ** grid, int grid_size_row, int grid_size_col, int current_row, int current_col, int finish_row, int finish_col, int distance_start_finish, int steps_walked);

#endif
