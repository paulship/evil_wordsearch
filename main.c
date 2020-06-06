#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wordsearch.h"

int main( void )
{
    /* Initialise the random number generator - only do this once!!! */
    srand(time(NULL));

    /* After we have sanitised the inputs, we are able to create our wordsearch. */
    wordsearch_t* wordsearch_ptr = wordsearch_ctor("BUG",60,20);

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
