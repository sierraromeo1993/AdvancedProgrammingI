

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>

struct correlatedFeatures{
	string feature1,feature2;  // names of the correlated features
	float corrlation;
	Line lin_reg;
	float threshold;
};


class SimpleAnomalyDetector:public TimeSeriesAnomalyDetector{
	vector<correlatedFeatures> cf;
	float minThresh = 0.9;

public:
	SimpleAnomalyDetector();
	virtual ~SimpleAnomalyDetector();

	virtual void learnNormal(const TimeSeries& ts);
	virtual vector<AnomalyReport> detect(const TimeSeries& ts);


	void findCoral(const vector<vector<string>>& featureCols);

	void findUniqueFeatureCoral(const vector<string>& trgtFeature,const vector<vector<string>>& featureCols);

    vector <float> convertToFloats(const vector<string>& feature);

	vector <Point> vecPoints(const vector<string>& trgtFeature,const vector<vector<string>>& featureCols,const string chosenFeature);

	vector<correlatedFeatures> getNormalModel(){
		return cf;
	}

};



#endif /* SIMPLEANOMALYDETECTOR_H_ */