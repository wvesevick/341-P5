template<typename NODETYPE>
Tree<NODETYPE>::~Tree() {
	while (root != NULL)
		deleteNode(root->data);
} // end destructor

template<typename NODETYPE>
TreeNode<NODETYPE> * Tree<NODETYPE>::insertNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
	// If the subtree is empty, then we have found our new nesting place.
	// This is the base case, so let's create the new node.
	if(curr == NULL){ // checks if the node or tree is empty
		curr = new TreeNode<NODETYPE>(value);
		if(root == NULL){
			root = curr;
		}
		cout << "INSERTED " << curr->getData() << endl;
		curr -> color = RED;
		return curr;
	}
	if (value <= curr->data){
		curr->left = insertNodeHelper(curr->left, value);
		curr->left->parent = curr;
	} else{
		curr->right = insertNodeHelper(curr->right, value);
		curr->right->parent = curr;
	}
	return curr;
	//recolor(curr);
} // end insertNodeHelper

template<typename NODETYPE>
TreeNode<NODETYPE> * Tree<NODETYPE>::findNode(const NODETYPE & value) {
	TreeNodePtr curr = root;
	while(curr != NULL) {
		if (value < curr->data) {
			curr = curr->left;
		}
		else if (value > curr->data){
			curr = curr->right;
		}
		else {
			cout << curr->data;
			return curr;
		}
	}
	return curr;
}

