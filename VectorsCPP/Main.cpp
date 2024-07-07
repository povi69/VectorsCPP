#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector v;
	for (int i = 0; i < 22; i++)
	{
		v.PushBack(i);
		cout << v << endl;
	}
	return 0;
}