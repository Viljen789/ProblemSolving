
#include <iostream>
#include <vector>
#include <initializer_list>
#include <iostream>





// Definition for a cell in the labyrinth.
struct Cell {
  int row;
  int col;
  Cell(int r, int c) : row(r), col(c) {}
};

// Check if a cell is valid (i.e., within the bounds of the labyrinth and not a wall).
bool IsValidCell(const std::vector<std::vector<char> >& labyrinth, const Cell& cell) {
  int num_rows = labyrinth.size();
  int num_cols = labyrinth[0].size();
  return cell.row >= 0 && cell.row < num_rows && cell.col >= 0 && cell.col < num_cols && labyrinth[cell.row][cell.col] != '#';
}

// Find the fastest route through the labyrinth.
std::vector<Cell> FindFastestRoute(std::vector<std::vector<char> > labyrinth, const Cell& start, const Cell& end) {
  std::vector<Cell> path;
  std::vector<std::vector<bool> > visited(labyrinth.size(), std::vector<bool>(labyrinth[0].size(), false));
  std::vector<Cell> queue;
  queue.push_back(start);
  visited[start.row][start.col] = true;

  while (!queue.empty()) {
    Cell cell = queue.front();
    queue.erase(queue.begin());
    path.push_back(cell);

    if (cell.row == end.row && cell.col == end.col) {
      // The end of the labyrinth has been reached.
      return path;
    }

    // Check the four neighboring cells.
    std::vector<Cell> neighbors;
    neighbors.push_back(Cell(cell.row - 1, cell.col));
    neighbors.push_back(Cell(cell.row + 1, cell.col));
    neighbors.push_back(Cell(cell.row, cell.col - 1));
    neighbors.push_back(Cell(cell.row, cell.col + 1));

    for (const Cell& neighbor : neighbors) {
      if (IsValidCell(labyrinth, neighbor) && !visited[neighbor.row][neighbor.col]) {
        queue.push_back(neighbor);
        visited[neighbor.row][neighbor.col] = true;
      }
    }
  }

  // No path was found.
  return {};
}


// ...

int main() {
  std::vector<std::vector<char> > labyrinth;
  // Use the vector constructor to create a vector of characters for each row.
  std::vector<char> row1 = {'S', '#', '.', '.', '.', '.', '.', '.', '.', 'E'};
  std::vector<char> row2 = {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'};
  std::vector<char> row3 = {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'};
  std::vector<char> row4 = {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'};
  std::vector<char> row5 = {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'};
  std::vector<char> row6 = {'.', '#', '.', '#', '#', '#', '#', '#', '.', '#'};
  std::vector<char> row7 = {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'};
  std::vector<char> row8 = {'.', '#', '#', '#', '#', '#', '.', '#', '.', '.'};
  std::vector<char> row9 = {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
  // Use the push_back method to add each vector to the labyrinth.
  labyrinth.push_back(row1);
  labyrinth.push_back(row2);
  labyrinth.push_back(row3);
  labyrinth.push_back(row4);
  labyrinth.push_back(row5);
  labyrinth.push_back(row6);
  labyrinth.push_back(row7);
  labyrinth.push_back(row8);
  labyrinth.push_back(row9);
    

    // ...

    // Define the start and end cells.
    Cell start(0, 0);
    Cell end(labyrinth.size() - 1, labyrinth[0].size() - 1);

    // Find the fastest route through the labyrinth.
    std::vector<Cell> path = FindFastestRoute(labyrinth, start, end);

    // Print the path to the console.
    for (const Cell& cell : path) {
      std::cout << "(" << cell.row << ", " << cell.col << ")" << std::endl;
    }

    return 0;

}




