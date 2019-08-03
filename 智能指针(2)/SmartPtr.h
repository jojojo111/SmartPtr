#pragma once
#include<stdio.h>
#include<memory>
using namespace std;
#define TRACE printf
/*
auto_ptr ����ȨΨһ,����Ȩ��ת�ƣ���������ָ�����׷�������
�ɵ�����ָ�븳����ֻ֮��ָ�����ȡ��������ָ�������Ȩ
ȱ�㣺����Ȩת�ƣ����¾ɵ�����ָ����ǰʧЧ

unique_ptr ����ȨΨһ����ֹ����������ƶ����ⲿ��ֹ����ָ���ָ���ƶ���
ȱ�㣺��Ϊ���ܿ���������ƶ�����˲��ܹ�������

Shared_Ptr  ǿ����ָ��  �����ü��� ��Ӧ�ñ�����ڴ�Ͷ�Ӧ�����ü���
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