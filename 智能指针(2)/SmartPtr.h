#pragma once
#include<stdio.h>
#include<memory>
using namespace std;
#define TRACE printf
/*
auto_ptr 所有权唯一,所有权的转移，导致智能指针容易发生错误
旧的智能指针赋给新之只能指针对象，取消旧智能指针的所有权
缺点：所有权转移，导致旧的智能指针提前失效

unique_ptr 所有权唯一，禁止拷贝构造和移动，外部禁止智能指针的指向移动：
缺点：因为不能拷贝构造和移动，因此不能共享数据

Shared_Ptr  强智能指针  ，引用计数 ，应该保存堆内存和对应的引用计数
*/
	  

#if 0
template<typename T>
class SmartPtr
{
public:
	SmartPtr(T *p_)
		:p(p_)
	{
		TRACE("constructor SmartPtr\n");
		p->upcount();
	}

	~SmartPtr(void)
	{
		TRACE("destructor SmartPtr\n");
		p->downcount();
	}

	operator T*(void)
	{
		TRANCE("T*(void)\n");
		return p;
	}
	T& operator*(void)
	{
		return *p;
	}
	T* operator->(void)
	{
		//TRANCE("%s,%d\n",__func__,__LINE__)
		return p;
	}
	SmartPtr& operator=(SmartPtr<T> &p_)
	{
		return operator=((T)*p_);
	}

	SmartPtr& operator=(T* p_)
	{
		p_->upcount();
		p->downcount();
		p = p_;
		return *this;
	}
	SmartPtr(const SmartPtr<T> &p_)
	{
		p = p_.p;
		p->upcount();
	}

private:
	T* p;
};

#endif