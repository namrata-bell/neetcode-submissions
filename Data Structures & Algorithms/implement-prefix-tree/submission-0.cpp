#include <bits/stdc++.h>
using namespace std;

class PrefixTree {
    struct Node {
        Node* child[26];
        bool end;

        Node() {
            end = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    void insert(string word) {
        Node* cur = root;

        for (int i = 0; i < word.size(); i++) {
            int j = word[i] - 'a';

            if (cur->child[j] == nullptr)
                cur->child[j] = new Node();

            cur = cur->child[j];
        }

        cur->end = true;
    }

    bool search(string word) {
        Node* cur = root;

        for (int i = 0; i < word.size(); i++) {
            int j = word[i] - 'a';

            if (cur->child[j] == nullptr)
                return false;

            cur = cur->child[j];
        }

        return cur->end;
    }

    bool startsWith(string prefix) {
        Node* cur = root;

        for (int i = 0; i < prefix.size(); i++) {
            int j = prefix[i] - 'a';

            if (cur->child[j] == nullptr)
                return false;

            cur = cur->child[j];
        }

        return true;
    }
};