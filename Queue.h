#pragma once
#include<iostream>
using namespace std;
const int n = 5;

template<typename T>
class Queue
{
private:
	T p[n];
	int head;
	int tail;
	int siz;
public:
	Queue() 
	{ 
		tail = 1;
		head = siz = 0; 
	};
	int size() const 
	{
		return siz;
	};
	bool empty() const
	{
		if (siz == 0) return true;
		else return false;
	};
	void push(const T b)
	{
		p[tail] = b;
		Pos_plus(b);
	};
	void pop()
	{
		if (siz) {
			for (int first = head; first == tail; first++)
			{
				if (first == n) first = 0;
				p[first] = p[first + 1];
				if (tail == n) tail = 0;
				if (head == n) head = 0;
			}
			
			//siz--;
			Pos_minus();
		}
	};
	T& front()
	{
		return p[head];
	};
	T& back()
	{
		return p[tail - 1];
	};
	void Pos_plus(const T b)
	{
		if (tail == n) tail = 0;
		else if (tail == head) {
			siz--;
			if (head == n) head = 0;
			else head++;
		}
		else { tail++; siz++; }
		
	}
	void Pos_minus()
	{
		siz--;
		if (tail == 0) tail = n;
		else tail--;
	}
};



