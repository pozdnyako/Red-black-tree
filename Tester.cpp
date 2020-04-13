#include "Tester.h"

void testingRBTVsMap() {
	rbt::Tree<int, int> tree;
	std::map<int, int> map;

	std::ofstream foutT("plot/outTree.dat", std::ios::binary);
	std::ofstream foutM("plot/outMap.dat", std::ios::binary);
    
	const int N_OP = 1000000;
	const int n_points = 1000;

	std::vector<Test> tests(N_OP);

	for(int i = 0; i < N_OP; i++) {
		tests[i] = Test(rand(), rand(), rand());
	}

	float tree_insert_time = 0.0f;
	float tree_find_time = 0.0f;
	float tree_remove_time = 0.0f;

	for(int i = 0; i < N_OP; i++) {
		//tree.is_ok();
		//std::cout << "rbt::Tree: " << i << "  " << tests[i].insert << " " << tests[i].remove << "\n\n";

		auto t_start = std::chrono::high_resolution_clock::now();
		tree.insert(tests[i].insert, tests[i].val);
		auto t_end = std::chrono::high_resolution_clock::now();
		tree_insert_time += std::chrono::duration<double, std::micro>(t_end-t_start).count();

		t_start = std::chrono::high_resolution_clock::now();
		int* data = tree.find(tests[i].remove);
		t_end = std::chrono::high_resolution_clock::now();
		tree_find_time += std::chrono::duration<double, std::micro>(t_end-t_start).count();

		if(data != NULL) {
			t_start = std::chrono::high_resolution_clock::now();
			tree.remove(tests[i].remove);
			t_end = std::chrono::high_resolution_clock::now();
			tree_remove_time += std::chrono::duration<double, std::micro>(t_end-t_start).count();

			tree.insert(tests[i].remove, tests[i].remove);
		}
		else {
			tree.insert(tests[i].remove, tests[i].remove);

			t_start = std::chrono::high_resolution_clock::now();
			tree.remove(tests[i].remove);
			t_end = std::chrono::high_resolution_clock::now();
			tree_remove_time += std::chrono::duration<double, std::micro>(t_end-t_start).count();

		}

		if(i % (N_OP/n_points) == 0) {
			foutT << i+1 << "\t" << tree_insert_time/(float)n_points
						 << "\t" << tree_find_time/(float)n_points
					  	 << "\t" << tree_remove_time/(float)n_points << "\n";

			tree_insert_time = 0.0f;
			tree_find_time = 0.0f;
			tree_remove_time = 0.0f;
		}

		if(i % (N_OP/100) == 0)
			std::cout << "rbt::Tree: " << (i+1) /(N_OP/100) << "%" << "\n";
	}

	float map_insert_time = 0.0f;
	float map_find_time = 0.0f;
	float map_remove_time = 0.0f;

	for(int i = 0; i < N_OP; i++) {
		auto t_start = std::chrono::high_resolution_clock::now();
		map.insert({ tests[i].insert, tests[i].val });
		auto t_end = std::chrono::high_resolution_clock::now();
		map_insert_time += std::chrono::duration<double, std::micro>(t_end-t_start).count();

		t_start = std::chrono::high_resolution_clock::now();
		auto data = map.find(tests[i].remove);
		t_end = std::chrono::high_resolution_clock::now();
		map_find_time += std::chrono::duration<double, std::micro>(t_end-t_start).count();

		if(data != map.end()) {
			t_start = std::chrono::high_resolution_clock::now();
			map.erase(tests[i].remove);
			t_end = std::chrono::high_resolution_clock::now();
			map_remove_time += std::chrono::duration<double, std::micro>(t_end-t_start).count();

			map.insert({ tests[i].remove, tests[i].remove } );
		}
		else {
			map.insert({ tests[i].remove, tests[i].remove });

			t_start = std::chrono::high_resolution_clock::now();
			map.erase(tests[i].remove);
			t_end = std::chrono::high_resolution_clock::now();
			map_remove_time += std::chrono::duration<double, std::micro>(t_end-t_start).count();
		}

		if(i % (N_OP/n_points) == 0) {
			foutM << i+1 << "\t" << map_insert_time/(float)n_points
						 << "\t" << map_find_time/(float)n_points
					  	 << "\t" << map_remove_time/(float)n_points << "\n";

			map_insert_time = 0.0f;
			map_find_time = 0.0f;
			map_remove_time = 0.0f;
		}
		if(i % (N_OP/100) == 0)
			std::cout << "std::map: " << (i+1) /(N_OP/100) << "%" << "\n";
	}


	system("gnuplot -p plot/insert.gp");
	//system("gnuplot -p plot/find.gp");
	//system("gnuplot -p plot/remove.gp");
}