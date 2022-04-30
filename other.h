#ifndef OTHER_H
#define OTHER_H

void generate_map(char ** &grid, int &grid_size_row, int &grid_size_col);
void random_start_and_finish_points(int &start_row, int &start_col, int &finish_row, int &finish_col, int grid_size_row, int grid_size_col);
void move_action(char **&grid, int &steps_walked, int &current_row, int &current_col, int grid_size_row, int grid_size_col);

#endif
