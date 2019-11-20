#include <iostream>
using namespace  std;


//------------------��child�ࡿ-----------------------------------
class Child             //1.����С���ѽڵ���
{
public:
	int childNo;         //��ǰС���ı��
	Child* leftchild;    //��¼С����������ھ�
	Child* rightchild;   //��¼С����������ھ�

public:

	Child(int id = 0) 	  //���캯��
	{
		childNo = id;
		leftchild = NULL;
		rightchild = NULL;
	}
};
//-------------------��Circle�ࡿ----------------------------------

class Circle               // ����ԲȦ��Ϸ��
{
public:
	int scale;             //��ǰ-���ڲ�����Ϸ������
	Child children[21];  //���-������Ϸ��С������

public:
	Circle(int num = 0) // ��Ĭ��ֵ���캯������ʼ��С���ڵ�
	{
		scale = num;


		for (int i = 0; i < num; i++)
		{
			children[i] = Child(i);      //Child(i)�ǹ��캯��
		}
	};

	//�����ڵ��ѭ����������ȷ��ÿ��С���������ھ�
	void Build()
	{
		for (int i = 0; i < scale; i++)
		{
			if (i == 0)
			{
				children[i].leftchild = &children[scale - 1];
				children[i].rightchild = &children[i + 1];
			}
			else if (i == scale - 1)
			{
				children[i].rightchild = &children[0];
				children[i].leftchild = &children[i - 1];
			}
			else
			{
				children[i].rightchild = &children[i + 1];
				children[i].leftchild = &children[i - 1];
			}

		}

	}
	//��Ϸ���к������ӵ�ǰ�ڵ�˳ʱ��ѭ����ʼ��num����
	void Run(int T)
	{
		int k;
		cout << "�ӵڼ���С����ʼ��Ϸ����������(k<109)��" << endl;
		cout << "--------------------------------------------" << endl;
		cin >> k;
		cout << "--------------------------------------------" << endl;
		int count = 1;
		Child* current = &children[k - 1];
		Child* temp = NULL;
		while (scale > 1)
		{
			//Quit the circle��С���˳���ǰԲȦ
			if (count == T )
			{
					temp = current->rightchild;
					current->leftchild->rightchild = current->rightchild;
					current->rightchild->leftchild = current->leftchild;
					current->leftchild = NULL;
					current->rightchild = NULL;
					cout << "No." << current->childNo+1 << "  is out" << endl;
					scale--;
					current = temp;
					count = 1;
			
			}
			else  //Count the next������������Ϸ	            		
			{
				count++;
				current = current->rightchild;			
			}
		}
		cout << "--------------------------------------------" << endl;
		cout << "The last child id is " << current->childNo << endl;
	}
};


//----------------------------������----------------------------------

int main()
{
	Circle nodes(21); // ԲȦ������21���ڵ����С����

	nodes.Build();

	nodes.Run(7);      // ��ʼѭ����������7������Ϸ��������������߱��

	system("pause");

	return 0;
}