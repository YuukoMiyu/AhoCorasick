#ifndef AHO_CORASICK_ARRAY_HEADER
#define AHO_CORASICK_ARRAY_HEADER

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Trie Trie;

Trie* Trie_Initalize();
void Trie_AddWord(Trie* self, char* word);
void Trie_Destroy(Trie* self);

void SearchInText(char* text, Trie* trie);

#endif
