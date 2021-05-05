#pragma once
#include "Vector.h"
#include "VectorHori.h"
#include "VectorVert.h"

class VectorHori;
class VectorVert;

class Fabric{
public:
	virtual Vector* Create() = 0;
};

class FabricHori : public Fabric {
public:
	virtual Vector* Create() override{ 
		return new VectorHori; 
	}
};

class FabricVert : public Fabric {
public:
	virtual Vector* Create() override{ 
		return new VectorVert; 
	}
};

Vector* create(string str, map<string, Fabric*> factory) {
	auto search = factory.find(str);
	if (search == factory.end()) {
		std::cout << "Not found\n";
		throw - 1;
	}
	return factory[str]->Create();
}
