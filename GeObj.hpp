#ifndef _GEOBJ_HPP
#define _GEOBJ_HPP

#include <map>

class GeObj {
protected:
	unsigned id;
	static std::map<unsigned, GeObj*> objList;
public:
	GeObj();
	~GeObj();
	std::map<unsigned, GeObj*>& getIdList();
};

#endif // _GEOBJ_HPP