template<typename NODETYPE>
void Tree<NODETYPE>::leftRotate(TreeNodePtr x) {
	TreeNodePtr y = x->right;
	x->right = y->left;
	if (y->left != NULL) {
		y->left->parent = x;
	}
	y->parent = x->parent;	
	
	if (x->parent == NULL){
		this->root = y;
	}
	else if (x->parent->left == x){
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

template<typename NODETYPE>
void Tree<NODETYPE>::rightRotate(TreeNodePtr x) {
	TreeNodePtr y = x->left;
	x->left = y->right;
	if (y->right != NULL) {
		y->right->parent = x;
	}
	y->parent = x->parent;	
	
	if (x->parent == NULL){
		this->root = y;
	}
	else if (x->parent->right == x){
		x->parent->right = y;
	}
	else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

template<typename NODETYPE>
void Tree<NODETYPE>::recolor(TreeNodePtr k){
	// CASE 1 -- TREE EMPTY -- WORKS FULLY
	TreeNodePtr u;
	cout << "Recolor called on " << k->getData() << endl;
	if(k == root){
		cout << "CASE 1" << endl;
		k -> color = BLACK;
	}

	// CASE 2 -- P IS BLACK -
	// 
	if(k->color == BLACK){
		cout << "CASE 2" << endl;
		//do nothing
	}

	// CASE 3 STUFF
	while(k->parent != NULL && k->parent->color == RED){
		if(k->parent->parent != NULL && k->parent == k->parent->parent->right){ // g = k->parent->parent
			u = k->parent->parent->left;
			if(u != NULL && u->color == RED){ // CASE 3.1
				cout << "CASE 3.1 TRIGGERED ON " << k->getData() << endl;
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
			} else {
				if(k->parent->left != NULL && k==k->parent->left){ // CASE 3.2.2
				cout << "CASE 3.2.2 TRIGGERED ON " << k->getData() << endl;
				k = k->parent;
				rightRotate(k);
				}
				//CASE 3.2.1
				cout << "CASE 3.2.1 TRIGGERED ON " << k->getData() << endl;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				leftRotate(k->parent->parent);
			}
		} else { // embed all mirror cases
			u = k->parent->parent->right;
			if(u != NULL && u->color == RED){ // CASE 3.1
				cout << "CASE 3.1 TRIGGERED ON " << k->getData() << endl;
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
			
			} else {
				if(k->parent->right != NULL && k==k->parent->right){ // CASE 3.2.4
				cout << "CASE 3.2.2 MIRROR TRIGGERED ON " << k->getData() << endl;
				k = k->parent;
				leftRotate(k);
				}
				//CASE 3.2.3
				cout << "CASE 3.2.1 MIRROR TRIGGERED ON " << k->getData() << endl;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				rightRotate(k->parent->parent);
			}
		}
	} // end of while loop
	root->color = BLACK;
} // end recolor


template<typename NODETYPE>
TreeNode<NODETYPE> * Tree<NODETYPE>::deleteNodeHelper(TreeNodePtr & curr, const NODETYPE & value) {
	// If the subtree is empty, quit
	if (curr == NULL)
		return curr;
	else if (value < curr->data)
		curr->left = deleteNodeHelper(curr->left, value);
	else if (value > curr->data)
		curr->right = deleteNodeHelper(curr->right, value);
	else {
		// We know that curr->data == value, so we're ready to delete
		
		// Let's call the "node to be deleted" . . . . doomed
		// Case 1: (doomed has no children)

		// i dont think this one you have to delete parent
		// you just get rid of it and it should change the other nodes
		if ((curr->left == NULL) && (curr->right == NULL)) {
			delete curr;
			curr = NULL;
		} // end case 1 if
		
		// Case 2: (doomed has one child)
		// this case is handling if it has one right child
		else if (curr->left == NULL) {
			TreeNodePtr temp = curr;
			curr = curr->right;
			curr -> parent = temp -> parent;
			delete temp;
		} // end case 2a if
		else if (curr->right == NULL) {
			TreeNodePtr temp = curr;
			curr = curr->left;
			curr -> parent = temp -> parent;
			delete temp;
		} // end case 2b if
		
		// Case 3: (doomed has two children)
		else {
			// NEED TO ASK ABOUT THIS!!!!
			// Find the smallest element on the right side of the tree.
			TreeNodePtr smallestRight = curr->right;
			while (smallestRight->left != NULL)
				smallestRight = smallestRight->left;
			
            // Notice that you actually only ever delete a node with 0 or 1 child from the tree.
            // Nodes with two children are too big to fail.
			curr->data = smallestRight->data;
			curr->right = deleteNodeHelper(curr->right, smallestRight->data);
		} // end case 3
	} // end outside else

	return curr;
} // end deleteNodeHelper

template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	if(curr->parent == NULL){ // this is root case
		cout << "Root is " << curr -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child: " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	} else if (curr -> left == NULL && curr -> right == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " No Kids";
		cout << " ShatterScore is: " << curr -> data << " " << curr->color << endl;
	} else if (curr -> left == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child is NULL ";
		cout << " Right Child: " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	} else if (curr -> right == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child is NULL ";
		cout << " Color is: " << curr->color << endl;
	} else {
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	}

	preOrderHelper(curr->left);		// traverse the left subtree
	preOrderHelper(curr->right);	// traverse the right subtree
} // end preOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	inOrderHelper(curr->left);		// traverse the left subtree
	if (curr == NULL)
		return;
	if(curr->parent == NULL){ // this is root case
		cout << "Root is " << curr -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child: " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	} else if (curr -> left == NULL && curr -> right == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " No Kids";
		cout << " ShatterScore is: " << curr -> data << " " << curr->color << endl;
	} else if (curr -> left == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child is NULL ";
		cout << " Right Child: " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	} else if (curr -> right == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child is NULL ";
		cout << " Color is: " << curr->color << endl;
	} else {
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	}
	inOrderHelper(curr->right);		// traverse the right subtree
} // end inOrderHelper

template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNodePtr curr) const {
	if (curr == NULL)
		return;
	postOrderHelper(curr->left);	// traverse the left subtree
	postOrderHelper(curr->right);	// traverse the right subtree
	if (curr == NULL)
		return;
	if(curr->parent == NULL){ // this is root case
		cout << "Root is " << curr -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child: " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	} else if (curr -> left == NULL && curr -> right == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " No Kids";
		cout << " ShatterScore is: " << curr -> data << " " << curr->color << endl;
	} else if (curr -> left == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child is NULL ";
		cout << " Right Child: " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	} else if (curr -> right == NULL){
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child is NULL ";
		cout << " Color is: " << curr->color << endl;
	} else {
		cout << "NODE IS: " << curr -> data;
		cout << " Parent is: " << curr -> parent -> data;
		cout << " Left Child: " << curr -> left -> data;
		cout << " Right Child " << curr -> right -> data;
		cout << " Color is: " << curr->color << endl;
	}
} // end postOrderHelper
