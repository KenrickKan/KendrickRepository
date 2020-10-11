#include <iostream>
using namespace std;
class Point
{
	static int defx, defy; //ȱʡ����
	static int pcount;	   //�������
private:
	int x, y;

public:
	Point()
	{ //ȱʡ���캯��
		x = defx;
		y = defy; //�þ�̬���ݳ�Ա����ʼ��
		pcount++; //���������1
	}
	Point(int a, int b)
	{
		x = a;
		y = b;
		pcount++; //���������1
	}
	Point(Point &p)
	{ //�������캯��
		x = p.x;
		y = p.y;
		pcount++;
	}
	~Point()
	{
		pcount--;
	} //��������
	static void setDef(int x, int y)
	{ //��̬��Ա�����ı�ȱʡ����
		defx = x;
		defy = y;
	}
	static int getCount()
	{
		return pcount;
	} //��̬��Ա����
	void show()
	{
		cout << "x= " << x << " y= " << y;
	}
};
int Point::defx; //ȱʡ��ʼ��Ϊ0
int Point::defy = 2;
int Point::pcount = 0;
int main()
{

	Point p1;
	p1.show();
	cout << endl;

	Point::setDef(11, 22);
	Point *p2 = new Point();
	cout << Point::getCount() << " points existing." << endl;
	p2->show();

	cout << endl;
	delete p2;
	cout << Point::getCount() << " points existing." << endl;

	Point p3(33, 44);
	cout << Point::getCount() << " points existing." << endl;
	p3.show();
}
