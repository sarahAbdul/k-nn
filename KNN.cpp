#include <iostream>
#include <string>
#include <vector>

#include "instance.h"
#include "neighbor.h"
#include "Action.h"
#include "FileReader.h"
#include "category.h"

using namespace std;
static  string PATH_TO_DATA_FILE = "coupious.data";
static  int NUM_ATTRS = 9;
static  int K = 262;

static  int CATEGORY_INDEX = 0;
static  int DISTANCE_INDEX = 1;
static  int EXPIRATION_INDEX = 2;
static  int HANDSET_INDEX = 3;
static  int OFFER_INDEX = 4;
  int WSACTION_INDEX = 5;
static  int NUM_RUNS = 1000;
static double averageDistance = 0;

int main()
{

    vector<Instance>* instances;
    vector<Neighbor> distances;
    vector<Neighbor> neighbors;
    WSAction classification;//.Action
    Instance classificationInstance;

    int numRuns = 0, truePositives = 0, falsePositives = 0, falseNegatives = 0, trueNegatives = 0;
    double precision = 0, recall = 0, fMeasure = 0;

    falsePositives = 1;
    FileReader reader(PATH_TO_DATA_FILE);
    instances = reader.buildInstances(NUM_ATTRS);
    cout <<"love hope determination success";
    return 0;
}

