
#include "SimpleAnomalyDetector.h"
#include "anomaly_detection_util.h"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	// TODO Auto-generated constructor stub

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	// TODO Auto-generated destructor stub
}

void SimpleAnomalyDetector::findCoral(const vector<vector<string>>& featureCols){
	
	for (const vector <string> feature:featureCols){
		
		findUniqueFeatureCoral(feature,featureCols);
		
	}
	return;
}

// this your also going to test seperatley and make sure it works properly 

void SimpleAnomalyDetector::findUniqueFeatureCoral(const vector<string>& trgtFeature,const vector<vector<string>>& featureCols){
		
		float currMax = 0;
		string featureId = "";



		for(vector<string> feature:featureCols) {
			if(trgtFeature[0].compare(feature[0])==0){continue;}
			 
			 vector <float> trgtArrHolder = convertToFloats(trgtFeature);
			 vector <float> featureArrHolder = convertToFloats(feature);

			 for(float e:trgtArrHolder){
				 std::cout<<e<<std::endl;
			 }

			 float arrTrgt[trgtArrHolder.size()];
    		 std::copy(trgtArrHolder.begin(), trgtArrHolder.end(), arrTrgt);

			 float arrFeature[featureArrHolder.size()];
    		 std::copy(featureArrHolder.begin(), featureArrHolder.end(), arrFeature);

			 int size = sizeof(arrTrgt)/sizeof(arrTrgt[0]);
			 
			 float currVal =  pearson(arrTrgt,arrFeature,size);
			 //std::cout<<currVal<<std::endl;
			 

			 if(fabs(currVal) > fabs(currMax)){
			 currMax = currVal;
			 featureId = feature[0];
			 }	 
		}

		if(fabs(currMax) > minThresh){
			std::cout<<"very good"<<std::endl;
			// here you return a vector of points push all relevant information
			// once that is done then we take that vector turn it to arrya of points 
			// and then send to Line_reg 
			
			//correlatedFeatures candidate; 
			//candidate.feature1 = trgtFeature[0];
			//candidate.feature2 = featureId;
			//candidate.corrlation = currMax;
			//candidate.lin_reg =  
			//candidate.threshold = minThresh;
		}

		return;

}
// This your going to check by creating your own input 
vector <Point> SimpleAnomalyDetector::vecPoints(const vector<string>& trgtFeature,const vector<vector<string>>& featureCols,const string chosenFeature){
	vector <string> foundFeature;
	vector <Point>  vectorPoints;

	for(vector <string> element:featureCols){
		if(element[0].compare(chosenFeature)==0){
			std::copy(element.begin(), element.end(), std::back_inserter(foundFeature));
		}
	}

	vector <float> trgtArrHolder = convertToFloats(trgtFeature);
	vector <float> featureArrHolder = convertToFloats(foundFeature);
	
	transform(trgtArrHolder.begin(),trgtArrHolder.end(),featureArrHolder.begin(),std::back_inserter(vectorPoints),
	[](float trgt, float feature){return Point(trgt,feature);});

	return vectorPoints;
}



vector <float> SimpleAnomalyDetector::convertToFloats(const vector<string>& feature){
	vector <float> tmp;

	for(int i = 0 ; i < feature.size(); i++) {
		if(i == 0){continue;}
		
		float num_float = std::stof(feature[i]);
		tmp.push_back(num_float);
		
		
	}
	
	return tmp;
}
// your going to do testing from here 
void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){
	//ts.getMasterDataFeatures();
	vector <string> trgt = {"A","1","2","3" };
	vector <string> feature = {"B","1.5","4.24","4.48100"};

	

	vector<vector<string>> featuresToCoral = {trgt,feature};
	findCoral(featuresToCoral);
	return;

	

}


vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
	// TODO Auto-generated destructor stub
}