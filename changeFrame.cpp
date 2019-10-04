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
	string str;
	
	const string Head = "08 ";
	const string Req = "Req: ";
	const string Ans = "Ans: ";
	//统计第一行有几个命令
	ifstream ftest;
	ftest.open("in.txt");
	int _num;
	while (ftest.eof()) {
		if (ftest) {
			if (str != "Ans:") {
				_num++;
			}
		}
	}
	ftest.clear();
	ftest.close();

	ifstream fin;
	fin.open("in.txt");
	
	while (fin.eof()) {
		if (fin) {
			fin >> str;
			l1.push_back(str);
		}
	}

	//获取源地址和目标地址
	l1.remove("Info");
	l1.remove("Req:");
	l1.remove("Ans:");

	
	ofstream fout;
	fout.open("out.txt");

	list<string>::iterator _str = l1.begin();
	
	//单帧
	//fout << Req << "  "<<  Head << add11 << add12;
	for (int i = 0; i < _num; i++) {
		fout << *_str << endl;;
	}
	//第一帧
	//fout 
		//连续帧
	int _start = 21;
	//fout << 
	//最后一行的帧命令

	
	cout << "执行完毕\n";
}

