//  ****************** TLE ***********************
#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    
    TrieNode(char ch)
    {
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    public:
    TrieNode* root; 
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }
    
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
            root->childCount++;
            root->children[index] = child;
        }

        // recrsion
        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    
    void lcp(string str, string &ans)
    {
        for(int i=0; i<str.length(); i++)
        {
            char ch = str[i];
            
            if(root->childCount == 1)
            {
                ans.push_back(ch);
//                 aage badho 
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            
            if(root->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie('\0');
    
//     insert all the strings into the trie
    for(int i=0; i<n; i++)
    {
        t->insertWord(arr[i]);
    }
    
    string first = arr[0];
    string ans = "";
    
    t->lcp(first, ans);
    return ans;
}


