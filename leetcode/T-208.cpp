/**
 * 208. 实现 Trie (前缀树)
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 */

#include <string>

using namespace std;

template <size_t N>
struct TrieNode
{
    TrieNode() : cnt(0), isEnd(false) {
        for (size_t i = 0; i < N; ++i) {
            children[i] = nullptr;
        }
    }
    TrieNode *children[N];
    int cnt;
    bool isEnd;
};

class Trie {
public:
    Trie() : root(new TrieNode<Num>()) {}

    void insert(string word) {
        auto p = root;

        for (size_t i = 0; i < word.length(); ++i) {
            char c = word[i];

            if (p->children[c - 'a'] == nullptr) {
                p->children[c - 'a'] = new TrieNode<Num>();
                ++p->cnt;
            }

            p = p->children[c - 'a'];
        }

        p->isEnd = true;
    }

    bool search(string word) {
        auto p = root;

        for (size_t i = 0; i < word.length(); ++i) {
            char c = word[i];

            if (p->children[c - 'a'] == nullptr) {
                return false;
            }

            p = p->children[c - 'a'];
        }

        return p->isEnd;
    }

    bool startsWith(string prefix) {
        auto p = root;

        for (size_t i = 0; i < prefix.length(); ++i) {
            char c = prefix[i];

            if (p->children[c - 'a'] == nullptr) {
                return false;
            }

            p = p->children[c - 'a'];
        }

        return true;
    }
private:
    static const size_t Num = 26;
private:
    TrieNode<Num> *root;
};
