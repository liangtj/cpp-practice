#include <vector>
#include <string>
#include <memory>
using namespace std;
struct SkipNode;
// typedef shared_ptr<SkipNode> SkipNode*;

struct SkipNode {
    int key;
    string value;
    vector<SkipNode*> forward;
    SkipNode(int k, const string v, int level)
        : key(k), value(v)
    {
        for(int i = 0; i < level; i++) {
            forward.emplace_back(nullptr);
        }
    }
};

class SkipList {
public:
    SkipList();

    void print();
    SkipNode* find(int searchKey);

    void insert(int searchKey, string newValue);
    void erase(int searchKey);

private:
    SkipNode* head;
    SkipNode* nil;

    int randomLevel();
    SkipNode* createNode(int key, string val, int level);

    int maxLevel;
};

// #include "skipList.cpp"

