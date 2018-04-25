#include "complex.h"

int main(void)
{
	Complex c1, c2;			//创建c1和c2两个复数对象
	cin >> c1 >> c2;		//分别输入c1和c2的实部和虚部
	Complex sum = c1 + c2;
	cout << sum << endl;
	Complex div = c1 / c2;
	cout << div << endl;
	if (c1 > c2)
		cout << "max:" << c1 << endl;
	else
		cout << "max:" << c2 << endl;
	system("pause");
	return 0;
}
