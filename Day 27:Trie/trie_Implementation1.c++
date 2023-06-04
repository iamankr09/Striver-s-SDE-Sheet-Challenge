/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:
    TrieNode*children[26];
    bool isTerminal;
    TrieNode(){
        isTerminal = false;
        for(int i = 0; i < 26 ; i++){
             children[i] = NULL;
        }
    }
};
class Trie {
 private:
   TrieNode*root;
public:

    /** Initialize your data structure here. */
    Trie() {
       root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void InsertWord(TrieNode*root , string word){
         if(word.length() == 0){
             root->isTerminal = true;
             return;
         }

         /* smallCalculation --> if first character present in Trie , call for remaining
            string to insert and if not present , create a new trienode and insert it in trie
            and call further to insert remaining string */

         int index = word[0]-'a';
         TrieNode*child;
         if(root->children[index] != NULL){
             child = root->children[index];
         }
         else{
             TrieNode*newTrieNode = new TrieNode();
             root->children[index] = newTrieNode;
             child = root->children[index];
         }

         // Recursive Cal1
         InsertWord(child , word.substr(1));

    }

    bool SearchWord(TrieNode*root , string word){
         if(word.length() == 0){
             if(root->isTerminal) return true;
             return false;
         }

         // SmallCalculation
         int index = word[0]-'a';
         TrieNode*child;
         if(root->children[index] != NULL){
             child = root->children[index];
         }
         else{
             return false;
         }


         // recursive call
         return SearchWord(child , word.substr(1));
    }

    bool StartWiths(TrieNode*root , string word){
          if(word.length() == 0){
              return true;
          }

          // Small Calculation
          int index = word[0]-'a';
          TrieNode*child;
          if(root->children[index] != NULL){
              child = root->children[index];
          }
          else{
              return false;
          }

          // Recursive Call
          return StartWiths(child , word.substr(1));
    }
    void insert(string word) {
          InsertWord(root , word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      return SearchWord(root , word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return StartWiths(root , prefix);
    }
};
