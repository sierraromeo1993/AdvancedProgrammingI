
#include "timeseries.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>




TimeSeries::TimeSeries(const char* CSVfileName){
    csvFile = std::move(CSVfileName);
    parsebyObj();
    parsebyFeature();

}

 void TimeSeries::parsebyObj() {
    
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
        
        }
        
void TimeSeries::parsebyFeature() {
    vector<string> timeVec = {"A"};
    vector<string> altVec = {"B"};
    vector<string> airVec = {"C"};
    vector<string> headingVec = {"D"};
    for(vector<string> element:masterDataObj){
        timeVec.push_back(element[0]);
        altVec.push_back(element[1]);
        airVec.push_back(element[2]);
        headingVec.push_back(element[3]);
    }
    masterDataFeature = {timeVec,altVec,airVec,headingVec};
 
};


vector<vector<string>> TimeSeries::getMasterDataFeatures() const{
    for(const vector<string>element:masterDataFeature){
        for(string a: element) {
            std::cout<<a<<std::endl;
        }}
    return masterDataFeature;
}

vector<vector<string>> TimeSeries::getMasterDataObj() const{
    return masterDataObj;
}


        
     
    

    








