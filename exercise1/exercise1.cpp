#include <iostream>
#include <cstring>

using namespace std;

class Rectangle {
	double Areasize;
	int Color;

public:
	friend double getRectangleSize(Rectangle rect);

	Rectangle(double x, double y){
		Areasize = x * y;
	};

	int getColor(){
		return Color;
	};

	void setColor(int clr){
		Color = clr;
	};
};

class Triangle {
	double Areasize;
	int Color;

public:
	friend double getTriangleSize(Triangle trig);

	Triangle(double x, double h){
		Areasize = x * h / 2.0;
	};

	int getColor(){
		return Color;
	};

	void setColor(int clr){
		Color = clr;
	};
};

double getRectangleSize(Rectangle rect){
	return rect.Areasize;
};

double getTriangleSize(Triangle trig){
	return trig.Areasize;
};

void main(){
	int i;
	int reds=0;
	int greens=0;

	Rectangle *rects[10];
	Triangle *trigs[10];

	for(i=0; i<10; i++){
		rects[i] = new Rectangle(rand()%100, rand()%100);
		rects[i]->setColor(int(rand()%2));
		trigs[i] = new Triangle(rand()%100, rand()%100);
		trigs[i]->setColor(int(rand()%2));
	};

	for(i=0; i<10; i++){
		if(rects[i]->getColor() == 0)
			reds++;
		else
			greens++;

		if(trigs[i]->getColor() == 0)
			reds++;
		else
			greens++;
	};

	cout << "Number of red shapes is: " << reds << endl;
	cout << "Number of green shapes is: " << greens;
};