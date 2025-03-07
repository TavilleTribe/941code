#include <iostream>
#define MaxSize 100

//作业二

using namespace std;
typedef char ElemType;
typedef struct SqList {
	ElemType datas[MaxSize];
	int length;
}SqList;

void InitList(SqList *&e) {
	e = new SqList;
	e->length = 0;
}

int GetLen(SqList *e) {
	return e->length;
}

int IndexOf(ElemType s,SqList *e) {
	for (int i = 0;i < e->length;i++) {
		if (s == e->datas[i]) {
			return i+1; 
		}
	}
	return -1;
//	int left = 0;
//	int right = e->length;
//	int mid = left + (left+right) >> 1 % (e->length+1);
//	while (left < right) {
//		if ()
//	} 
}

bool InsertList(SqList *&e,int index,ElemType s) {
	if (index < 1||index > e->length+1||index >= MaxSize) {
		return false;
	}
	index--;
	e->length++;
	for (int j = e->length;j > index;j--) {
		e->datas[j] = e->datas[j-1];
	}
	e->datas[index] = s;
	return true;
}

bool IsEmpty(SqList *e) {
	return !e->length;
}

bool GetElem(ElemType &value,SqList *e,int index) {
	if (index < 1||index > e->length||index > MaxSize) {
		return false;
	}
	index--;
	value = e->datas[index];
	return true;
}

bool DeleteElem(SqList *&e,int index) {
	if (index < 1||index > e->length||index >MaxSize) {
		return false;
	}
	index--;
	for (int j = index;j < e->length;j++) {
		e->datas[j] = e->datas[j+1];
	}
	e->length--;
	return true;
}

void DestroyList(SqList *&e) {
	delete e;
}

void DispList(SqList *e) {
	for (int i = 0;i < e->length;i++) {
		cout<<e->datas[i]<<" ";
	}
}



int main() {
	ElemType datas[5] = {'A','B','C','D','E'};
	
	ElemType temp; 
	SqList *e;
	InitList(e);
	
	for (int i = 0;i < 5;i++) {
		InsertList(e,i+1,datas[i]);
	}
	
	DispList(e);
	cout<<endl;
	cout<<GetLen(e)<<endl;
	cout<<"是否为空: "<<IsEmpty(e)<<endl;
	cout<<"第3个元素: "<<GetElem(temp,e,3)<<endl;
	cout<<"元素A的位置为: "<<IndexOf('A',e)<<endl<<endl;
	
	InsertList(e,4,'f');
	cout<<"插入后"<<endl; 
	DispList(e);
	cout<<endl;
	
	DeleteElem(e,3);
	cout<<"删除后"<<endl;
	DispList(e);
	cout<<endl;
	
	DestroyList(e); 
}
