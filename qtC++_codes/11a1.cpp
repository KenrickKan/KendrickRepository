#include <iostream>
using namespace std;
// ����
class Shape
{
public:
   void setWidth(int w)
   {
      width = w;
   }
   void setHeight(int h)
   {
      height = h;
   }
   int getWidth()
   {
      cout << "jilei" << endl;
      return width;
   }

protected:
   int width;
   int height;
};

// ������
class Rectangle : public Shape
{
public:
   int getWidth()
   {
      cout << "paisheng" << endl;
      //return width;
      return this->Shape::getWidth();
      // return this->getWidth();
      //���������� ��Ա����ʱ
   }
   int getArea()
   {
      return (width * height);
   }
};

int main(void)
{
   Rectangle Rect;

   Rect.setWidth(5);
   Rect.setHeight(7);

   cout << Rect.getWidth() << endl;
   // �����������
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}
