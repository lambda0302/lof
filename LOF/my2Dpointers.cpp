#include"my2Dpointers.h"
using namespace std;

my2Dpointers::my2Dpointers() {
	pointer.resize(2);
	pointer[0] = 0;
	pointer[1] = 0;
}
my2Dpointers::my2Dpointers(double x, double y) {
	pointer.push_back(x);
	pointer.push_back(y);
}
my2Dpointers::~my2Dpointers() {}
void my2Dpointers::setpointer1(double x) {
	pointer[0] = x;
}
double my2Dpointers::getpointer1() const{
	return pointer[0];
}
void my2Dpointers::setpointer2(double y) {
	pointer[1] = y;
}
double my2Dpointers::getpointer2() const{
	return pointer[1];
}

void my2Dpointers::settargetdistance(double _tar_dis) {
	targetdistance = _tar_dis;
}

double my2Dpointers::gettargetdistance()const {
	return targetdistance;
}




void my2Dpointers::setk_distance(double _k_dis) {
	k_distance = _k_dis;
}

double my2Dpointers::getk_distance()const {
	return k_distance;
}

void my2Dpointers::setKnn(vector<my2Dpointers> _knn) {
	for (int i = 0; i < _knn.size(); ++i) {
		Knn.push_back(_knn[i]);
	}
	
}

vector<my2Dpointers> my2Dpointers::getKnn() {
	return Knn;
}

void my2Dpointers::setlrd(double _lrd) {
	lrd = _lrd;
}

double my2Dpointers::getlrd()const {
	return lrd;
}

void my2Dpointers::setlof(double _lof) {
	lof = _lof;
}

double my2Dpointers::getlof()const {
	return lof;
}


void my2Dpointers::setknn(my2Dpointers* v_knn) {
	knn = v_knn;
}

my2Dpointers* my2Dpointers::getknn()const {
	return knn;
}


void my2Dpointers::setnumOfKnn(int num) {
	numOfKnn = num;
}

int my2Dpointers::getnumOfKnn()const {
	return numOfKnn;
}

bool my2Dpointers::operator<(const my2Dpointers& p)const {
	return this->getpointer1() < p.getpointer1();
}