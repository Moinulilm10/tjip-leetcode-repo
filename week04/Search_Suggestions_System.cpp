#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class TrieNode
    {
    public:
        string word;
        TrieNode *next[26];
        TrieNode()
        {
            word = "";
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    TrieNode *generateTrie(vector<string> &products)
    {
        TrieNode *root = new TrieNode();
        for (auto &wrd : products)
        {
            TrieNode *curr = root;
            for (auto &c : wrd)
            {
                int id = c - 'a';
                if (curr->next[id] == NULL)
                    curr->next[id] = new TrieNode();
                curr = curr->next[id];
            }
            curr->word = wrd;
        }
        return root;
    }
    void dfs(TrieNode *u, vector<string> &words)
    {
        if (u == NULL || words.size() == 3)
            return;
        if (u->word.size() > 0 && words.size() < 3)
        {
            words.push_back(u->word);
        }
        for (int i = 0; i < 26; i++)
        {
            dfs(u->next[i], words);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        TrieNode *root = generateTrie(products);
        vector<vector<string>> suggestions;
        for (auto &c : searchWord)
        {
            root = root && root->next[c - 'a'] ? root->next[c - 'a'] : NULL;
            vector<string> words;
            dfs(root, words);
            suggestions.push_back(words);
        }
        return suggestions;
    }
};