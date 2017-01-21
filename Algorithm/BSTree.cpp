//
//  BSTree.cpp
//  Algorithm
//
//  Created by Freya Hayashi on 1/20/17.
//  Copyright (c) 2017 Freya Hayashi. All rights reserved.
//

#include "BSTree.h"
#include <iostream>

BSTree::BSTree() {
	root = nullptr;
}

BSTree::~BSTree() {
	
}

BSTree::Node * BSTree::add(int key) {
	Node * h = new Node;
	h->value = key;
	h->right = h->left = nullptr;
	h->grade = 0;
	if(root == nullptr) {
		root = h;
		return root;
	}
	return add(h, root);
}

BSTree::Node * BSTree::add(Node * h, Node * to) {
	Node * head = to;
	while(head != nullptr) {
		if(h->value < head->value) {
			if (head->left == nullptr) {
				head->left = h;
				h->parent = head;
				head = nullptr;
			}
			else head = head->left;
		}
		else {
			if (head->right == nullptr) {
				head->right = h;
				h->parent = head;
				head = nullptr;
			}
			else head = head->right;
		}
	}
	spreadUp(h);
	return h;
}


void BSTree::spreadUp(BSTree::Node * node) {
	if (node == nullptr) return;
	int l = 0, r = 0;
	if (node->left != nullptr) l = node->left->grade + 1;
	if (node->right != nullptr) r = node->right->grade + 1;
	int diff = l - r;
	node->grade = l > r ? l : r;
	if (diff > 1) {
		Node * left = node->left;
		node->left = nullptr;
		left->parent = node->parent;
		if (node->parent == nullptr) {
			root = left;
		}
		else if(node->parent->left == node) {
			node->parent->left = left;
		}
		else {
			node->parent->right = left;
		}
		add(node, root);
	}
	else if (diff < -1) {
		Node * right = node->right;
		node->right = nullptr;
		right->parent = node->parent;
		if (node->parent == nullptr) {
			root = right;
		}
		else if(node->parent->left == node) {
			node->parent->left = right;
		}
		else {
			node->parent->right = right;
		}
		add(node, root);
	}
	else {
		node->grade = l > r ? l : r;
		if(node->parent != nullptr) spreadUp(node->parent);
	}
}

BSTree::Node * BSTree::getRoot() {
	return root;
}

void BSTree::setRoot(BSTree::Node * root) {
	this->root = root;
}

bool BSTree::search(int key) {
	Node * head = root;
	while (head != nullptr) {
		if (head->value == key) return true;
		else if(head->value < key) head = head->right;
		else head = head->left;
	}
	return false;
}