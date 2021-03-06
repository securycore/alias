/* Author: Oleg Zaikin, ISDCT SB RAS, Irkutsk */

#include <iostream>

#include "igbfs.h"

int main(int argc, char *argv[])
{
	if (argc < 5) {
		cerr << "Usage: -cnf cnf_name -script script_name -pcs pcs_name -solver solver_name -time time_limit" << endl;
		exit(-1);
	}

	string cnf_name = "";
	string pcs_name = "";
	string solver_name = "";
	string alias_script_name = "";
	double time_limit = 0;
	int cpu_cores = 0;
	
	for (int i = 1; i < argc; i++) {
		string par_str = argv[i];
		if ((par_str == "-cnf") && (i+1 < argc))
			cnf_name = argv[i+1];
		else if ((par_str == "-pcs") && (i+1 < argc))
			pcs_name = argv[i+1];
		else if ((par_str == "-script") && (i + 1 < argc))
			alias_script_name = argv[i + 1];
		else if ((par_str == "-solver") && (i+1 < argc))
			solver_name = argv[i + 1];
		else if ((par_str == "-time") && (i+1 < argc))
			time_limit = atof(argv[i+1]);
	}
	
	cout << "cnf_name " << cnf_name << endl;
	cout << "pcs_name " << pcs_name << endl;
	cout << "solver_name " << solver_name << endl;
	cout << "alias_script_name " << alias_script_name << endl;
	cout << "wall_time_limit " << time_limit << endl;

	igbfs igbfs_obj;
	igbfs_obj.cnf_name = cnf_name;
	igbfs_obj.pcs_name = pcs_name;
	igbfs_obj.solver_name = solver_name;
	igbfs_obj.alias_script_name = alias_script_name;
	igbfs_obj.time_limit = time_limit;
	
	igbfs_obj.init();
	igbfs_obj.iteratedGBFS();
	igbfs_obj.solveInstance();

	cout << "*** final total time " << igbfs_obj.timeFromStart() << endl;
	
	return 0;
}