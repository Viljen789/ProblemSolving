#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

// Define a pair of integers to represent a position in the labyrinth.
typedef std::pair<int, int> Position;

// Define a structure to represent a node in the search tree.
struct Node {
  Position pos;   // The position of the node in the labyrinth.
  int steps;      // The number of steps taken to reach this node.
  Node* parent;   // The parent node in the search tree.
};

// Define a function to perform the breadth-first search.
int findShortestPath(const std::vector<std::vector<char> >& labyrinth,
                     const Position& start,
                     const Position& end) {
  // Create a queue to hold the nodes that need to be explored.
  std::queue<Node*> q;

  // Create a 2D vector to keep track of which positions have been visited.
  std::vector<std::vector<bool> > visited(labyrinth.size(),
                                          std::vector<bool>(labyrinth[0].size(), false));

  // Create a map to store the nodes by position.
  std::unordered_map<Position, Node*> nodes;

  // Create the starting node and add it to the queue.
  Node* startNode = new Node({start, 0, nullptr});
  q.push(startNode);
  visited[start.first][start.second] = true;
  nodes[start] = startNode;

  // While the queue is not empty, continue searching.
  while (!q.empty()) {
  // Get the next node from the queue.
  Node node = q.front();
  q.pop();

  // If this node is the end node, return the number of steps taken.
  if (node.pos == end) {
  return node.steps;
  }

  // Add the unvisited neighbors of this node to the queue.
  for (int y = -1; y <= 1; y++) {
  for (int x = -1; x <= 1; x++) {
  // Skip the current position.
  if (y == 0 && x == 0) continue;
    // Calculate the position of the neighbor.
  int ny = node.pos.first + y;
  int nx = node.pos.second + x;

  // Make sure the neighbor is within the bounds of the labyrinth.
  if (ny < 0 || ny >= labyrinth.size() || nx < 0 || nx >= labyrinth[0].size()) continue;

  // Make sure the neighbor is not a wall.
  if (labyrinth[ny][nx] == '#') continue;

  // Make sure the neighbor has not been visited before.
  if (visited[ny][nx]) continue;

  // Add the neighbor to the queue
  q.push({{ny, nx}, node.steps + 1});
  visited[ny][nx] = true;
}
}
}

// If the end node was not reached, return -1 to indicate that no path was found.
return -1;
}

int main() {
  // Initialize the labyrinth as a 2D vector of characters.
  std::vector<std::vector<char> > labyrinth = {
    {'S', '#', '.', '.', '.', '.', '.', '.', '.', 'E'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '.', '#', '#', '#', '#', '#', '.', '#'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '.', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '#', '#', '#', '#', '#', '#', '.'}
  };
  Position start = {0, 0};
Position end = {9, 9};
int steps = findShortestPath(labyrinth, start, end);

  return 0;
}
