#include <iostream>
#include <vector>
#include "AnomalyDetector.h"
#include "SimpleAnomalyDetector.h"
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>

using namespace std;

// this is a simple test to put you on the right track
void generateTrainCSV(float a1,float b1, float a2, float b2){
	ofstream out("trainFile1.csv");
	out<<"A,B,C,D"<<endl;
	Line ac(a1,b1);
	Line bd(a2,b2);
	for(int i=1;i<=100;i++){
		float a=i;
		float b=rand()%40;
		out<<a<<","<<b<<","<<ac.f(a)-0.02+(rand()%40)/100.0f<<","<<bd.f(b)-0.02+(rand()%40)/100.0f<<endl;
	}
	out.close();
}

void generateTestCSV(float a1,float b1, float a2, float b2, int anomaly){
	ofstream out("testFile1.csv");
	out<<"A,B,C,D"<<endl;
	Line ac(a1,b1);
	Line bd(a2,b2);
	for(int i=1;i<=100;i++){
		float a=i;
		float b=rand()%40;
		if(i!=anomaly)
			out<<a<<","<<b<<","<<ac.f(a)-0.02+(rand()%40)/100.0f<<","<<bd.f(b)-0.02+(rand()%40)/100.0f<<endl;
		else
			out<<a<<","<<b<<","<<ac.f(a)+1<<","<<bd.f(b)-0.02+(rand()%40)/100.0f<<endl;
	}
	out.close();
}

void checkCorrelationTrain(correlatedFeatures c,string f1, string f2, float a, float b){
	if(c.feature1==f1){
		if(c.feature2!=f2)
			cout<<"wrong correlated feature of "<<f1<<" (-20)"<<endl;
		else{
			if(c.corrlation<0.99)
				cout<<f1<<"-"<<f2<<" wrong correlation detected (-5)"<<endl;
			if(c.lin_reg.a<a-0.5f || c.lin_reg.a>a+0.5f)
				cout<<f1<<"-"<<f2<<" wrong value of line_reg.a (-5)"<<endl;
			if(c.lin_reg.b<b-0.5f || c.lin_reg.b>b+0.5f)
				cout<<f1<<"-"<<f2<<" wrong value of line_reg.b (-5)"<<endl;
			if(c.threshold>0.3)
				cout<<f1<<"-"<<f2<<" wrong threshold detected (-5)"<<endl;
		}
	}

}

int main(){
	srand (time(NULL));
	float a1=1+rand()%10, b1=-50+rand()%100;
	float a2=1+rand()%20 , b2=-50+rand()%100;


	// test the learned model: (40 points)
	// expected correlations:
	//	A-C: y=a1*x+b1
	//	B-D: y=a2*x+b2

	generateTrainCSV(a1,b1,a2,b2);
	TimeSeries ts("trainFile1.csv");
    ts.parsebyObj();
    
	
	return 0;
}