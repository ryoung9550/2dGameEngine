#include "GeObj.hpp"
#include <vector>
#include <cstdlib>
#include <cstdio>

GeObj::GeObj() 
{
	srand(time(0));
	constexpr unsigned maxSize = ((sizeof(unsigned) * 8) << 1u) - 1;
	unsigned tempID;
	while (true) {
		tempID = rand() % maxSize;
		if (objList.find(tempID) == objList.end()) {
			this->id = tempID;
			objList.insert(std::pair<unsigned, GeObj*>(id, this));
			break;
		}
	}
}

GeObj::~GeObj()
{
	objList.erase(id);
}

std::map<unsigned, GeObj*>& GeObj::getIdList()
{
	return objList;
}
