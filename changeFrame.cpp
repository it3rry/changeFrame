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
	int _num = 0;
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
	int _sing_frame_num = 4;
	for (int i = 0; i < _sing_frame_num; i++) {
		_str++;
	}
	
	//单帧
	//fout << Req << "  "<<  Head << add11 << add12;
	for (int i = 0; i < _num; i++) {
		fout << *_str << endl;;
	}
	
	fout << Head << "   " << add11 << add12;
	while (*_str == "Info") {
		fout << *_str;
		_str++;
	}
	//单帧补齐
	fout << endl;
	
	//第一帧
	int _start = 21;
	fout << Ans << "MN " << Head << add21 << add22
		<< "总数" << *_str++;
	//控制帧
	fout << Req << "1N" << Head << add11 << add12
		<< "30 ";
	int _Control_Num = 6;
	for (int i = 0; i < _Control_Num; i++) {
		fout << "00 ";
	}
	fout << endl;
	//最后一行的帧命令
	//检测还有多少没录入命令
	int _rest_comm_num = 0;
	while (_str == l1.end()) {
		_rest_comm_num++;
		_str++;
	}
	int _Consecutive_num_rest = 0;
	while (_str != l1.end()) {
		if (_rest_comm_num < 7) {
			fout << Ans << "1N" << Head << add11 << add12;
			for (int i = 0; i < _Consecutive_num_rest; i++) {
				fout << *_str;
				_str++;
			}
			fout << endl;
			_rest_comm_num = _rest_comm_num - 7;
		}
		else {
			fout << Ans << "1N" << Head << add11 << add12;
			int _last_comm_num = 7 - _rest_comm_num;
			for (int i = 0; i < _rest_comm_num; i++) {
				fout << *_str;
				_str++;
			}
			for (int i = 0; i < _last_comm_num; i++) {
				fout << "00 ";
			}
			fout << endl;

		}
	}
	
	cout << "执行完毕\n";
}

