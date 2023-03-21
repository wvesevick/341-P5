#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "treenode.h"
#include "licorice.h"

template<typename NODETYPE> class Tree {
	private:
		TreeNode<NODETYPE> * root;
		
		typedef TreeNode<NODETYPE> * TreeNodePtr;
	
		// Helper functions
		TreeNodePtr insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value);
		TreeNodePtr deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value);		
		
		void preOrderHelper(TreeNodePtr curr) const;
		void inOrderHelper(TreeNodePtr curr) const;
		void postOrderHelper(TreeNodePtr curr) const;


        /*
        **********
        // Red/Black recoloring helper functions
        void leftRotate(TreeNodePtr x);
        void rightRotate(TreeNodePtr y);
        void recolor(TreeNodePtr k);
        void doubleBlack(TreeNodePtr x);
		**********
        */
        
	public:
		// Class setup
		Tree() { root = NULL; }
		~Tree();
		
		// Core functionality
		void insertNode(const NODETYPE & value) { 
			insertNodeHelper(root, value);
			TreeNodePtr k = findNode(value);
			recolor(k);
		}

		void deleteNode(const NODETYPE & value) { 
			deleteNodeHelper(root, value);
			TreeNodePtr k = findNode(value);
			 }
		void preOrder() const { preOrderHelper(root); }
		void inOrder() const { inOrderHelper(root); }
		void postOrder() const { postOrderHelper(root); }

		TreeNodePtr findNode(const NODETYPE & value);
		TreeNodePtr leftRotateHelper(NODETYPE & value);

		void leftRotate(TreeNodePtr x);
		void rightRotate(TreeNodePtr x);
		void recolor(TreeNodePtr k);
        
}; // end class Tree

#include "tree.inl"

#endif
