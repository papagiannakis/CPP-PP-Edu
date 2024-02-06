#include <iostream>
#include <fstream>
#include <cmath>

// Define image dimensions and max iterations
const int WIDTH = 800;
const int HEIGHT = 800;
const int MAX_ITER = 100000;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// Function to compute a point halfway between two points
Point midpoint(const Point& p1, const Point& p2) {
    return Point((p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0);
}

int main() {
    std::ofstream image("sierpinski_gasket.ppm");

    // Seed for random number generation and file setup
    srand(time(nullptr));
    image << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

    // Define vertices of the main triangle
    Point vertices[3] = {
        Point(WIDTH / 2, 0), 
        Point(0, HEIGHT), 
        Point(WIDTH, HEIGHT)
    };

    // Start from a random point
    Point current(rand() % WIDTH, rand() % HEIGHT);

    // Plot points on the image
    for (int i = 0; i < MAX_ITER; ++i) {
        int vertexIndex = rand() % 3;
        current = midpoint(current, vertices[vertexIndex]);
        image << "0 0 0\t";  // Plot point
    }

    image.close();
    std::cout << "Sierpinski gasket image generated";
    return 0;
}