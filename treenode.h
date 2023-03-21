#ifndef TREENODE_H
#define TREENODE_H

#include "licorice.h"

// forward declaration of a class Tree
template<typename NODETYPE> class Tree;

enum Color {BLACK = 0, RED};

template<typename NODETYPE>
class TreeNode {
	friend class Tree<NODETYPE>;

	private:
		TreeNode<NODETYPE> * left;
		TreeNode<NODETYPE> * right;
        TreeNode<NODETYPE> * parent;
		NODETYPE data;
		
	public:
		// Class setup

		TreeNode(const NODETYPE & d) : left(NULL), right(NULL), data(d), color(RED) {}
		Color color;
		// Access function
		NODETYPE getData() const {return data;}
		//ADDED THIS
		NODETYPE getColor() {return color;}
		NODETYPE setColor(Color newColor) {color = newColor;}
		//do we need get parent

		
}; // end class TreeNode

#endif
