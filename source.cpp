#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include <fstream>
using namespace std;

queue<vector<int> > open;
queue<vector<int> > close;

void check(vector<int> current,int n)
{
    int s=current.size();
    int flag=1;
    int cRow=s+1;
    int pRow,pCol,cCol;
    for(cCol=1;cCol<=n;cCol++){
        flag=1;
        for(int j=0;j<s;j++){
                pRow=j+1;
                pCol=current[j];
                if(cCol==pCol)
                {
                        flag=0;
                        break;
                }
                if(abs(cCol-pCol)==abs(cRow-pRow)){
                        flag=0;
                        break;
                }
        }
        if(flag!=0)
        {
            vector<int> newNode=current;
            newNode.push_back(cCol);
            open.push(newNode);
        }
    }
}

void show(vector<int> current,int k,int n)
{
	int flag;
    ofstream out("result.txt",ios::app);//文件输入
    if (out.is_open())
    {
        out<<"This is No."<<k<<" result: "<<endl;
        for(int i=0;i<n;i++)
    	{
        	flag=current[i]-1;
        	for(int j=0;j<n;j++)
        	{
           		if(j!=flag)
           		{
                	out<<"0 ";
           		}
            	else
            	{
                	out<<"1 ";
            	}
        	}
        	out<<endl;
    	}
    }
}

int main()
{
	int k=1;
	int n;
	cout<<"How many queens?"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		vector<int> a;
        a.push_back(i);
		open.push(a);
	}
	ofstream out("result.txt");
	if (out.is_open())
    {
        out<<" ";
        out.close();
    }
	while(!open.empty())
	{
		vector<int> current=open.front();
		open.pop();
		if(current.size()==n)
		{
			show(current,k,n);
			//print(current,k);
			k++;
			continue;
		}
		close.push(current);
		check(current,n);
	}
}
