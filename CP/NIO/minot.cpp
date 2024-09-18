#include <iostream>
#include <algorithm>

struct Point {
    int x, y;
};

struct Rectangle {
    Point a, b;
    int width() const { return std::abs(a.x - b.x); }
    int height() const { return std::abs(a.y - b.y); }
};

Rectangle read_rectangle() {
    Rectangle r;
    std::cin >> r.a.x >> r.a.y >> r.b.x >> r.b.y;
    return r;
}

int overlap(const Rectangle& r1, const Rectangle& r2) {
    int x_overlap = std::max(0, std::min(r1.b.x, r2.b.x) - std::max(r1.a.x, r2.a.x));
    int y_overlap = std::max(0, std::min(r1.b.y, r2.b.y) - std::max(r1.a.y, r2.a.y));
    return 2 * (x_overlap + y_overlap);
}

int main() {
    Rectangle r1 = read_rectangle();
    Rectangle r2 = read_rectangle();
    int total_circumference = 2 * (r1.width() + r1.height() + r2.width() + r2.height());
    int total_overlap = overlap(r1, r2);
    std::cout << total_circumference - total_overlap << std::endl;
    return 0;
}