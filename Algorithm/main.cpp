//
//  main.cpp
//  Algorithm
//
//  Created by Freya Hayashi on 1/20/17.
//  Copyright (c) 2017 Freya Hayashi. All rights reserved.
//

#include <iostream>
#include <vector>
#include "BSTree.h"

int main(int argc, const char * argv[]) {
	std::vector<BSTree::Node*> v;
	BSTree tree;
	while(1) {
		int value;
		std::cin >> value;
		v.push_back(tree.add(value));
		printf("%d\n", tree.getRoot()->value);
	}
	return 0;
}
