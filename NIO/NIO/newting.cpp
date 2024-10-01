#include <queue>
#include <vector>
#include <iostream>

// Define a pair of integers to represent a position in the labyrinth.
typedef std::pair<int, int> Position;

// Define a structure to represent a node in the search tree.
struct Node {
  Position pos;   // The position of the node in the labyrinth.
  int steps;      // The number of steps taken to reach this node.
};

// Define a function to perform the breadth-first search.
int findShortestPath(const std::vector<std::vector<char> >& labyrinth,
                     const Position& start,
                     const Position& end) {
  // Create a queue to hold the nodes that need to be explored.
  std::queue<Node> q;

  // Create a 2D vector to keep track of which positions have been visited.
  std::vector<std::vector<bool> > visited(labyrinth.size(),
                                          std::vector<bool>(labyrinth[0].size(), false));

  // Add the starting node to the queue.
  q.push({start, 0});
  visited[start.first][start.second] = true;

  // While the queue is not empty, continue searching.
  while (!q.empty()) {

    // Get the next node from the queue.
    Node node = q.front();
    q.pop();
     std::cout << "Node position: (" << node.pos.first << ", " << node.pos.second << ")" << std::endl;
  std::cout << "Number of steps taken: " << node.steps << std::endl;

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

int main(){
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
};

/*{'S',         '#', '(0, 1)', '(0, 2)', '(0, 3)', '(0, 4)', '(0, 5)', '(0, 6)', '(0, 7)', 'E'},
{'(1, 0)',      '#', '(1, 2)', '(1, 3)', '(1, 4)', '(1, 5)', '(1, 6)', '(1, 7)', '(1, 8)', '(1, 9)'},
{'(2, 0)',      '#', '(2, 2)', '(2, 3)', '(2, 4)', '(2, 5)', '(2, 6)', '(2, 7)',      '#', '(2, 9)'},
{'(3, 0)',      '#',      '#',      '#',      '#',      '#',       '#',     '#',      '#', '(3, 9)'},
{'(4, 0)',      '#', '(4, 2)', '(4, 3)', '(4, 4)', '(4, 5)', '(4, 6)', '(4, 7)', '(4, 8)', '(4, 9)'},
{'(5, 0)',      '#', '(5, 2)',      '#',      '#',      '#',      '#',      '#', '(5, 8)',      '#'},
{'(6, 0)',      '#', '(6, 2)', '(6, 3)', '(6, 4)', '(6, 5)', '(6, 6)', '(6, 7)', '(6, 8)', '(6, 9)'},
{'(7, 0)',      '#',      '#',      '#',      '#',      '#',      '#', '(7, 7)',      '#',      '#'},
{'(8, 0)', '(8, 1)', '(8, 2)', '(8, 3)', '(8, 4)', '(8, 5)', '(8, 6)', '(8, 7)',      '#', '(8, 9)'},
};

*/


  int steps = findShortestPath(labyrinth, {0, 0}, {0, 3});

  std::cout << "Shortest path has " << steps << " steps." << std::endl;
  return 0;


}

