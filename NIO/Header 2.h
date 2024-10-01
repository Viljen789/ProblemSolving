//
//  Header.h
//  NIO
//
//  Created by Viljen Apalset Vassbø on 03/01/2023.
//

#ifndef Header_h
#define Header_h
struct Cell {
    int row;
    int col;
    Cell() {} // default constructor
    Cell(int r, int c) : row(r), col(c) {}
};

struct CellHash {
  std::size_t operator()(const Cell& c) const {
    return c.row * 100 + c.col;
  }
};

bool operator<(const Cell& lhs, const Cell& rhs) {
  return std::tie(lhs.row, lhs.col) < std::tie(rhs.row, rhs.col);
}



std::ostream& operator<<(std::ostream& out, const Cell& cell) {
  out << "(" << cell.row << ", " << cell.col << ")";
  return out;
}

// Check if a cell is valid (i.e., within the bounds of the labyrinth and not a wall).
bool IsValidCell(const std::vector<std::vector<char> >& labyrinth, const Cell& cell) {
    int num_rows = labyrinth.size();
    int num_cols = labyrinth[0].size();
    return cell.row >= 0 && cell.row < num_rows && cell.col >= 0 && cell.col < num_cols && labyrinth[cell.row][cell.col] != '#';
}


#endif /* Header_h */


/* main.cpp: #include <vector>
 #include <queue>
 #include <functional>
 #include <unordered_map>
 #include <iostream>
 #include <utility>
 #include "Header.h"


 using namespace std;

 // Definition for a cell in the labyrinth.

 // Find the fastest route through the labyrinth using Dijkstra's algorithm.
 std::vector<Cell> FindShortestRoute(std::vector<std::vector<char> > labyrinth, const Cell& start, const Cell& end) {
     std::unordered_map<Cell, int, CellHash> distances(labyrinth.size() * labyrinth[0].size());
     std::unordered_map<Cell, Cell, CellHash> parent(labyrinth.size() * labyrinth[0].size());
     std::priority_queue<pair<int, Cell>, vector<pair<int, Cell> >, std::greater<pair<int, Cell> > > q;
     
     distances[start] = 0;
     q.emplace(0, start);
     
     while (!q.empty()) {
         // Get the next cell in the queue.
         int distance = q.top().first;
         Cell cell = q.top().second;
         q.pop();
         
         // Check the four neighboring cells.
         std::vector<Cell> neighbors;
         neighbors.push_back(Cell(cell.row - 1, cell.col));
         neighbors.push_back(Cell(cell.row + 1, cell.col));
         neighbors.push_back(Cell(cell.row, cell.col - 1));
         neighbors.push_back(Cell(cell.row, cell.col + 1));
         
         for (const Cell& neighbor : neighbors) {
             if (IsValidCell(labyrinth, neighbor)) {
                 int new_distance = distance + 1;
                 if (new_distance < distances[neighbor]) {
                     // Update the distance and the parent of the cell.
                     distances[neighbor] = new_distance;
                     parent[neighbor] = cell;
                     q.emplace(new_distance, neighbor);
                 }
                 if (neighbor.row == end.row && neighbor.col == end.col) {
                     // The end of the labyrinth has been reached.
                     // Create a vector to store the path.
                     std::vector<Cell> path;
                     // Traverse the path backwards from the end cell to the start cell.
                     Cell current = end;
                     while (current.row != start.row || current.col != start.col) {
                         path.insert(path.begin(), current);
                         current = parent[current];
                     }
                     // Add the start cell to the beginning of the path.
                     path.insert(path.begin(), start);
                     return path;
                 }
             }
         }
     }
     // Return an empty vector if the end of the labyrinth was not reached.
     return std::vector<Cell>();
 }

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
     const auto& path = FindShortestRoute(labyrinth, start, end);
     for (const auto& cell : path) {
       std::cout << cell << " ";
     }
     std::cout << std::endl;


     // Print the path to the console.
     

     return 0;

 }




*/
