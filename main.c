#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wordsearch.h"

int main( void )
{
    printf("Starting evil wordsearch generator.\n");

    srand(time(NULL));

    wordsearch_t* wordsearch_ptr = wordsearch_ctor("bug",160,50);

    if( wordsearch_ptr == NULL )
    {
        printf("It didn't work.\n");
    }
    else
    {
        wordsearch_fill_blanks( wordsearch_ptr );
        do
        {
            printf("\nWordsearch is now:\n");
            wordsearch_print( wordsearch_ptr );
            wordsearch_fill_blanks( wordsearch_ptr );
            printf("\nRefilled blanks:\n");
            wordsearch_print( wordsearch_ptr );
        } while ( wordsearch_blank_words( wordsearch_ptr ) );


        printf("\n\nFinal wordsearch now looks like this.....\n\n");
        wordsearch_print( wordsearch_ptr );

        wordsearch_dtor( wordsearch_ptr );
    }

    printf("All done - exiting now.\n");
    return 0;
}
