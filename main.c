#include "AhoCorasickArray.h"

int main() {
    char* text = "thisisaPLaintext";
    char* search[] = {"hello", "thi", "PLa", "text"};
    int searchCount = 4;

    Trie* trie = Trie_Initalize();
    char** lastWord = (search + searchCount - 1);
    for (char** word = search; word <= lastWord; word++) {
        Trie_AddWord(trie, *word);
    }
    SearchInText(text, trie);

    Trie_Destroy(trie);

    return 0;
}
