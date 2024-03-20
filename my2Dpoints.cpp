#include"my2Dpoints.h"
using namespace std;

my2Dpoints::my2Dpoints() {
	pointer.resize(2);
	pointer[0] = 0;
	pointer[1] = 0;
}
my2Dpoints::my2Dpoints(double x, double y) {
	pointer.push_back(x);
	pointer.push_back(y);
}
my2Dpoints::~my2Dpoints() {}
void my2Dpoints::setpointer1(double x) {
	pointer[0] = x;
}
double my2Dpoints::getpointer1() const{
	return pointer[0];
}
void my2Dpoints::setpointer2(double y) {
	pointer[1] = y;
}
double my2Dpoints::getpointer2() const{
	return pointer[1];
}

void my2Dpoints::settargetdistance(double _tar_dis) {
	targetdistance = _tar_dis;
}

double my2Dpoints::gettargetdistance()const {
	return targetdistance;
}




void my2Dpoints::setk_distance(double _k_dis) {
	k_distance = _k_dis;
}

double my2Dpoints::getk_distance()const {
	return k_distance;
}

void my2Dpoints::setKnn(vector<my2Dpoints> _knn) {
	for (int i = 0; i < _knn.size(); ++i) {
		Knn.push_back(_knn[i]);
	}
	
}

vector<my2Dpoints> my2Dpoints::getKnn() {
	return Knn;
}

void my2Dpoints::setlrd(double _lrd) {
	lrd = _lrd;
}

double my2Dpoints::getlrd()const {
	return lrd;
}

void my2Dpoints::setlof(double _lof) {
	lof = _lof;
}

double my2Dpoints::getlof()const {
	return lof;
}


void my2Dpoints::setknn(my2Dpoints* v_knn) {
	knn = v_knn;
}

my2Dpoints* my2Dpoints::getknn()const {
	return knn;
}


void my2Dpoints::setnumOfKnn(int num) {
	numOfKnn = num;
}

int my2Dpoints::getnumOfKnn()const {
	return numOfKnn;
}

bool my2Dpoints::operator<(const my2Dpoints& p)const {
	return this->getpointer1() < p.getpointer1();
}