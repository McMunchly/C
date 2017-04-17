/* play craps */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    char input, wins = 0, losses = 0;
    bool play = true, result;
       
    srand((unsigned) time(NULL));
        
    printf("Welcome to craps!\n");
     
    while(play)
    {
        result = play_game();
         
        if(result == true)
            wins++;
        else
            losses++;
                   
        printf("\nPlay again? ");
        input = getchar();
    
        if(input == 'y')
        {
            play = true;
        }
        else
            play = false;
            
        scanf("%c", &input);
    }
    
    printf("\nWins: %d\tLosses: %d\n", wins, losses);
    
    return 0;
}

int roll_dice(void)
{
    int rand1, rand2;
    
    rand1 = (rand() % 6) + 1;
    rand2 = (rand() % 6) + 1;
    return rand1 + rand2;
}

bool play_game(void)
{
    int result = roll_dice(), point;
    bool game = true;
    
    printf("\nYou rolled: %d\n", result);
        
    /* first roll */
    switch(result)
    {
        case 7: case 11:
            printf("You win!\n");
            return true;
        case 2: case 3: case 12:
            printf("You lose!\n");
            return false;
        default:
            point = result;
            printf("Your point is %d\n", point);
            break;
    }
    
    /* roll until the players rolls a 7 or rolls the point */
    while(game)
    {
        result = roll_dice();
        
        printf("You rolled: %d\n", result);
        
        if(result == point)
        {
            printf("You win!\n");
            return true;
        }
        else if(result == 7)
        {
            printf("You lose!\n");
            break;
        }
    }
    
    return false;
}