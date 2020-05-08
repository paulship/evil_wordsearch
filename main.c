#include <stdio.h>
#include <stdlib.h>
#include "wordsearch.h"

int main( void )
{
    printf("Starting evil wordsearch generator.\n");

    wordsearch_t* wordsearch_ptr = wordsearch_ctor("bug",20,10);

    if( wordsearch_ptr == NULL )
    {
        printf("It didn't work.\n");
    }
    else
    {
        wordsearch_fill_blanks( wordsearch_ptr );
        wordsearch_print( wordsearch_ptr );

        wordsearch_dtor( wordsearch_ptr );
    }

    printf("All done - exiting now.\n");
    return 0;
}
