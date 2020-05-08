#include <stdio.h>
#include <stdlib.h>

#ifndef _WORDSEARCH_H
#define _WORDSEARCH_H

/*
    Structure to represent the wordsearch. When you create a wordsearch, a pointer to one of these will be returned. Don't
    lose this pointer - you need it destroy the wordsearch and unallocate the memory later on!!
*/
typedef struct
{
    /* Pointer to the word that we want to avoid having in the wordsearch */
    const char* initial_word;
    /* Length of the original word in the wordsearch */
    uint8_t initial_word_len;
    /* Bitmap used for uninitialised letters */
    uint32_t unique_letters_map;
    /* Pointer to the start of the letter grid. note - not a string! This numbergrid size is determined by grid*height */
    char* lettergrid;
    /* Array similar to that above indicating possible letters for each entry in the grid */
    uint32_t* lettergrid_poss;
    /* Defines the size of the grid */
    uint16_t lettergrid_width;
    uint16_t lettergrid_height;
} wordsearch_t;



#endif /* _WORDSEARCH_H */
