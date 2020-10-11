#include <time.h>
#include <iostream>
using namespace std;
class Date
{
private:
	int year, month, day;

public:
	Date(int y, int m, int d)
	{ //���캯��1 ���в����Ĺ��캯��
		cout << "���캯��1" << endl;
		year = y;
		month = m;
		day = d;
	}
	Date()
	{ //���캯��2����ǰ����  ���������Ĺ��캯��
		cout << "���캯��2" << endl;
		time_t ltime = time(NULL);	   //ȡ�õ�ǰʱ��
		tm *today = localtime(&ltime); //ת��Ϊ����ʱ��
		year = today->tm_year + 1900;  //ȡ�õ�ǰ���
		month = today->tm_mon + 1;	   //ȡ�õ�ǰ�·�,0-11
		day = today->tm_mday;		   //ȡ�õ�ǰ��,1-31
	}
	void print()
	{
		cout << year << "." << month << "." << day << endl;
	}
};
int main()
{
	Date date(2020, 7, 29);
	date.print();

	cout << endl;

	Date date_test;
	date_test.print();

	Date dates[4] = {Date(2000, 10, 7),
					 Date(2012, 11, 2),
					 Date(2013, 12, 8)}; //����4��Date����
	cout << endl;
	dates[3].print();
	dates[3] = Date(2014, 12, 13); //�Ե�4��Ԫ�������¶���

	for (int i = 0; i < 4; i++)
	{
		dates[i].print();
	}
	system("pause");
}
