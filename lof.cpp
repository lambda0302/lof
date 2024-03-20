#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
//#include<iterator>
#include<cmath>
#include<fstream>
#include<map>
#include<iomanip>
#include"my2Dpoints.h"
#include"myNode.h"


#define Errordistance 0.0001
using namespace std;




//优先队列自定义比较用于大根堆
class prioritycmp1 {
public:
	bool operator()(my2Dpoints p1, my2Dpoints p2) {
		return p1.gettargetdistance() < p2.gettargetdistance();
	}
};

//优先队列自定义比较用于小根堆
class prioritycmp2 {
public:
	bool operator()(my2Dpoints p1, my2Dpoints p2) {
		return p1.gettargetdistance() > p2.gettargetdistance();
	}
};


//全局变量 用于存储近邻的优先队列
priority_queue<my2Dpoints, vector<my2Dpoints>, prioritycmp1> pq;

//全局变量 用于存储pq存储不完的元素，用于实现k距离内有k+1个点的情况
priority_queue<my2Dpoints, vector<my2Dpoints>, prioritycmp2> pqrecord;

//生成树时用sort对维度x排序
bool cmp1(my2Dpoints pointer1, my2Dpoints pointer2) {
	return pointer1.getpointer1() < pointer2.getpointer1();
}
//生成树时用sort对维度y排序
bool cmp2(my2Dpoints pointer1, my2Dpoints pointer2) {
	return pointer1.getpointer2() < pointer2.getpointer2();
}
//反复利用sort对效率有影响，但影响只在生成树的过程中


//生成树
myNode* maketree(vector<my2Dpoints> myPointers, int begin, int end, int dimension = 1) {//begin指向第一个，end指向最后一个
	if (begin > end) {
		return nullptr;
	}
	sort(myPointers.begin() + begin, myPointers.begin() + end + 1, dimension == 1 ? cmp1 : cmp2);
	myNode* tree = new myNode(myPointers[(end - begin) / 2 + begin], dimension);
	//myNode tree(myPointers[(end - begin) / 2 + begin], dimension);//错误，局部变量空间会被收回
	tree->setleft(maketree(myPointers, begin, (end - begin) / 2 + begin - 1, 3 - dimension));
	tree->setright(maketree(myPointers, (end - begin) / 2 + begin + 1, end, 3 - dimension));
	return tree;
}


//读取树
void readtree(myNode* tree) {//输出树，检查
	if (tree == nullptr) {
		return;
	}
	cout << "x:" << tree->getpointer().getpointer1() << "  y:" << tree->getpointer().getpointer2() << endl;
	readtree(tree->getleft());
	readtree(tree->getright());
}


//计算当前点与目标的距离并赋予结点
void compulatedistance(myNode* Root, my2Dpoints P) {
	Root->setpointdistance
	(sqrt((P.getpointer1() - Root->getpointer().getpointer1())*(P.getpointer1() - Root->getpointer().getpointer1())
		+ (P.getpointer2() - Root->getpointer().getpointer2())*(P.getpointer2() - Root->getpointer().getpointer2())));
}


//判断当前点是否应该加入队列
void decideinput(int k, myNode* Root, my2Dpoints P) {
	if (Root->getpointer().getpointer1() == 2 && Root->getpointer().getpointer2() == 0) {
		cout << "决定" << endl;
	}
	if (pq.size() < k) {
		pq.push(Root->getpointer());
	}
	else if (pq.top().gettargetdistance() >= Root->getpointer().gettargetdistance()) {
		pqrecord.push(pq.top());
		pq.pop();
		pq.push(Root->getpointer());
	}
	else if (fabs(pq.top().gettargetdistance() - Root->getpointer().gettargetdistance()) < Errordistance) {
		pqrecord.push(Root->getpointer());
	}

	
}


