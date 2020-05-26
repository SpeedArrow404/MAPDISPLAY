#include "JsonNode.h"

JsonNode::JsonNode() {
	this->name = nullptr;
	this->value = nullptr;
}

JsonNode& JsonNode::operator= (const char* arg) {
	if (this->Nodes.size() > 0)
		return *this;
	if (arg == nullptr) {
		this->value = new char[1];
		this->value[0] = '\0';
	}
	else {
		this->value = CopyString(arg);
	}
	return *this;
}

JsonNode& JsonNode::operator[] (const char* arg) {
	if (arg == nullptr || this->value != nullptr)
		return *this;

	for (int i = 0; i < this->Nodes.size(); i++)
	{
		if (StringCompare(this->Nodes[i]->name, arg))
			return *(this->Nodes[i]);
	}

	JsonNode* newNode = new JsonNode();
	newNode->name = CopyString(arg);
	this->Nodes.push_back(newNode);
	return *newNode;

}

JsonNode& JsonNode::operator[] (const unsigned int arg) {
	if (arg < this->Nodes.size())
		return *Nodes[arg];
	else if (arg - this->Nodes.size() <= 1) {
		JsonNode* newNode = new JsonNode();
		this->Nodes.push_back(newNode);
		return *newNode;
	}
	else
		return *this;
}