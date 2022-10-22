#include<iostream>
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
        int index = word[0] - 'A';
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

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        // base case 
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
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

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void deleteUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // absent
            std::cout << "Word not found!! Unable to delete!!\n";
            return;
        }

        deleteUtil(child, word.substr(1));
    }

    void deleteWord(string word)
    {
        deleteUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("ABCD");
    t->insertWord("TIME");
    t->insertWord("DO");
    t->insertWord("DUCK");


    cout<<"Present or Not:  "<<t->searchWord("ABCD")<<endl;
    cout<<"Present or Not:  "<<t->searchWord("TIME")<<endl;
    cout<<"Present or Not:  "<<t->searchWord("TIM")<<endl;
    cout<<"Present or Not:  "<<t->searchWord("DUCK")<<endl;
    cout<<endl;
    
    cout<<"Before deleting  'DO': "<<endl;
    cout<<"Present or Not:  "<<t->searchWord("DO")<<endl;
    t->deleteWord("DO");
    cout<<"After deleting  'DO': "<<endl;
    cout<<"Present or Not:  "<<t->searchWord("DO")<<endl;


return 0;
}