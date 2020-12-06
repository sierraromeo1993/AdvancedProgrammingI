#ifndef TIMESERIES_H_
#define TIMESERIES_H_
#include <vector>
#include <string>

using namespace std;

class TimeSeries{


	
	vector<vector<string>> masterDataObj;
	vector<vector<string>> masterDataFeature;

	const char* csvFile;

	



public:

	TimeSeries(const char* CSVfileName);

	void parsebyObj() ;

	void parsebyFeature() ;

	vector<vector<string>> getMasterDataFeatures() const;

	vector<vector<string>> getMasterDataObj() const;




};



#endif /* TIMESERIES_H_ */