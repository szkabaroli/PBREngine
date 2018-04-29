#include "OBJImporter.h"

OBJImporter::OBJImporter()
{

}


void OBJImporter::Import(string fileName)
{
	attrib_t attrib;
	vector<shape_t> shapes;
	vector<material_t>materials;

	string base_dir = ".";
	string err;

	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, fileName.c_str(), base_dir.c_str());
	
	if (!err.empty()) {
		printf(err.c_str());
	}

	if (!ret)
		throw runtime_error("Failed to load file: " + fileName);

	printf("# of vertices  = %d\n", (int)(attrib.vertices.size()) / 3);
	printf("# of normals   = %d\n", (int)(attrib.normals.size()) / 3);
	printf("# of texcoords = %d\n", (int)(attrib.texcoords.size()) / 2);
	printf("# of materials = %d\n", (int)materials.size());
	printf("# of indices    = %d\n", (int)shapes[0].mesh.indices.size());
}

OBJImporter::~OBJImporter()
{
}
