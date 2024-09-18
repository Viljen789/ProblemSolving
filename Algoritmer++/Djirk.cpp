#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>

// Define a hash function for the Cell type
struct CellHash {
  std::size_t operator()(const Cell& cell) const {
    return std::hash<int>()(cell.first) ^ std::hash<int>()(cell.second);
  }
};

// Use the custom hash function when defining the maps
using DistanceMap = std::unordered_map<Cell, int, CellHash>;
using ParentMap = std::unordered_map<Cell, Cell, CellHash>;


// Define a maze as a 2D grid of cells
using Maze = std::vector<std::vector<char>>;

// Define a pair of integers to represent a cell in the maze
using Cell = std::pair<int, int>;

// Define a map to store the distances of each cell from the start
using DistanceMap = std::unordered_map<Cell, int>;

// Define a priority queue to prioritize cells with the smallest distance
using PriorityQueue = std::priority_queue<std::pair<int, Cell>, std::vector<std::pair<int, Cell>>, std::greater<std::pair<int, Cell>>>;

// Define a map to store the parent cell for each cell in the shortest path
using ParentMap = std::unordered_map<Cell, Cell>;

// Define the possible movements from a cell
const std::vector<Cell> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// Function to find the shortest path through a maze using Dijkstra's algorithm
std::vector<Cell> dijkstra(const Maze& maze, const Cell& start, const Cell& goal) {
  // Create a distance map to store the distances of each cell from the start
  DistanceMap distances;
  // Create a priority queue to prioritize cells with the smallest distance
  PriorityQueue pq;
  // Create a parent map to store the parent cell for each cell in the shortest path
  ParentMap parents;

  // Initialize the distance of the start cell to 0 and all other cells to infinity
  distances[start] = 0;
  pq.emplace(0, start);
  for (int i = 0; i < maze.size(); i++) {
    for (int j = 0; j < maze[i].size(); j++) {
      Cell cell = {i, j};
      if (cell != start) {
        distances[cell] = std::numeric_limits<int>::max();
        pq.emplace(std::numeric_limits<int>::max(), cell);
      }
    }
  }

  // Iterate over the priority queue
  while (!pq.empty()) {
    // Get the cell with the smallest distance
      // auto [distance, cell] = pq.top();
  auto p = pq.top();
  int distance = p.first;
  Cell cell = p.second;

    pq.pop();

    // If we have reached the goal, we can stop the search
    if (cell == goal) {
      break;
    }

    // Otherwise, iterate over the possible movements from this cell
    for (const auto& move : moves) {
      // Calculate the new cell position
      int row = cell.first + move.first;
      int col = cell.second + move.second;

      // Check if the new cell is within the bounds of the maze and is not a wall
      if (row >= 0 && row < maze.size() && col >= 0 && col < maze[row].size() && maze[row][col] != '#') {
        // Calculate the new distance for this cell
        int new_distance = distance + 1;


    // Check if the new distance is better than the current distance
    if (new_distance < distances[{row, col}]) {
      // Update the distance and parent for this cell
      distances[{row, col}] = new_distance;
      parents[{row, col}] = cell;
        // pq.emplace(new_distance, {row, col});
  pq.push({new_distance, {row, col}});

    }
  }
}
}

// Construct the shortest path from the goal to the start by following the parents
std::vector<Cell> path;
Cell current = goal;
while (current != start) {
path.push_back(current);
current = parents[current];
}
path.push_back(start);
std::reverse(path.begin(), path.end());

return path;
}

int main() {
// Define a maze as a 2D grid of characters
Maze maze = {
{'S', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
{'.', '#', '.', '#', '.', '#', '#', '#', '.', '.'},
{'.', '#', '.', '#', '.', '.', '.', '#', '.', '.'},
{'.', '#', '.', '#', '#', '#', '.', '#', '.', '.'},
{'.', '#', '.', '.', '.', '.', '.', '#', '.', '.'},
{'.', '#', '#', '#', '#', '#', '#', '#', '.', '.'},
{'.', '#', '.', '.', '.', '.', '.', '#', '.', '.'},
{'.', '#', '#', '#', '#', '#', '#', '#', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '#', '.', '.', '.', '.', 'G'},
};

// Find the shortest path through the maze
auto path = dijkstra(maze, {0, 0}, {9, 9});

// Print the maze with the shortest path marked
for (int i = 0; i < maze.size(); i++) {
for (int j = 0; j < maze[i].size(); j++) {
if (std::find(path.begin(), path.end(), Cell{i, j}) != path.end()) {
std::cout << '*';
} else {
std::cout << maze[i][j];
}
std::cout << std::endl;
}

return 0;
}


