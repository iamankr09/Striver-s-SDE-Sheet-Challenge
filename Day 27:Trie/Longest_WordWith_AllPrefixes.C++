#include <bits/stdc++.h> 
class TrieNode{
   public:
   TrieNode*children[26];
   bool flag;
   TrieNode(){
       flag = false;
       for(int i = 0 ; i < 26 ; i++){
           children[i] = NULL;
       }
   }  

   bool isContainKey(char ch){
       return children[ch-'a'] != NULL; 
   }

   void put(char ch , TrieNode*node){
       children[ch-'a'] = node;
    }

   TrieNode*get(char ch){
       return children[ch-'a'];
   }
   
   void setEnd(){
       flag = true;
   }

   bool isEnd(){
       return flag;
   }
};
class Trie{
     private:
     TrieNode*root;
     public:
     Trie(){
         root = new TrieNode();
     }  

     void Insert(string &word){
         TrieNode*node = root;
         for(int i = 0 ; i < word.length() ; i++){
             if(!node->isContainKey(word[i])){
                 node->put(word[i], new TrieNode());
             }

             // move to the Next reference
             node = node->get(word[i]);
         }
         node->setEnd();
     }

     bool Search(string &word){
         TrieNode*node =root;
         for(int i = 0 ; i < word.length() ; i++){
             if(!node->isContainKey(word[i])){
                 return false;
             }

             node = node->get(word[i]);
         }
         return node->isEnd() == true;
     }

     bool checkIfPrefixExist(string &word){
          TrieNode*node = root;
          for(int i = 0 ; i < word.length() ; i++){
              if(!node->isContainKey(word[i])){
                  return false;
              }
              else{
                  node = node->get(word[i]);
                   if(node->isEnd() == false) return false;
              }
              
          }

          return true;
          
     }
};
string completeString(int n, vector<string> &a){
      Trie trie;
       for(auto &it : a){
           trie.Insert(it);
       }
       string longest = "";
       for(auto &it : a){
           if(trie.checkIfPrefixExist(it)){
               if(it.length() > longest.length()){
                   longest = it;
               }
               else if(it.length() == longest.length() && it < longest){
                   longest = it;
               }
           }
       }


       if(longest == "") return "None";
       return longest;
}
