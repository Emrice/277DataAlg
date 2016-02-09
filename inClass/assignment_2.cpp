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
  double PI;
  double radius;
  
public:
  Circle(double);
  void setRadius(double);
  double getRadius();
  double getArea();
  double getCircumference();
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
  PI = 3.14;
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
