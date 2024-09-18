#include <iostream>
#include <vector>

int main() {
  // Create an empty vector of integers.
  std::vector<int> v1;

  // Create a vector of 10 integers, all initialized to 0.
  std::vector<int> v2(10);

  // Create a vector of 5 integers, all initialized to 10.
  std::vector<int> v3(5, 10);

  // Create a vector from an array of integers.
  int a[] = {1, 2, 3, 4, 5};
  std::vector<int> v4(a, a + 5);

  // Print the contents of the vectors.
  std::cout << "v1: ";
  for (int x : v1) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::cout << "v2: ";
  for (int x : v2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::cout << "v3: ";
  for (int x : v3) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::cout << "v4: ";
  for (int x : v4) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
