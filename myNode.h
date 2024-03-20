#pragma once
#ifndef MYNODE_H
#define MYNODE_H
#include"my2Dpoints.h"
class myNode{
public:
	myNode();
	myNode(my2Dpoints, int);
	~myNode();
	void setpointer(my2Dpoints _pointer);
	my2Dpoints getpointer()const;
	void setDimension(int);
	int getDimension()const;
	void setleft(myNode* _left);
	myNode* getleft()const;
	void setright(myNode* _right);
	myNode* getright()const;
	void setpointdistance(double);

private:
	my2Dpoints pointer;
	int Dimension;
	myNode* left = nullptr;
	myNode* right = nullptr;


};







#endif // !MYNODE_H
