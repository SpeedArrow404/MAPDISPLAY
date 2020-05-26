#pragma once
#ifndef _JSON_NODE_
#define _JSON_NODE_
#include "Include.h"
#include "CommonFunctions.h"

class JsonNode {
public:
	char* name;
	char* value;
	vector<JsonNode*> Nodes;
	JsonNode();

	JsonNode& operator[] (const char* arg);
	JsonNode& operator[] (const unsigned int arg);
	JsonNode& operator= (const char* arg);
};

#endif // !_JSON_NODE_

