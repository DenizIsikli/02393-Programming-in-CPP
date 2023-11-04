#include <iostream>
#include <vector>
#include <cmath>
#include "shapes.h"

using namespace std;

int main(){
    vector<Shape *> shapes;

    Rectangle u(2,5);
    shapes.push_back(&u);
    Square v(3);
    shapes.push_back(&v);
    Circle w(2);
    shapes.push_back(&w);

    // Enumerating all areas
    cout << "Areas..." << endl;
    double area = 0;

    for(auto &shape : shapes){
        cout << round(shape->area()) << " ";
        area += shape->area();
    }
    cout << endl << "Total area is " << round(area) << endl;

    // Enumerating all areas
    cout << "Perimeters..." << endl;
    double perimeter = 0;
    for(auto &shape : shapes){
        cout << round(shape->perimeter()) << " ";
        perimeter += shape->perimeter();
    }
    cout << endl << "Total area is " << round(perimeter) << endl;

    // I want to put them side-by-side
    // And see how much space they use (width and height)
    cout << "Placing side-by-side..." << endl;
    double width = 0;
    double height = 0;
    for(auto &shape : shapes){
        width += shape->width();
        if(height < shape->height()){
            height = shape->height();
        }
    }
    cout << "Total width is " << round(width) << endl;
    cout << "Total height is " << round(height) << endl;

    // I now try to do the same, but minimizing width
    // First, I rotate those shapes that need it
    for(auto &shape : shapes){
        if(shape->width() > shape->height()) {
            shape->rotate();
        }
    }
    // Then I proceed as before
    cout << "Placing side-by-side..." << endl;
    width = 0;
    height = 0;
    for(auto &shape : shapes){
        width += shape->width();
        if(height < shape->height()){
            height = shape->height();
        }
    }

    cout << "Total width is " << round(width) << endl;
    cout << "Total height is " << round(height) << endl;

    return 0;
}
