// changeFrame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	list<string> l1;
	string s1;
	
	
	ifstream fin;
	fin.open("in.txt");
	
	while (fin.eof()) {
		if (fin) {
			fin >> s1;
			l1.push_back(s1);
		}

	}
	//统计第一行有几个命令


	l1.remove("Info");
	l1.remove("Req:");
	l1.remove("Ans:");


	
	ofstream fout;
	fout.open("out.txt");
	
	//单帧

	//第一帧

	//连续帧
	
	//最后一行的帧命令

	
	cout << "执行完毕\n";
}

