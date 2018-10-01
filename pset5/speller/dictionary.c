// Implements a dictionary's functionality

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"

typedef struct node
{
    char word[LENGTH];
    struct node *next;
}
node;

node* HASHTABLE[HASHTABLE_SIZE];

/*
   Hash function from /r/cs50 :
   https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
*/

int hash_it(char* word)
{
    unsigned int hash = 0;
    for (int i=0; word[i] != '\0'; i++)
        hash = (hash << 2) ^ word[i];
    return hash % HASHTABLE_SIZE;
}

// To count the number of words in the dictionary
unsigned int words = 0;
bool status;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char s1[(strlen(word) + 1)];
    strcpy(s1, word);

    for(int i = 0; s1[i] != '\0'; i++)
    {
        s1[i] = tolower(s1[i]);
    }

    node *n = HASHTABLE[hash_it(s1)];

    while (n != NULL)
    {
        if(strcmp(s1,word) == 0)
        {
                return true;
        }

        else
        {
            n = n->next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for (int i = 0; i < HASHTABLE_SIZE; HASHTABLE[i] = NULL, i++) {}

    FILE* fptr = fopen(dictionary, "r");
    if (fptr == NULL)
    {
        printf("Dictionary failed to open");
        return false;
    }

    // Iterate through the words of the dictionary
    while (true)
    {
        node *n1 = malloc(sizeof(node));

        fscanf(fptr, "%s", n1->word);
        n1->next = NULL;

        if(feof(fptr))     // DOUBT
        {
            free(n1);
            return false;
        }

        words++;

        node *n2 = HASHTABLE[hash_it(n1->word)];

        if (n2 == NULL)
        {
            HASHTABLE[hash_it(n1->word)] = n1;
        }

        else
        {
            n1->next = HASHTABLE[hash_it(n1->word)];
            HASHTABLE[hash_it(n1->word)] = n1;
        }
    }

    fclose(fptr);
    status = true;
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (status == true)
    {
        return words;
    }

    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *ptr = HASHTABLE[i];
        while (ptr != NULL)
        {
            node *t = ptr;
            ptr = ptr->next;
            free(t);
        }
    }
    status = false;
    return false;
}
