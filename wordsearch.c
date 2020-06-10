#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "wordsearch.h"


static bool check_and_destroy( wordsearch_t* const data_ptr, const int32_t x_start, const int32_t y_start, const int32_t x_step, const int32_t y_step );
static int32_t calc_idx( const int32_t x_size, const int32_t x_pos, const int32_t y_pos );

/*
    Constructor
*/
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

/*
    Destructor
*/
void wordsearch_dtor( wordsearch_t* const data_ptr )
{
    free( data_ptr->lettergrid_ptr );
    free( data_ptr );
}

/*
    Fills any squares in the wordsearch that are currently blank with a random character
    from the character pool.
*/
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

/*
    Print the wordsearch to stdout.
*/
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

/*
    This function looks for any instance in the wordsearch where out initial word can be found
    and, if it does exist, replaces one of the characters in the word with a space. At the end,
    there will be no instances of the initial word in the wordsearch. The function will return
    TRUE if any ssquares have been blanked out, and FALSE if nothing was blanked out, meaning
    we now have a completed evil wordsearch.
*/
bool wordsearch_blank_words( wordsearch_t* const data_ptr )
{
    bool changes_made = false;

    for( uint16_t x=0; x<data_ptr->lettergrid_width; x++ )
    {
        for( uint16_t y=0; y<data_ptr->lettergrid_height; y++ )
        {
            const bool right      = check_and_destroy( data_ptr, x, y,  1,  0 );
            const bool right_down = check_and_destroy( data_ptr, x, y,  1,  1 );
            const bool down       = check_and_destroy( data_ptr, x, y,  0,  1 );
            const bool down_left  = check_and_destroy( data_ptr, x, y, -1,  1 );
            const bool left       = check_and_destroy( data_ptr, x, y, -1,  0 );
            const bool left_up    = check_and_destroy( data_ptr, x, y, -1, -1 );
            const bool up         = check_and_destroy( data_ptr, x, y,  0, -1 );
            const bool up_right   = check_and_destroy( data_ptr, x, y,  1, -1 );

            changes_made |= ( right || right_down || down || down_left || left || left_up || up || up_right );
        }
    }

    return( changes_made );
}

/*
    This is an internal function used to check if the target word exists in a particular
    location in the grid. The initial x and y positions are provided, as are the
    x and y step values. The step values should be one of [+1,0,-1] and control if the
    search is being done upwards, downwards, to the left or right. 

    If the target word is present, one of the characters in the word will be replaced with
    a space, and the function returns TRUE. Function returns FALSE if the word is not
    present and no changes have been made. 
*/
static bool check_and_destroy( wordsearch_t* const data_ptr, const int32_t x_start, const int32_t y_start, const int32_t x_step, const int32_t y_step )
{
    /* Get a local copy of some important data on the stack */
    const int32_t initial_word_len = (int32_t)(data_ptr->initial_word_len);
    const int32_t lettergrid_width = (int32_t)(data_ptr->lettergrid_width);
    const int32_t lettergrid_height = (int32_t)(data_ptr->lettergrid_height );

    /* Quick check for bollocksy data */
    if( initial_word_len < 1 )
    {
        return false;
    }

    /* First check that the scan area is not about to fall off the end of the wordsearch. */
    const int32_t x_end = x_start + ( (initial_word_len-1) * x_step );
    const int32_t y_end = y_start + ( (initial_word_len-1) * y_step );

    if( ( x_end<0 ) || ( y_end<0 ) || ( x_end>=lettergrid_width ) || ( y_end>=lettergrid_height ) )
    {
        return false; /* Exit without having done anything. */
    }

    /* Scan through and see if we have a match on the word */
    bool match_found = true;
    for( int32_t n=0; n<initial_word_len; n++ )
    {
        if( match_found )
        {
            /* Index in the grid of the letter we are checking */
            int32_t idx = calc_idx( lettergrid_width, x_start + (n*x_step), y_start + (n*y_step) );
            match_found = ( data_ptr->initial_word_ptr[n] == data_ptr->lettergrid_ptr[idx] );
        }
    }

    /* If we've found a match, we need to kill one of the letters at random by replacing it with a space. */
    if( match_found )
    {
        const int32_t kill_pos = rand() % initial_word_len;
        const int32_t kill_idx = calc_idx( lettergrid_width, x_start + (kill_pos*x_step), y_start + (kill_pos*y_step) );
        data_ptr->lettergrid_ptr[kill_idx] = ' ';
    }

    return( match_found );
}

/*
    Converts an x and y position into a grid location, depending on the width of the
    lettergrid.
*/
static int32_t calc_idx( const int32_t x_size, const int32_t x_pos, const int32_t y_pos )
{
    return y_pos * x_size + x_pos;
}

