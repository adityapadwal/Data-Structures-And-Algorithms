#include<iostream>
#include<vector>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode 
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length() == 0)
        {
            // last character ko terminal node banao matlab root ko he terminal banao
            root->isTerminal = true;
            return;
        }

//      word will be in caps
        int index = word[0] - 'a';
        TrieNode* child;

//      present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recrsion
        insertUtil(child, word.substr(1));
    }
    
    void insert(string word) {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode* root, string word)
    {
        // base case 
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

//      present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent 
            return false;
        }

        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixUtil(TrieNode* root, string word)
    {
        // base case 
        if(word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;

//      present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent 
            return false;
        }

        return prefixUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};