//
//  main.c
//  CD
//
//  Created by Ree on 12/7/16.
//  Copyright © 2016 Ree. All rights reserved.
//
//Create Pokedex for first gen pokemon including name, type, evolution level, and if I find them cute.
//Add functionality to add pokemon.


#include <stdio.h>      // declares printf(), scanf() and fpurge().
#include <stdbool.h>    //make bool type usable
#include <string.h>     // declares strcmp().
#include <stdlib.h>     // We'll need that later for malloc() and realloc().

struct Pokedex  //make structure for pokedex
    {
        char Name[20];
        int Number;
        char Type[25];
        int EvoLvl;
        //bool isCute;
    };

// Global variables:
int                        gNumEntries = 0;
struct Pokedex*            gPokedex = NULL;

//Make a new entry sub-routine.
void MakeNew();

void MakeNew()
{
//    char yesOrNo;
    
    // First, create a new array element (or a new array if we don't have one yet):
    if( gPokedex == NULL )
    {
        gPokedex = malloc( sizeof(struct Pokedex) ); // size of 1 element.
        if( gPokedex == NULL )    // Still NULL? malloc() must have returned NULL due to error.
        {
            printf( "ERROR: Couldn't create a new entry!\n" );
            return;
        }
    }
    else
    {
        struct Pokedex* newPtr = NULL;
        newPtr = realloc( gPokedex, (gNumEntries +1) *sizeof(struct Pokedex) );
        if( newPtr == NULL )    // Error! Out of memory?
        {
            // We just keep the old pointer in gDatabase.
            printf( "ERROR: Couldn't create a new entry!\n" );
            return;
        }
        // newPtr is our new ptr, gDatabase is no longer valid!
        gPokedex = newPtr;    // Remember newPtr in gDatabase.
    }
    // Make sure we remember we have one more entry:
    gNumEntries += 1;
    
    printf("Pokemon Name?: ");
    scanf("%s20",gPokedex[gNumEntries-1].Name);
    
    printf("Pokemon Number?: ");
    scanf("%d",&gPokedex[gNumEntries-1].Number);

    printf("Pokemon Type?: ");
    scanf("%s25",gPokedex[gNumEntries-1].Type);
    
    printf("Level of Evolution?: ");
    scanf("%d",&gPokedex[gNumEntries-1].EvoLvl);
    
    //printf("Is it cute? (y/n)");
    //scanf("%c",&yesOrNo);
    
    fpurge(stdin);
    
    //gPokedex[ gNumEntries -1 ].isCute = (yesOrNo == 'y' || yesOrNo == 'Y');
}

//List all entries sub-routine.

void List();

void List()
{
    int    x = 0;
    
    if( gPokedex == NULL )
    {
        printf("There are no Pokemon in the Pokedex.\n");
        return;
    }
    while( x < gNumEntries )
    {
        printf( "Pokemon: %s\n", gPokedex[ x ].Name );
        printf( "Number: %d\n",gPokedex[ x ].Number);
        printf( "Type: %s\n", gPokedex[ x ].Type );
        printf( "Evolves at: %d\n", gPokedex[ x ].EvoLvl );
        //if( gPokedex[ x ].isCute )
        //    printf( "\tThis Pokemon is cute!\n" );
        printf( "\n" );    // Add an empty line for space to the next CD.
        
        x += 1;
    }
}

void    DoCleanUp( void );

void    DoCleanUp( void )
{
    if( gPokedex != NULL )    // We have allocated memory?
    {
        free( gPokedex );
        gPokedex = NULL;                // Not really necessary, but good style.
        gNumEntries = 0;
    }
}

int main(int argc, const char * argv[])
{
    //struct Pokedex myEntries[150];
    
    //Sample Entry
    //strcpy(myEntries[0].Name, "MissingNo.");
    //strcpy(myEntries[0].Type, "???");
    //myEntries[0].EvoLvl = 0;
    //myEntries[0].isCute = true;
    
    //printf( "Pokemon Name: %s\n", myEntries[0].Name );
    //printf( "Pokemon Type: %s\n", myEntries[0].Type );
    //printf( "Evolution at: %d\n", myEntries[0].EvoLvl);
    //if (myEntries[0].isCute == true)
    //{
    //    printf( "Cute!\n");
    //}
    
    
    bool run = true;
    char input[10];
    while(run == true)
    {
        
        printf("Type 'NEW' to add a new pokemon to the pokedex, 'LIST' to list them all or 'END' to end.\n");
        scanf("%9s",input);
        fpurge(stdin);
        
        if(strcmp(input,"NEW") == 0)
            //code for new entry
            //printf("NEW");
            MakeNew(); //sub-routine for making new entries
        else if(strcmp(input,"LIST") == 0)
            //code for list
            //printf("LIST");
            List(); //sub-routine for listing all entries
        else if(strcmp(input,"END") == 0)
            run = false;
        else
            printf("ERROR: Retype 'NEW', 'LIST', or 'END' please.\n");
            
    }
    
    DoCleanUp();
    
    return 0;
}
