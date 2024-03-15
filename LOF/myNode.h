#pragma once
#ifndef MYNODE_H
#define MYNODE_H
#include"my2Dpointers.h"
class myNode{
public:
	myNode();
	myNode(my2Dpointers, int);
	~myNode();
	void setpointer(my2Dpointers _pointer);
	my2Dpointers getpointer()const;
	void setDimension(int);
	int getDimension()const;
	void setleft(myNode* _left);
	myNode* getleft()const;
	void setright(myNode* _right);
	myNode* getright()const;
	void setpointdistance(double);

private:
	my2Dpointers pointer;
	int Dimension;
	myNode* left = nullptr;
	myNode* right = nullptr;


};







#endif // !MYNODE_H
