
#include "timeseries.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>




TimeSeries::TimeSeries(const char* CSVfileName){
    csvFile = std::move(CSVfileName);

}

vector<vector<string>> TimeSeries::parsebyObj(){
    

    std::ifstream ip(csvFile);

        string Time; string Alt_Height;string Air_Speed;string Heading;
        
        while(ip.good()){

            getline(ip,Time,',');
            getline(ip,Alt_Height,',');
            getline(ip,Air_Speed,',');
            getline(ip,Heading,'\n');

            int val1 = Time.compare("");
            int val2 = Time.compare("A");
            if(val1== 0 || val2==0){continue;}
            vector<string> infoObj = {Time,Alt_Height,Air_Speed,Heading};
            masterDataObj.push_back(infoObj);   
        } 
        return masterDataObj;
        }

void TimeSeries::parsebyFeature(){
    vector<vector<string>> masterDataFeature;
    

    
};


        
     
    

    








