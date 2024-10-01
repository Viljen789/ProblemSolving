#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>


// Definition for a cell in the labyrinth.
struct Cell {
  int row;
  int col;
  Cell(int r, int c) : row(r), col(c) {}
};

// Overload the == operator for the Cell type.
bool operator==(const Cell& lhs, const Cell& rhs) {
  return lhs.row == rhs.row && lhs.col == rhs.col;
}


// Check if a cell is valid (i.e., within the bounds of the labyrinth and not a wall).
bool IsValidCell(const std::vector<std::vector<char> >& labyrinth, const Cell& cell) {
  int num_rows = labyrinth.size();
  int num_cols = labyrinth[0].size();
  return cell.row >= 0 && cell.row < num_rows && cell.col >= 0 && cell.col < num_cols && labyrinth[cell.row][cell.col] != '#';
}

// Find the fastest route through the labyrinth using Dijkstra's algorithm.
std::vector<Cell> FindFastestRoute(std::vector<std::vector<char> > labyrinth, const Cell& start, const Cell& end) {
    std::vector<std::vector<Cell> > parent(labyrinth.size(), std::vector<Cell>(labyrinth[0].size(), Cell(-1, -1)));
  std::vector<std::vector<int> > cost(labyrinth.size(), std::vector<int>(labyrinth[0].size(), -1));
  std::unordered_map<int, int> row_to_id;
  std::unordered_map<int, int> col_to_id;
  std::priority_queue<std::pair<int, Cell>, std::vector<std::pair<int, Cell> >, std::greater<std::pair<int, Cell> > > pq;

  int id = 0;
  for (int i = 0; i < labyrinth.size(); ++i) {
    for (int j = 0; j < labyrinth[i].size(); ++j) {
      row_to_id[i] = id;
      col_to_id[j] = id;
      ++id;
    }
  }

  cost[start.row][start.col] = 0;
  pq.push(std::pair<int, Cell>(0, start));

  while (!pq.empty()) {
    // Get the cell with the lowest cost.
    std::pair<int, Cell> top = pq.top();
    pq.pop();
    int distance = top.first;
    Cell cell = top.second;

    if (cell == end) {
      // The end of the labyrinth has been reached.
      std::vector<Cell> path;
      while (cost[cell.row][cell.col] != 0) {
        path.push_back(cell);
        cell = parent[cell.row][cell.col];
      }
     

    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
  }

  // Check the four neighboring cells.
  std::vector<Cell> neighbors;
  neighbors.push_back(Cell(cell.row - 1, cell.col));
  neighbors.push_back(Cell(cell.row + 1, cell.col));
  neighbors.push_back(Cell(cell.row, cell.col - 1));
  neighbors.push_back(Cell(cell.row, cell.col + 1));

  for (const Cell& neighbor : neighbors) {
    if (IsValidCell(labyrinth, neighbor) && cost[neighbor.row][neighbor.col] > distance + 1) {
      // Update the cost and path of the neighbor.
      cost[neighbor.row][neighbor.col] = distance + 1;
      parent[neighbor.row][neighbor.col] = cell;
      pq.push(std::pair<int, Cell>(distance + 1, Cell(neighbor.row, neighbor.col)));
    }
  }
}

// No path was found.
return {};
}

int main() {
    // Create the labyrinth.
    std::vector<char> row1 = {'S', '#', '.', '.', '.', '.', '.', '.', '.', 'E'};
    std::vector<char> row2 = {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'};
    std::vector<char> row3 = {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'};
    std::vector<char> row4 = {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'};
    std::vector<char> row5 = {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'};
    std::vector<char> row6 = {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'};
    std::vector<char> row7 = {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'};
    std::vector<char> row8 = {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'};
    std::vector<char> row9 = {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'};
    // Use the push_back method to add each vector to the labyrinth.
    std::vector<std::vector<char> > labyrinth;
;
    
    
    labyrinth.push_back(row1);
    labyrinth.push_back(row2);
    labyrinth.push_back(row3);
    labyrinth.push_back(row4);
    labyrinth.push_back(row5);
    labyrinth.push_back(row6);
    labyrinth.push_back(row7);
    labyrinth.push_back(row8);
    labyrinth.push_back(row9);
    
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
