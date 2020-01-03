#include <iostream>
#include <string>

class Point2D
{
public:
	Point2D();
	Point2D(int x, int y);
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
	void Display();

private:
	int mX;
	int mY;
};

Point2D::Point2D()
{
	mX = 0;
	mY = 0;
}

Point2D::Point2D(int x, int y)
{
	mX = x;
	mY = y;
}

void Point2D::SetX(int x)
{
	mX = x;
}

void Point2D::SetY(int y)
{
	mX = y;
}

int Point2D::GetX()
{
	return mX;
}

int Point2D::GetY()
{
	return mY;
}

void Point2D::Display()
{
	std::cout << "X: " << mX << ", Y: " << mY << std::endl;
}

int main()
{
	Point2D myPoint(5, 10); 
	//Point2D myPoint = Point2D(7, 12);
	//Point2D myPoint = { 9, 20 };
	myPoint.Display();

	system("pause");
}