//查找k近邻
void findKnn(myNode* Root, my2Dpoints P,unsigned int k, int dimension) {
	
	if (Root == nullptr) {
		return;
	}
	if (Root->getpointer().getpointer1() == 2 && Root->getpointer().getpointer2() == 0) {
		cout << "查询到了" << endl;
	}
	if (dimension == 1) {																				//维度x
		if (P.getpointer1() < Root->getpointer().getpointer1()) {						//x向左
			if (Root->getleft()) {
				findKnn(Root->getleft(), P, k, 3 - dimension);			//递归
																		//回溯
				compulatedistance(Root, P);//当前节点与P的欧氏距离
				decideinput(k, Root,P);//判断是否应将当前节点加入队列
				
				if (abs(P.getpointer1() - Root->getpointer().getpointer1()) <= pq.top().gettargetdistance()) {//若与另一区域相交，则到另一子树递归
					findKnn(Root->getright(), P, k, 3 - dimension);
				}
				
			}
			else {														//找到最小区块
				compulatedistance(Root, P);//当前节点与P的欧氏距离
				decideinput(k, Root,P);//判断是否应将当前节点加入队列
				return;
			}
		}
		else {																			//x向右
			if (Root->getright()) {
				findKnn(Root->getright(), P, k, 3 - dimension);			//递归
																		//回溯
				compulatedistance(Root, P);//当前节点与P的欧氏距离
				decideinput(k, Root,P);//判断是否应将当前节点加入队列
					
				if (abs(P.getpointer1() - Root->getpointer().getpointer1()) <= pq.top().gettargetdistance()) {////若与另一区域相交，则到另一子树递归
					findKnn(Root->getleft(), P, k, 3 - dimension);
				}

			}
			else {														//找到最小区块
				compulatedistance(Root, P);//当前节点与P的欧氏距离
				decideinput(k, Root,P);//判断是否应将当前节点加入队列
				return;
			}
		}
	}
	else {																								//维度y
		if (P.getpointer2() < Root->getpointer().getpointer2()) {						//x向左
			if (Root->getleft()) {
				findKnn(Root->getleft(), P, k, 3 - dimension);			//递归
																		//回溯
				compulatedistance(Root, P);//当前节点与P的欧氏距离
				decideinput(k, Root,P);//判断是否应将当前节点加入队列
				if (abs(P.getpointer2() - Root->getpointer().getpointer2()) <= pq.top().gettargetdistance()) {//若与另一区域相交，则到另一子树递归
					findKnn(Root->getright(), P, k, 3 - dimension);
				}
			}
			else {														//找到最小区块
				compulatedistance(Root, P);//当前节点与P的欧氏距离
				decideinput(k, Root,P);//判断是否应将当前节点加入队列
				return;
			}
		}
		else {																			//x向右
			if (Root->getright()) {
				findKnn(Root->getright(), P, k, 3 - dimension);			//递归
																		//回溯
				compulatedistance(Root, P);//当前节点与P的欧氏距离
				decideinput(k, Root,P);//判断是否应将当前节点加入队列
				if (abs(P.getpointer2() - Root->getpointer().getpointer2()) <= pq.top().gettargetdistance()) {//若与另一区域相交，则到另一子树递归
					findKnn(Root->getleft(), P, k, 3 - dimension);
				}

			}
			else {														//找到最小区块
				compulatedistance(Root, P);//当前节点与P的欧氏距离
				decideinput(k, Root,P);//判断是否应将当前节点加入队列
				return;
			}
		}
	}
}

//计算两点间距离
double distance(my2Dpoints p1, my2Dpoints p2) {
	return sqrt((p1.getpointer1() - p2.getpointer1())*(p1.getpointer1() - p2.getpointer1())
		+ (p1.getpointer2() - p2.getpointer2())*(p1.getpointer2() - p2.getpointer2()));
}


