//
//  BSTree.h
//  Algorithm
//
//  Created by Freya Hayashi on 1/20/17.
//  Copyright (c) 2017 Freya Hayashi. All rights reserved.
//

#ifndef __Algorithm__BSTree__
#define __Algorithm__BSTree__

class BSTree {
public:
	struct Node {
		int value, grade;
		Node * parent;
		Node * left, * right;
	};
	BSTree();
	~BSTree();
	Node * add(int key);
	Node * add(Node * node, Node * dest);
	void spreadUp(Node * node);
	Node * getRoot();
	void setRoot(Node * root);
	bool search(int key);
private:
	Node * root;
};

#endif /* defined(__Algorithm__BSTree__) */
