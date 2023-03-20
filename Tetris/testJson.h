#ifndef TESTJSON_H
#define TESTJSON_H

#include "nlohmann/json.hpp"
using json = nlohmann::json;
class TestJson
{
private:
	json data;
public:
	void testWrite();

};

#endif // !TESTJSON_H

