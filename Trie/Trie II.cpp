class Node{
	Node *links[26];
	int cntEndWith=0,cntPrefix=0;
public:
	bool containsKey(char ch){
		return links[ch-'a']!=NULL;
	}
	void put(char ch,Node *node){
		links[ch-'a']=node;
	}
	Node* get(char ch){
		return links[ch-'a'];
	}
	void increaseEnd(){
		cntEndWith++;
	}
	void increasePrefix(){
		cntPrefix++;
	}
	void deleteEnd(){
		cntEndWith--;
	}
	void decreasePrefix(){
		cntPrefix--;
	}
	int getEnd(){
		return cntEndWith;
	}
	int getPrefix(){
		return cntPrefix;
	}
};

class Trie{
	Node *root;
    public:
    Trie(){
		root=new Node();
    }

    void insert(string &word){
		Node *node=root;
		for(auto i:word){
			if(!node->containsKey(i))
				node->put(i,new Node());
			node=node->get(i);
			node->increasePrefix();
		}
		node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
		Node *node=root;
		for(auto i:word){
			if(!node->containsKey(i))
				return 0;
			node=node->get(i);
		}
		return node->getEnd();
    }

    int countWordsStartingWith(string &word){
		Node *node=root;
		for(auto i:word){
			if(!node->containsKey(i))
				return 0;
			node=node->get(i);
		}
		return node->getPrefix();
    }

    void erase(string &word){
		Node *node=root;
		for(auto i:word){
			if(!node->containsKey(i))
				return;
			node=node->get(i);
			node->decreasePrefix();
		}
		node->deleteEnd();		
    }
};
