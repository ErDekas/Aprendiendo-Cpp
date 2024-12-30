#include <iostream>

using namespace std;

class Vector2D {
public:
    float x, y;

    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

    // Overload + operator to add two Vector2D objects
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Overload - operator to subtract two Vector2D objects
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // Overload * operator to multiply vector by a scalar
    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // Overload * operator to perform dot product of two vectors
    float operator*(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // Function to display vector
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;
    Vector2D v5 = v1 * 2.0;
    float dotProduct = v1 * v2;

    cout << "v1: "; v1.display();
    cout << "v2: "; v2.display();
    cout << "v1 + v2: "; v3.display();
    cout << "v1 - v2: "; v4.display();
    cout << "v1 * 2: "; v5.display();
    cout << "v1 * v2 (producto escalar): " << dotProduct << endl;

    return 0;
}