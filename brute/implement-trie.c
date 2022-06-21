#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Trie {
    struct Trie** node;
    bool isword;
} Trie;


Trie* trieCreate() {
    Trie* res = (Trie*)malloc(1*sizeof(Trie));
    res->node = (Trie**)malloc(26*sizeof(Trie*));
    res->isword = false;
    return res;
}

void trieInsert(Trie* obj, char * word) {
    Trie* p = obj;
    int len = strlen(word);
    for(int i=0; i<len; i++)
    {
        int idx = word[i] - 'a';
        if(!p->node[idx])
        {
            p->node[idx] = trieCreate();
        }
        p = p->node[idx];
    }
    p->isword = true;
}

bool trieSearch(Trie* obj, char * word) {
    Trie* p = obj;
    int len = strlen(word);
    for(int i=0; i<len; i++)
    {
        int idx = word[i] - 'a';
        if(!p->node[idx])
        {
            return false;
        }
        p = p->node[idx];
    }
    return p->isword;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    Trie* p = obj;
    int len = strlen(prefix);
    for(int i=0; i<len; i++)
    {
        int idx = prefix[i] - 'a';
        if(!p->node[idx])
        {
            return false;
        }
        p = p->node[idx];
    }
    return true;
}

void trieFree(Trie* obj) {
    for(int i=0; i<26; i++) 
    {
        if(!obj->node[i]) 
        {
            free(obj->node[i]);
        }
    }
    free(obj->node);
    free(obj);
}

int main()
{
    Trie* obj = trieCreate();

    trieCreate(obj);

    trieInsert(obj, "hello");
    trieInsert(obj, "halo");

    printf("search hello: %d\n", trieSearch(obj, "hello"));
    printf("search hello: %d\n", trieSearch(obj, "happy"));

    trieFree(obj);

    return 0;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/