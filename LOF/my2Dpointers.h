#include<iostream>
#include<vector>

#ifndef MY2DPOINTERS_H
#define MY2DPOINTERS_H



class my2Dpointers{
public:
	my2Dpointers();
	my2Dpointers(double,double);
	~my2Dpointers();
	void setpointer1(const double);
	double getpointer1()const;
	void setpointer2(const double);
	double getpointer2()const;
	void settargetdistance(double);
	double gettargetdistance()const;
	void setk_distance(double);
	double getk_distance()const;
	void setKnn(std::vector<my2Dpointers>);			
	std::vector<my2Dpointers> getKnn();
	void setlrd(double);															
	double getlrd()const;
	void setlof(double);
	double getlof()const;
	void setknn(my2Dpointers*);
	my2Dpointers* getknn()const;
	void setnumOfKnn(int);
	int getnumOfKnn()const;
	bool operator<(const my2Dpointers& p)const;



private:
	std::vector<double> pointer;
	double targetdistance;
	double k_distance;
	std::vector<my2Dpointers> Knn;
	my2Dpointers* knn;
	int numOfKnn;
	double lrd;
	double lof;

};



#endif // !my2Dpointers
















