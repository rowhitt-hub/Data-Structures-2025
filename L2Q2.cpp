/*
Write a C++ menu-driven program that calculates and displays the area of a square, cube, rectangle, and cuboid.
Consider length as the side value for the square and cuboid. Identify proper data members and member functions.
Design and create an appropriate class for the given scenario. Maintain proper boundary conditions and follow
coding best practices.
The menus are as follows,
a) Square
b) Cube
c) Rectangle
d) Cuboid
e) Exit
*/
#include <iostream>
using namespace std;

class ShapeCalculator {
private:
    double length, breadth, height;

public:
    void calculateSquareArea() {
        cout << "Enter side of the square: ";
        cin >> length;
        cout << "Area of the square: " << (length * length) << endl;
    }

    void calculateCubeSurfaceArea() {
        cout << "Enter side of the cube: ";
        cin >> length;
        cout << "Surface area of the cube: " << (6 * length * length) << endl;
    }

    void calculateRectangleArea() {
        cout << "Enter length and breadth of the rectangle: ";
        cin >> length >> breadth;
        cout << "Area of the rectangle: " << (length * breadth) << endl;
    }

    void calculateCuboidSurfaceArea() {
        cout << "Enter length, breadth, and height of the cuboid: ";
        cin >> length >> breadth >> height;
        double surfaceArea = 2 * (length * breadth + breadth * height + height * length);
        cout << "Surface area of the cuboid: " << surfaceArea << endl;
    }
};

int main() {
    ShapeCalculator calculator;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "a) Square\n";
        cout << "b) Cube\n";
        cout << "c) Rectangle\n";
        cout << "d) Cuboid\n";
        cout << "e) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        choice = tolower(choice);

        switch (choice) {
            case 'a':
                calculator.calculateSquareArea();
                break;
            case 'b':
                calculator.calculateCubeSurfaceArea();
                break;
            case 'c':
                calculator.calculateRectangleArea();
                break;
            case 'd':
                calculator.calculateCuboidSurfaceArea();
                break;
            case 'e':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 'e');

    return 0;
}
