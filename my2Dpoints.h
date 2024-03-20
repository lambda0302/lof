#include<iostream>
#include<vector>

#ifndef my2Dpoints_H
#define my2Dpoints_H



class my2Dpoints{
public:
	my2Dpoints();
	my2Dpoints(double,double);
	~my2Dpoints();
	void setpointer1(const double);
	double getpointer1()const;
	void setpointer2(const double);
	double getpointer2()const;
	void settargetdistance(double);
	double gettargetdistance()const;
	void setk_distance(double);
	double getk_distance()const;
	void setKnn(std::vector<my2Dpoints>);			
	std::vector<my2Dpoints> getKnn();
	void setlrd(double);															
	double getlrd()const;
	void setlof(double);
	double getlof()const;
	void setknn(my2Dpoints*);
	my2Dpoints* getknn()const;
	void setnumOfKnn(int);
	int getnumOfKnn()const;
	bool operator<(const my2Dpoints& p)const;



private:
	std::vector<double> pointer;
	double targetdistance;
	double k_distance;
	std::vector<my2Dpoints> Knn;
	my2Dpoints* knn;
	int numOfKnn;
	double lrd;
	double lof;

};



#endif // !my2Dpoints
















