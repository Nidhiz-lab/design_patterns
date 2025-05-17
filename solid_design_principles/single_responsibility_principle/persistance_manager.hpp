#pragma once
#include "journal_single_responsibility_principle.hpp"
using namespace std;

class PersistanceManager {
public:
	PersistanceManager() {}

	void save(const journal& j, const string& filename);
};