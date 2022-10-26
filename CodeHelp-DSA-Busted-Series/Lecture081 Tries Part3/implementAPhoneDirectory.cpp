#include<iostream>
#include<vector>
using namespace std;

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

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
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
            // aage badho
            child = root->children[index];
        }
        else
        {
            // absent
            // create and aage badho
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recrsion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    
    void printSuggestions(TrieNode* curr, vector<string>&temp, string prefix)
    {
        if(curr->isTerminal == true)
        {
            temp.push_back(prefix);
//             why did we remove return statement from here ???
        }
        
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode* next = curr->children[ch - 'a'];
            
            if(next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        
        for(int i=0; i<str.length(); i++)
        {
            char lastChar = str[i];
            
            prefix.push_back(lastChar);
            
//             check for the last character
            TrieNode* curr = prev->children[lastChar - 'a'];
            
//             if not found
            if(curr == NULL)
            {
                break;
            }
            
//             if found
            vector<string>temp;
            printSuggestions(curr, temp, prefix);
            
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    creation of trie
    Trie* t = new Trie();
    
//     insert all the contacts in the trie
    for(int i=0; i<contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWord(str);
    }
    
//     return ans
    return t->getSuggestions(queryStr);
}