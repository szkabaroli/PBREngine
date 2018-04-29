#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

using namespace tinyobj;
using namespace std;

class OBJImporter
{
public:
	OBJImporter();
	~OBJImporter();
	void Import(string fileName);
};

