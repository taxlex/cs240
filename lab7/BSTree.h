#ifndef BSTREE_H
#define BSTREE_H

#include <vector>

using namespace std;
class BSTree{
	friend class Node;
	public:
		BSTree();
		BSTree(const BSTree &old_tree);
		~BSTree();
		bool empty();
		bool insert(int val);
		bool find(int val);
		void sortedArray(vector<int> &list);
		bool remove(int num);
		void printBST();
	private:
		class Node{
			friend class BSTree;
			public:
				Node(Node * aParent);
				int data;
				bool hasVal;
	
			private:
				Node * leftSubTree;
				Node * rightSubTree;
				Node * parent;
				bool insert(Node * currNode, int val);
				bool find(Node * currNode, int val);
				void copyPreOrder(Node * to, Node * from);
				void deleteTreePostOrder(Node * currNode);
				void sortedArrayInOrder(vector<int> &list, Node * currNode);
				void removePreOrder(Node * currNode, int num);
				Node * minVal();
				Node * maxVal();
				void printNode(Node * currNode, int level);
	
		};
		Node * root;
};



#endif
