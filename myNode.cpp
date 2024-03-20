#include"myNode.h"
using namespace std;


myNode::myNode(){
	
}

myNode::myNode(my2Dpoints _pointer, int _dimension) 
	:pointer(_pointer), Dimension(_dimension) {};

myNode::~myNode() {
	delete left;
	delete right;
}

void myNode::setpointer(my2Dpoints _pointer) {
	pointer.setpointer1(_pointer.getpointer1());
}

my2Dpoints myNode::getpointer() const {
	return pointer;
}

void myNode::setDimension(int dim) {
	Dimension = dim;
}

int myNode::getDimension() const {
	return Dimension;
}

void myNode::setleft(myNode* _left) {
	left = _left;
}

myNode* myNode::getleft() const {
	return left;
}

void myNode::setright(myNode* _right) {
	right = _right;
}

myNode* myNode::getright() const {
	return right;
}


void myNode::setpointdistance(double _dis) {
	pointer.settargetdistance(_dis);
}