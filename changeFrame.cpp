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

	ifstream fin;
	fin.open("D:\\git\\changeFrame\\testfile\\in.txt");
	
	while (!fin.eof()) {
		if (fin) {
			fin >> str;
			l1.push_back(str);
		}
	}

	//获取源地址和目标地址
	list<string>::iterator _getadd = l1.begin();
	_getadd++;
	_getadd++;
	string add11 = *_getadd;
	_getadd++;
	string add12 = *_getadd;

	while (*_getadd == "Ans:") {
		_getadd++;
	}
	_getadd++;
	string add21 = *_getadd;
	_getadd++;
	string add22 = *_getadd;

	//处理掉无用的信息
	l1.remove("Info");
	l1.remove("Req:");
	l1.remove("Ans:");
	
	ofstream fout;
	fout.open("out.txt");

	list<string>::iterator _str = l1.begin();

	//单帧
	fout << Req << "   "<<  Head << add11 <<" "<< add12<< " ";
	_str++;
	_str++;
	for (int i = 0; i < 3; i++) {
		fout << *_str++ << " ";
	}

	for (int i = 0; i < 4; i++) {
		fout << "00" << " ";
	}
	
	//单帧补齐
	fout << endl;
	//第一帧
	int _start = 21;
	fout << Ans << "MN " << Head << "07" << " " << "E8" << " ";
	for (int i = 0; i < 7; i++) {
		fout << *_str++ << " ";
	}
	fout << endl;

	//控制帧

	fout << Req << "1N " << Head << add11 << " " << add12 << " "
	<< "30 ";
	int _Control_Num = 6;
	for (int i = 0; i < _Control_Num; i++) {
		fout << "00 ";
	}
	fout << endl;
	list<string>::iterator a = l1.end();
	a--;
	int _rest_comm_num = 9;

	while (_str != a) {
		if (_rest_comm_num < 7) {
			fout << Ans <<"   "<< Head << add11 << " "<< add12<<" ";
			for (int i = 0; i < _rest_comm_num; i++) {
				fout << *_str++<< " ";
			}
			int _Consecutive_num_rest = 7- _rest_comm_num;
			for (int i = 0; i < _Consecutive_num_rest; i++) {
				fout << "00 ";
			}
		}
		else {
			fout << Ans << "1N " << Head << add11<< " " << add12<< " ";
			for (int i = 0; i < 7; i++) {
				fout << *_str++ << " ";
			}
			fout << endl;
			_rest_comm_num = _rest_comm_num - 7;
		}
	}
	fout.close();
}

