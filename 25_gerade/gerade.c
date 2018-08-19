#include <stdio.h>

struct Point
{
	double x_value;
	double y_value;
} point1, point2;

//call by value 
/*
double gradient(struct Point p1, struct Point p2)
{
	return (p2.y_value - p1.y_value) / (p2.x_value - p1.x_value);
} 
*/

//call by reference
double gradient(struct Point *p1, struct Point *p2)
{
	return ((*p2).y_value - (*p1).y_value) / ((*p2).x_value - (*p1).x_value);
}

void main()
{
	point1.x_value = 2;
	point1.y_value = 1;
	point2.x_value = 5;
	point2.y_value = 6;

	double m = gradient(&point1, &point2);
	double c = (point1.y_value) - (m * point1.x_value);

	printf("Point 1: ( %0.2f | %0.2f )\n", point1.x_value, point1.y_value);
	printf("Point 2: ( %0.2f | %0.2f )\n", point2.x_value, point2.y_value);
	printf("Gradient (m): %0.2f\n", m);
	printf("Y-Intercept (c): %0.2f\n", c);
	system("pause");
}

