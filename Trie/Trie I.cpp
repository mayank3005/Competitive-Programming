class Node{
    Node *links[26];
    bool flag=false;
public:
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL); 
    }
    
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
    
};

class Trie {
    Node *root;
public:
    Trie() {
        root=new Node();    
    }
    
    void insert(string word) {
        Node *node=root;
        for(auto i:word){
            if(!node->containsKey(i)){
                node->put(i,new Node());
            }
            node=node->get(i);     
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node=root;
        for(auto i:word){
            if(!node->containsKey(i)) return false;
            node=node->get(i);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(auto i:prefix){
            if(!node->containsKey(i)) return false;
            node=node->get(i);
        }
        return true;     
    }
};
