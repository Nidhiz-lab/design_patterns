#include <fstream>
#include "persistance_manager.hpp"

void PersistanceManager::save(const journal& j, const string& filename)
{
	ofstream ofs(filename);
	for (auto& e : j.entries)
	{
		ofs << e << endl;
	}
}