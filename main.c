#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "wordsearch.h"

/* This is the maximum dimension of either the width or height of the output (ought to be big enough!!) */
#define MAX_DIMENSIONS  65535

static void output_usage_text( void );
static bool check_dimension_ok( const char* const input, int* const output );
static bool check_target_word_ok( const char* const word );

int main( const int argc, const char* const argv[] )
{
    int height = 0;
    int width = 0;

    /* Initialise the random number generator - only do this once!!! */
    srand(time(NULL));

    /* Check we have received 3 arguments. */
    if( argc != 4 )
    {
        output_usage_text();
        return EXIT_FAILURE;
    }

    /* Check that width and height parameters are sensible and in range. */
    if( !check_dimension_ok( argv[2], &width ) )
    {
        printf( "Invalid width, must be in the range 0-%d.\n", MAX_DIMENSIONS );
        return EXIT_FAILURE;
    }
    if( !check_dimension_ok( argv[3], &height ) )
    {
        printf( "Invalid height, must be in the range 0-%d.\n", MAX_DIMENSIONS );
        return EXIT_FAILURE;
    }

    /* Check target word is ok. */
    if( !check_target_word_ok( argv[1] ) )
    {
        printf( "Target word invalid - must contain only alphanumerics, and at least 3 unique characters.\n" );
        return EXIT_FAILURE;
    }

    /* After we have sanitised the inputs, we are able to create our wordsearch. */
    wordsearch_t* wordsearch_ptr = wordsearch_ctor(argv[1],width,height);

    if( wordsearch_ptr == NULL )
    {
        printf("Memory allocation error.\n");
        return EXIT_FAILURE;
    }
    else
    {
        /* Repeatedly fill in any blanks and remove instances where the target word appears, until it is no longer there. */
        do
        {
            wordsearch_fill_blanks( wordsearch_ptr );
        } while ( wordsearch_blank_words( wordsearch_ptr ) );


        /* Output the final wordsearch. */
        wordsearch_print( wordsearch_ptr );

        /* Clean up memory usage. */
        wordsearch_dtor( wordsearch_ptr );
    }

    return EXIT_SUCCESS;
}


static void output_usage_text( void )
{
    printf( "Evil wordsearch generator.\n"
            "Usage:\n"
            "    wordsearch [target word] [width] [height]\n"
            "\n"
            "Target word must be alphanumeric, not contains spaces, and at least 3 unique characters.\n"
            "\n" );
}

static bool check_dimension_ok( const char* const input, int* const output )
{
    /* Check the string input length is ok. */
    if( strlen( input ) > 6 )
    {
        return false;
    }

    /* Check the string only contains numbers */
    const char* c_ptr = input;
    while( *c_ptr != '\0' )
    {
        if( ( *c_ptr < '0' ) || ( *c_ptr > '9' ) )
        {
            return false;
        }
        c_ptr++;
    }

    /* Convert to integer */
    *output = atoi( input );

    /* Check it is in range. */
    if( ( *output < 0 ) || ( *output > MAX_DIMENSIONS )  )
    {
        return false;
    }

    return true;
}

static bool check_target_word_ok( const char* const word )
{
    return( true );
}
