#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;	// Ryan ** hi
#include "tree.h"
#include "licorice.h"
#include "treenode.h"

//Type git add *.cpp *.h *.txt *.inl makefile and hit enter.
//Type git commit -m "finished phase(s) X"
//Type git push origin master and hit enter.

/*
QUESTIONS FOR GUPTA
ASK IF CASE 2 NEEDS RETURN STATEMENT
CASE 3.2.2 WORKS ONLY IF NEXT PART COMMENTED OUT
NEED TO GO BACK AND DO DELETE STUFF WITH PARENTS
*/

int main() {
	/*
	Tree<int> intTree;
	int insertVal[10] = {50, 25, 75, 12, 33, 67, 88, 6, 13, 68};
	
	for (int x = 0; x < 10; x++){
		intTree.insertNode(insertVal[x]);
	}
	*/

	ifstream myFile;
	myFile.open("licorBabies.txt");

	
	Tree<LicorIce> myTree;
	LicorIce babies[23];
	LicorIce newBaby;
	
	//reads in Name then Weapon then Shatter score
	// insert into the tree based on  shatter score
	for(int x = 0; x < 23; x++){
		string variableName;
		int variableInt;
		myFile >> variableName;
		newBaby.setName(variableName);
		myFile >> variableInt;
		newBaby.setWeapon(variableInt);
		myFile >> variableInt;
		newBaby.setShatter(variableInt);
		babies[x] = newBaby;
		myTree.insertNode(newBaby);
	}


	//TESTING 3.1 WORKS ON EXAMPLE
	/*
	myTree.findNode(babies[0])->color = BLACK;
	myTree.findNode(babies[1])->color = BLACK;
	myTree.findNode(babies[2])->color = BLACK;
	myTree.findNode(babies[3])->color = RED;
	myTree.findNode(babies[4])->color = RED;
	myTree.findNode(babies[5])->color = RED;
	myTree.recolor(myTree.findNode(babies[5]));
	*/

	//TESTING 3.2.2 WORKS ON EXAMPLE
	/*
	myTree.findNode(babies[0])->color = BLACK;
	myTree.findNode(babies[1])->color = BLACK;
	myTree.findNode(babies[2])->color = BLACK;
	myTree.findNode(babies[3])->color = RED;
	myTree.findNode(babies[4])->color = RED;
	myTree.recolor(myTree.findNode(babies[4]));
	*/
	
	//TESTING 3.2.1 WORKS ON EXAMPLE
	/*
	myTree.findNode(babies[0])->color = BLACK;
	myTree.findNode(babies[1])->color = BLACK;
	myTree.findNode(babies[2])->color = BLACK;
	myTree.findNode(babies[3])->color = RED;
	myTree.findNode(babies[4])->color = RED;
	myTree.recolor(myTree.findNode(babies[4]));
	*/

	/*
	myTree.recolor(myTree.findNode(babies[0]));
	myTree.recolor(myTree.findNode(babies[1]));
	myTree.recolor(myTree.findNode(babies[2]));
	myTree.recolor(myTree.findNode(babies[3]));
	myTree.recolor(myTree.findNode(babies[4]));
	myTree.recolor(myTree.findNode(babies[5]));
	*/
	
	

	cout << "EVERYTHING DONE " << endl;
	cout << "Preorder: " << endl;
	myTree.preOrder();


	/*
	cout << "Rotated Tree" << endl << "************" << endl;
	cout << "Preorder: ";
	myTree.preOrder();
	*/
	/*
	cout << "Inorder: ";
	intTree.inOrder();
	cout << endl;
	
	cout << "Postorder: ";
	intTree.postOrder();
	cout << endl;
	
	intTree.deleteNode(50);
	cout << "Preorder: ";
	intTree.preOrder();
	cout << endl;
	cout << "Inorder: ";
	intTree.inOrder();
	cout << endl;
	
	cout << "Postorder: ";
	intTree.postOrder();
	cout << endl;
	*/
	
	return 0;
}
