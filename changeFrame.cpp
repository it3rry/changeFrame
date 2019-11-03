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

	while (*_getadd != "Ans:") {
		_getadd++;
	}
	_getadd++;
	string add21 = *_getadd;
	_getadd++;
	string add22 = *_getadd;

	l1.remove("Info");
	ofstream fout;
	fout.open("out.txt");
	list<string>::iterator _str = l1.begin();
	//单帧
	fout << Req << "   "<<  Head << add11 <<" "<< add12<< " ";
	_str++;
	_str++;
	int _supplementary_num = 0;
	while (*_str != "Ans:") {
		fout << *_str++ << " ";
		_supplementary_num++;
	}

	for (int i = 0; i < 7- _supplementary_num; i++) {
		fout << "00" << " ";
	}
	fout << endl;

	l1.remove("Req:");

	//第一帧
	int _start = 21;
	//_str++; _str++;
	fout << Ans << "MN " << Head << add21 << " " << add22 << " ";
	++_str; ++_str; ++_str;
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
	int _rest_comm_num =0;
	//计算还有多少数据没有写入
	list<string>::iterator temp_str = _str;
	while (temp_str != l1.end()) {
		_rest_comm_num++;
		temp_str++;
	}
	
	//最后帧
	while (_str != l1.end()) {
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

