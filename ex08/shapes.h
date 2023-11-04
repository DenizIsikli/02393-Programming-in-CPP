#ifndef shapes_h
#define shapes_h


class Shape {
public:
    virtual double area() const  = 0;
    virtual double perimeter() const = 0;
    virtual double height() const = 0;
    virtual double width() const = 0;
    virtual void rotate() = 0;
};

class Rectangle : public Shape {
private:
    double _height;
    double _width;

public:
    Rectangle(double height, double width);
    double area() const override;
    double perimeter() const override;
    double height() const override;
    double width() const override;
    void rotate() override;
};

class Square : public Shape {
private:
    double _side;

public:
    explicit Square(double side);
    double area() const override;
    double perimeter() const override;
    double height() const override;
    double width() const override;
    void rotate() override;
};

class Circle : public Shape {
private:
    double _radius;

public:
    explicit Circle(double radius);
    double area() const override;
    double perimeter() const override;
    double height() const override;
    double width() const override;
    void rotate() override;
};

#endif // SHAPES_H
