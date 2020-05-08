#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "wordsearch.h"

wordsearch_t* wordsearch_ctor( const char* const word, const uint16_t width, const uint16_t height )
{
    wordsearch_t* ret_ptr = malloc( sizeof(wordsearch_t) );

    if( ret_ptr != NULL )
    {
        uint32_t gridsize = ((uint32_t)width) * ((uint32_t)height);
        ret_ptr->lettergrid_ptr = malloc( sizeof(char) * gridsize );
        if( ret_ptr->lettergrid_ptr != NULL )
        {
            ret_ptr->initial_word_ptr = word;
            ret_ptr->initial_word_len = strlen(word);
            ret_ptr->lettergrid_height = height;
            ret_ptr->lettergrid_width = width;
            for( uint32_t n=0 ; n<gridsize; n++ )
            {
                ret_ptr->lettergrid_ptr[n] = ' ';
            }
        }
        else
        {
            free( ret_ptr );
            ret_ptr = NULL;
        }
    }

    return( ret_ptr );
}


void wordsearch_dtor( wordsearch_t* const data_ptr )
{
    free( data_ptr->lettergrid_ptr );
    free( data_ptr );
}


void wordsearch_fill_blanks( wordsearch_t* const data_ptr )
{
    const uint32_t gridsize = ((uint32_t)data_ptr->lettergrid_height) * ((uint32_t)data_ptr->lettergrid_width);

    for( uint32_t n=0; n<gridsize; n++ )
    {
        char* const char_ptr = data_ptr->lettergrid_ptr + n;
        if( *char_ptr == ' ' )
        {
            uint16_t letter_index = rand() % data_ptr->initial_word_len;
            *char_ptr = data_ptr->initial_word_ptr[letter_index];
        }
    }
}


void wordsearch_print( wordsearch_t* const data_ptr )
{
    char* char_ptr = data_ptr->lettergrid_ptr;

    for( uint16_t n=0; n<data_ptr->lettergrid_height; n++ )
    {
        for( uint16_t m=0; m<data_ptr->lettergrid_width; m++ )
        {
            printf("%c",*char_ptr);
            char_ptr++;
        }
        printf("\n");
    }

}
