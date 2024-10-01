#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

struct Point {
  int x;
  int y;
};

struct Node {
  Point pos;
  int steps;
  Node* prev;
};

Point p1 = {1, 2};
Node n1 = {p1, 3, nullptr};


bool isValidMove(const std::vector<std::vector<char> >& labyrinth, const std::set<Point>& visited, const Point& p) {
  // Check if the point is out of bounds or is a wall.
  if (p.x < 0 || p.x >= labyrinth[0].size() || p.y < 0 || p.y >= labyrinth.size() || labyrinth[p.y][p.x] == '#') {
    return false;
  }
  // Check if the point has already been visited.
  if (visited.find(p) != visited.end()) {
    return false;
  }
  return true;
}


int findShortestPath(const std::vector<std::vector<char> >& labyrinth, const Point& start, const Point& end) {
  std::queue<Node> q;
  std::set<Point> visited;

  // Start with the starting node.
  Node startNode = { start, 0, nullptr };
  q.push(startNode);

  // While the queue is not empty, continue searching.
  while (!q.empty()) {
    Node curr = q.front();
    q.pop();

    // If we have reached the end, return the number of steps taken.
    if (curr.pos == end) {
      // Backtrace the path by following the "prev" pointers.
      std::vector<Point> path;
      path.push_back(end);
      Node* n = &curr;
      while (n->prev != nullptr) {
        n = n->prev;
        path.push_back(n->pos);
      }
      // Reverse the path so that it starts at the start node.
      std::reverse(path.begin(), path.end());

      // Print the path.
      std::cout << "Shortest path: ";
      for (const auto& p : path) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
      }
      std::cout << std::endl;
      return curr.steps;
    }

    // Mark the current position as visited.
    visited.insert(curr.pos);

    // Try moving up.
    Point up = { curr.pos.x, curr.pos.y - 1 };
    if (isValidMove(labyrinth, visited, up)) {
      Node next = { up, curr.steps + 1, &curr };
      q.push(next);
    }

    // Try moving down.
    Point down = { curr.pos.x, curr.pos.y + 1 };
    if (isValidMove(labyrinth, visited, down)) {
      Node next = { down, curr.steps + 1, &curr };
      q.push(next);
    }

    // Try moving left.
    Point left = { curr.pos.x - 1, curr.pos.y };
    if (isValidMove(labyrinth, visited, left)) {
      Node next = { left, curr.steps + 1, &curr };
      q.push(next);
    }

    // Try moving right.
    Point right = { curr.pos.x + 1, curr.pos.y };
if (isValidMove(labyrinth, visited, right)) {
Node next = { right, curr.steps + 1, &curr };
q.push(next);
}
}

// If we get here, it means we have not found a path.
return -1;
}

int main() {
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

  Point start = {0, 0};
  Point end = {0, 3};
  int steps = findShortestPath(labyrinth, start, end);
  std::cout << steps;
  return 0;
}
