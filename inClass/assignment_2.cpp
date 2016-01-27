//
//  Assignment #2
//
//  Created by Bernin A. Uben on 1/26/16.
//  Copyright © 2016 Bernin A. Uben. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

class Circle {
public:
    Circle(double);
    double getRadius();
    void setRadius(double);
    double getArea();
    double getCircumference();
private:
    double radius;
    double PI = 3.14;
};

int main() {
    double radius;
    string answer = "yes";
    
    while(answer == "yes"){
        cout << "\nWhats the radius of the circle?:";
        cin >> radius;
        
        Circle one(radius);
        cout << "\nUser entered " << one.getRadius() << " as Radius\n";
        cout << "Area: " << one.getArea() << endl;
        cout << "Circumference: " << one.getCircumference() << endl;
        
        cout << "\nAnother one?('yes' or 'no'): ";
        cin >> answer;
        
        if(answer != "yes"){
            break;
        }
    }
    return 0;
}

Circle::Circle(double mainRadius){
    radius = mainRadius;
}

void Circle::setRadius(double mainRadius){
    radius = mainRadius;
}

double Circle::getRadius(){
    return radius;
}

double Circle::getArea(){
    return PI * radius * radius;
}

double Circle::getCircumference(){
    return PI * (2 * radius);
}
