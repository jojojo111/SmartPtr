#include"RefCount.h"
#include"SmartPtr.h"

int main()
{
	SmartPtr<Sample> p = new Sample;
	SmartPtr<Sample> p2 = new Sample;

	p = p2;

	p->doSomething();
	(*p).doSomething();


	return 0;
}