#include <iostream>
#include <string>

using namespace std;

class Shape {
  public:
    virtual Shape* clone() const = 0; // Clone method for creating copies.
    virtual void draw() const = 0;   // Draw method for rendering the shape.
    virtual ~Shape() {}              // Virtual destructor for proper cleanup.
};

class Circle : public Shape {
  private:
    double radius;

  public:
    Circle(double r) : radius(r) {}

    Shape *clone() const override {
      return new Circle(*this);
    }

    void draw() const override {
      cout << "Drawing a circle with radius " << radius << endl;
    }
};

class Rectangle : public Shape {
  private:
    double width;
    double height;

  public:
    Rectangle(double w, double h) : width(w), height(h) {}

    Shape *clone() const override {
      return new Rectangle(*this);
    }

    void draw() const override {
      cout << "Drawing a rectangle with width " << width << " and height " << height << endl;
    }
};

int main() {
  Circle circlePrototype(5.0);
  Rectangle rectanglePrototype(4.0, 6.0);

  Shape* shape1 = circlePrototype.clone();
  Shape* shape2 = rectanglePrototype.clone();

  shape1->draw(); // Output: Drawing a circle with radius 5
  shape2->draw(); // Output: Drawing a rectangle with width 4 and height 6
}