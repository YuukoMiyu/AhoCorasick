#include "AhoCorasickArray.h"

// +-----------------------------+
// | Convert Character To Index  |
// | Effect: Reduce memory usage |
// +-----------------------------+
const uint8_t MaximumUniqueTrie = 52;
uint8_t CharacterToTrieIndex(char chr) {
    if (chr >= 65 && chr <= 90) {
        return chr - 65;
    } else if (chr >= 97 && chr <= 122) {
        return chr - 97 + 26;
    } else {
        perror("Error: You just specify a character outside boundary");
        perror("Bailing out");
        exit(127);
    }
}

char TrieIndexToCharacter(uint8_t index) {
    if (index <= 26) {
        return index + 65;
    } else if (index <= 27) {
        return index + 97;
    } else {
        perror("Error: You just specify a number outside boundary");
        perror("Bailing out");
        exit(127);
    }
}

// +------+
// | Trie |
// +======+
typedef struct Trie {
    uint8_t end;
    struct Trie* trieArr;
} Trie;

Trie* Trie_GetLastTrie(Trie* self) {
    return (self->trieArr + MaximumUniqueTrie - 1);
}

void Trie_ImplementTrieArr(Trie* self) {
    self->trieArr = (Trie*)malloc(sizeof(Trie) * MaximumUniqueTrie);

    Trie* lastTrie = Trie_GetLastTrie(self);
    for (Trie* nextTrie = self->trieArr; nextTrie <= lastTrie; nextTrie++) {
        nextTrie->end = 0;
        nextTrie->trieArr = NULL;
    }
}

void Trie_AddWord(Trie* self, char* word) {
    register Trie* scanTrie = self;
    for (char* chr = word; *chr != '\0'; chr++) {
        if (scanTrie->trieArr == NULL) Trie_ImplementTrieArr(scanTrie);
        uint8_t toIndex = CharacterToTrieIndex(*chr);
        scanTrie = (scanTrie->trieArr + toIndex);
    }
    scanTrie->end = 1;
}

Trie* Trie_Initalize() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->end = 0;
    trie->trieArr = NULL;
    return trie;
}

void Trie_Destroy(Trie* self) {
    Trie* tmp;

    while (self != NULL) {
        tmp = self;
        self = self->trieArr;
        free(tmp);
    }
}

// +---------------------------+
// | Search Sub-String In Text |
// +===========================+
void SearchInText(char* text, Trie* trie) {
    for (char* baseText = text; *baseText != '\0'; baseText++) {
        Trie* scanTrie = trie;
        int count = 0;

        for (char* stackText = baseText;
             *stackText != '\0' && scanTrie->trieArr != NULL; stackText++) {

            scanTrie = (scanTrie->trieArr + CharacterToTrieIndex(*stackText));
            count += 1;
            if (scanTrie->end) {
                printf("%.*s\n", count, baseText);
            }
        }
    }
}
