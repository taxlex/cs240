#ifndef BSTREE_H
#define BSTREE_H

using namespace std;
class BSTree{
	public:
		BSTree();
		bool empty();
		bool insert(int val);
		bool find(int val);
	private:
		class Node{
			public:
				Node(Node * aParent);
				bool insert(Node * currNode, int val);
				bool find(Node * currNode, int val);
				int data;
				bool hasVal;
	
			private:
				Node * leftSubTree;
				Node * rightSubTree;
				Node * parent;
	
		};
		Node * root;
};



#endif