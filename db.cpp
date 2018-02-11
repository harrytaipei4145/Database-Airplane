#include <string>
#include <fstream>      
#include <iostream>     
#include "db.h"
#include <vector>  
#include<cstdlib>
using namespace std;

fstream file;
fstream ofile;
string s;
int position;
string filename;

void db::init(){
	//Do your db initialization.
}

void db::setTempFileDir(string dir){
	//All the files that created by your program should be located under this directory.
	filename = dir;
	ofile.open(filename, fstream::out);
}

void db::import(string csvFileName){
	//Inport csv files under this directory.
	
	file.open(csvFileName, fstream::in);
	
	file.seekg(300, ios::beg);
	int j = 0;
	while (!file.eof())
	{
		
		for (int i = 0; i < 15; i++)
		{
			getline(file, s, ',');
		}

		if (s != "NA")
		{
		

			ofile << s<<" ";
			//time.push_back(temp);

			for (int i = 0; i < 13; i++)
			{
				getline(file, s, ',');
				if (i == 1)
				{
					//ori.push_back(s);
					ofile << s << " ";
				}
				else if (i == 2)
				{
					//des.push_back(s);
					ofile << s << " ";
				}
			}
			
		}
		else
		{
			for (int i = 0; i < 13; i++)
			{
				getline(file, s, '\n');
			}
		}
	
	}
	
	file.close();
	
	
}

void db::createIndex(){
	

	ofile.close();
}

double db::query(string origin, string dest){
	//Do the query and return the average ArrDelay of flights from origin to dest.
	//This method will be called multiple times.
	fstream ifile;
	double sum = 0.0, num = 0.0;
	ifile.open(filename, fstream::in);
	string ori, des;
	int delay;
	while (!ifile.eof())
	{
		ifile >> delay;
		ifile>>ori;
		ifile>>des;
		
		
		if (ori != origin)
			continue;
		else
		{
			if (des != dest)
				continue;
			else
			{
				sum =sum+ delay;
				num = num + 1.0;
			}

		}
	}
	ifile.close();
	return sum/num; //Remember to return your result.
}

void db::cleanup(){
	//Release memory, close files and anything you should do to clean up your db class.
}