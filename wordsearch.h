#ifndef _WORDSEARCH_H
#define _WORDSEARCH_H

#include <stdint.h>
#include <stdbool.h>

/*
    Structure to represent the wordsearch. When you create a wordsearch, a pointer to one of these will be returned. Don't
    lose this pointer - you need it destroy the wordsearch and unallocate the memory later on!!
*/
typedef struct
{
    /* Pointer to the word that we want to avoid having in the wordsearch */
    const char* initial_word_ptr;
    /* Length of the original word in the wordsearch */
    uint8_t initial_word_len;
    /* Pointer to the start of the letter grid. note - not a string! This numbergrid size is determined by grid*height */
    char* lettergrid_ptr;
    /* Defines the size of the grid */
    uint16_t lettergrid_width;
    uint16_t lettergrid_height;
} wordsearch_t;


extern wordsearch_t* wordsearch_ctor( const char* const word, const uint16_t width, const uint16_t height );
extern void wordsearch_dtor( wordsearch_t* const data_ptr );

extern void wordsearch_fill_blanks( wordsearch_t* const data_ptr );
extern void wordsearch_print( wordsearch_t* data_ptr );
extern bool wordsearch_blank_words( wordsearch_t* const data_ptr );

#endif /* _WORDSEARCH_H */
