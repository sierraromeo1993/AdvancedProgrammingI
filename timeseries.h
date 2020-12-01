#ifndef TIMESERIES_H_
#define TIMESERIES_H_
#include <vector>
#include <string>

using namespace std;

class TimeSeries{


	
	vector<vector<string>> masterDataObj;

	const char* csvFile;

	



public:

	TimeSeries(const char* CSVfileName);

	vector<vector<string>> parsebyObj();

	void parsebyFeature();


};



#endif /* TIMESERIES_H_ */