int main()
{

	/*
																								//键盘输入点集
	cout << "Please enter the count of the pointers you will input:";
	int size = 0;
	cin >> size;
	vector<my2Dpoints> myP(size);
	cout << "Enter your pointers :";
	double x = 0, y = 0;
	for (int i = 0; i < size; ++i) {
		cin >> x >> y;
		myP[i].setpointer1(x);
		myP[i].setpointer2(y);
		if (i < size - 1) {
			cout << "Next:";
		}
	}
	*/
	

																								//文件输入点集
	cout << "Please enter the count of the points :";
	int size = 0;
	cin >> size;
	vector<my2Dpoints> myP(size);
	fstream inputFile("data.txt", ios::in);
	double x = 0, y = 0;
	for (int i = 0; i < size; ++i) {
		inputFile >> x >> y;
		myP[i].setpointer1(x);
		myP[i].setpointer2(y);
	}
																								//检查点集
	cout << endl << endl;
	sort(myP.begin(), myP.end(), cmp1);
	cout << "check points:" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "x:" << myP[i].getpointer1() << "      y:" << myP[i].getpointer2() << endl;
	}
	cout << endl << endl;



																								//生成kd树
	myNode* myTree = maketree(myP, 0, myP.size() - 1, 1);


	map<my2Dpoints, double> map1;//用于点与k距离
	map<my2Dpoints, double> map2;//用于点与lrd
	map<my2Dpoints, double> map3;//用于点与lof


																								//检查树
	if (myTree == nullptr) {
		cout << "空树，或者出现错误" << endl;
	}


	cout << "Enter K:";
	int k;
	cin >> k;


	vector<my2Dpoints> recKnn;

	double recK_dis = 0;
	for (int i = 0;i<myP.size();++i) {//循环计算每一个点的k距离与k近邻
		findKnn(myTree, myP[i], k + 1, 1);
		recKnn.resize(0);
		recK_dis = 0;

		while (!pqrecord.empty() && fabs(pqrecord.top().gettargetdistance() - pq.top().gettargetdistance())<Errordistance) {
			recKnn.push_back(pqrecord.top());
			pqrecord.pop();
		}
		while (!pqrecord.empty()) {
			pqrecord.pop();
		}
		recK_dis = pq.top().gettargetdistance();
		while (pq.top().gettargetdistance()!=0) {
			recKnn.push_back(pq.top());
			pq.pop();
		}
		while (!pq.empty()) {
			pq.pop();
		}

		myP[i].setKnn(recKnn);
		myP[i].setk_distance(recK_dis);
		map1[myP[i]] = recK_dis;

	}


	cout << "K_nn_num:\n";
	for (auto it = myP.begin(); it!= myP.end(); ++it) {												//检查
		cout << (*it).getKnn().size() << endl;
	}
	cout << endl;
	

	cout << "K_distance:\n";
	for (auto it = myP.begin(); it != myP.end(); ++it) {												//检查
		cout << (*it).getk_distance() << endl;
	}
	cout << endl;


	for (int i = 0; i < myP.size();++i) {																//计算lrd
		double sumreachdis = 0;
		for (int j = 0; j < myP[i].getKnn().size();++j) {
			sumreachdis += max(distance(myP[i], myP[i].getKnn()[j]), map1[myP[i].getKnn()[j]]);
		}
		myP[i].setlrd(1 / (sumreachdis / myP[i].getKnn().size()));
		map2[myP[i]] = 1 / (sumreachdis / myP[i].getKnn().size());
	}


	cout << "lrd:\n";
	for (auto it = myP.begin(); it != myP.end(); ++it) {												//检查lrd
		cout << (*it).getlrd() << endl;
	}
	cout << endl;



	for (int i = 0; i < myP.size(); ++i) {
		double sumofreachden = 0;
		for (int j = 0; j < myP[i].getKnn().size(); ++j) {
			sumofreachden += map2[myP[i].getKnn()[j]];
		}
		myP[i].setlof((sumofreachden / myP[i].getKnn().size()) / myP[i].getlrd());
		map3[myP[i]] = (sumofreachden / myP[i].getKnn().size()) / myP[i].getlrd();

	}

	ofstream outFile("lof.txt", ios::out);


	cout << "lof:\n";
	for (auto it = myP.begin(); it != myP.end(); ++it) {												//检查lof
		outFile << "point:[" << (*it).getpointer1() << "," << (*it).getpointer2() << "]"
			<< right << setw(10) << "lof:" << (*it).getlof() << endl;
		cout << (*it).getlof() << endl;
	}
	
	system("pause");
	return 0;


}

