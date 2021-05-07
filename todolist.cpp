#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
//应该创建的是倒序链表：last
struct node {
	int d;//难度级别
	int num;//任务编号
	node *last = NULL;
};
struct list {
	node *first = NULL;
	node *tail = NULL;
};
void record(list &dairy, int value, int num) {
	node* newone = new node;
	newone->last = dairy.first;
	newone->d = value;
	newone->num = num;
	dairy.first = newone;
}
void deletenode(node*& temp) {
	node* clear = temp->last;
	temp->last = clear->last;
	free(clear);
}
void update(list& dairy, vector<int> target) {
	node* temp = dairy.first;
	for (int i = 0; i < 4; i++) {
		int flag = target[i] - target[i + 1];
		while (--flag)	temp = temp->last;
		deletenode(temp);
	}
	temp = dairy.first->last;
	free(dairy.first);
	dairy.first = temp;
}
void check(list &dairy) {
	int i;
	vector<int> target;
	vector<int> output;
	vector<int> clear1;
	vector<int> clear2;
	node *temp = dairy.first;
	while (temp != dairy.tail && target.size() < 5) {
		for (i = 0; i < target.size(); i++) {
			if (target[i] == temp->d) break;
		}
		if (i == target.size()) {
			target.push_back(temp->d);
			output.push_back(temp->num);
		}
		temp = temp->last;
	}
	if (target.size() == 5) {
		for (i = 4; i >= 0; i--) cout << output[i] << " ";
		cout << endl;
		update(dairy, output);
		clear1.swap(target);
		clear2.swap(output);
		return;
	}
	else cout << "-1" << endl;
}
int main() {
	int n, temp, num = 1;//任务数量 任务编号
	list dairy;
	dairy.tail = new node;//头指针
	dairy.first = dairy.tail;//尾指针
	cin >> n;
	while(num <= n) {
		cin >> temp;
		record(dairy, temp, num);
		check(dairy);
		num++;
	}
	return 0;
}