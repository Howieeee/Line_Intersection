#include<iostream>
#include<algorithm> //max ,min
using namespace std;

/*
	���w����u�q, �P�_��u�O�_�ۥ�
	L1 (AB) , L2 (CD)
*/

struct Point { float x, y; }; 

bool ifInLine(Point &target, Point &p1, Point &p2) { //���]�O AB dot AC 
	// AB = p1.x-p2.x, p1.y-p2.y    AC = target.x - p1.x, target.y-p1.y
	float dot = (p1.x - p2.x)*(target.x - p1.x) + (p1.y - p2.y)*(target.y - p1.y);
	float dis = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));

	if (dot <= dis)
		return true;
	else return false;

}


float crossProduct(Point &A, Point &B, Point &point) { //���]point = C
	// AC = (C.x - A.x, C.y - A.y)  BC = (C.x - B.x , C.y-B.y)

	// return AC cross BC  
	return ((point.x - A.x)*(point.y - B.y) - (point.y - A.y)*(point.x - B.x));
}

bool ifIntersect(Point &A, Point &B, Point &C, Point &D) {
	// �Y�̤j�����I�p�� ���̤p�����I �N��S���ۥ�i��
	 if(max(A.x, B.x) < min(C.x, D.x) ||
		max(A.y, B.y) < min(C.y, D.y) ||
		max(C.x, D.x) < min(A.x, B.x) ||
		max(C.y, D.y) < min(A.y, B.y) ) return false;

	 //�P�_C,D���I�O�_�b L1 ���ⰼ  ��crossProduct (CP)  ���o AB -> C, D ������
	 float CP_c = crossProduct(A, B, C);
	 float CP_d = crossProduct(A, B, D);

	 //�Y CP_c * CP_d < 0 �N���Ө��פ�V���P, C,D�Y�bL1 �ⰼ   L1,L2���ۥ�
	 //�H������ �M�� A,B�O�_�bL2�ⰼ
	 float CP_a = crossProduct(C, D, A);
	 float CP_b = crossProduct(C, D, B);

	 if (CP_c * CP_d < 0 || CP_a * CP_b < 0)
		 return true;

	 //��crossProduct = 0�� 
	 //���] CP_c = 0  �N�� C�P AB�@�u  �o�ɭn�P�_ C�O�_�bAB�u�q�W  ����=0  A dot B = |A||B|
	 if (CP_a == 0)
		 return ifInLine(A, C, D);
	 if (CP_b == 0)
		 return ifInLine(B, C, D);
	 if (CP_c == 0)
		 return ifInLine(C, A, B);
	 if (CP_d == 0)
		 return ifInLine(D, A, B);

	 return false;
}

int main() {

	Point A = {66,-10};
	Point B = {1,0};
	Point C = {66,-10};
	Point D = {120,1220};

	if (ifIntersect(A, B, C, D))
		cout << "L1 intersects L2\n";
	else
		cout << "No\n";

	system("pause");
}