#pragma once

#include <chrono>

#include "Tree.h"
#include <ctime>

struct Test {
	Test(int _insert, int _remove, int _val) :
		insert(_insert),
		remove(_remove),
		val(_val) {}

	Test() {}
	
	int insert;
	int remove;

	int val;
};

void testingRBTVsMap();