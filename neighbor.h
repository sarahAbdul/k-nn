#ifndef  NEIGHBOR_H
#define NEIGHBOR_H

class Neighbor {
private:
    Instance instance;
	int distance;

public:
    Neighbor() {
		setInstance(Instance());
		setDistance(0);
	}

	Neighbor(Instance instance, int distance) {
		this->setInstance(instance);
		this->setDistance(distance);
	}

	void setDistance(int distance) {
		this->distance = distance;
	}

    int getDistance() {
		return distance;
	}

	void setInstance(Instance instance) {
		this->instance = instance;
	}

	Instance getInstance() {
		return instance;
	}
};

#endif // NEIGHBOR_H
