/* Author: Oleg Zaikin, ISDCT SB RAS, Irkutsk */

#ifndef base_ls_h
#define base_ls_h

#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <algorithm>

#include "point.h"

const double DEFAULT_TIME_LIMIT = 3600;
const unsigned MAX_SOLVING_VARS = 32;

using namespace std;

class base_local_search
{
public:
	base_local_search();
	vector<unsigned> vars;
	vector<point> checked_points;
	unsigned skipped_points_count;
	unsigned interrupted_points_count;
	point global_record_point;
	string cnf_name;
	string pcs_name;
	string graph_file_name;
	fstream graph_file;
	string estimation_script_name;
	string solver_name;
	string solver_script_name;
	int cpu_cores;
	double time_limit;
	chrono::high_resolution_clock::time_point start_t;

	int getCpuCores();
	string getCmdOutput(const char* cmd);
	double timeFromStart();
	bool isTimeExceeded();

	void init();
	void loadVars();
	vector<unsigned> getAllCnfVars(const string filename);
	vector<unsigned> readVarsFromPcs(string pcs_name);
	bool isEstTooLong();
	void writeToGraphFile(const string str);
	string getScriptCommand(const string script_name, const point cur_point);
	void setGraphFileName();
	bool solveInstance();
	void reportFinalEstimation();
	void calculateEstimation(point &cur_point);
	
	inline bool isChecked(const point cur_point) {
		return (find(checked_points.begin(), checked_points.end(), cur_point) != checked_points.end());
	}

	inline void printGlobalRecordPoint() { global_record_point.print(vars); }
};

#endif


