#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int win_choice(char* player_choice, char* computer_choice) {
    if (strcmp(player_choice, "Stone") == 0) {
        if (strcmp(computer_choice, "Stone") == 0) return -1;
        if (strcmp(computer_choice, "Paper") == 0) return 0;
        if (strcmp(computer_choice, "Scissors") == 0) return 1;
    
    } else if (strcmp(player_choice, "Paper") == 0) {
        if (strcmp(computer_choice, "Stone") == 0) return 1;
        if (strcmp(computer_choice, "Paper") == 0) return -1;
        if (strcmp(computer_choice, "Scissors") == 0) return 0;
    
    } else if (strcmp(player_choice, "Scissors") == 0) {
        if (strcmp(computer_choice, "Stone") == 0) return 0;
        if (strcmp(computer_choice, "Paper") == 0) return 1;
        if (strcmp(computer_choice, "Scissors") == 0) return -1;
    }

    return -1;
}

int play_game(int points_to_win) {
    char player_choice[10], computer_choice[10];
    int player_points = 0, computer_points = 0, computer_number, result;

    while (player_points != points_to_win && computer_points != points_to_win) {
        printf("Your Points: %d\n", player_points);
        printf("Computer Points: %d\n", computer_points);

        choice:
            printf("What do you choose(Stone, Paper or Scissors): ");
            scanf("%s", player_choice);
        if (strcmp(player_choice, "stone") == 0 || strcmp(player_choice, "Stone") == 0) 
            strcpy(player_choice, "Stone");
        else if (strcmp(player_choice, "paper") == 0 || strcmp(player_choice, "Paper") == 0) 
            strcpy(player_choice, "Paper");
        else if (strcmp(player_choice, "scissors") == 0 || strcmp(player_choice, "Scissors") == 0) 
            strcpy(player_choice, "Scissors");
        else {
            printf("Invalid Choice!\n");
            goto choice;
        }

        computer_number = rand() % 3;
        switch (computer_number) {
            case 0: strcpy(computer_choice, "Stone"); break;
            case 1: strcpy(computer_choice, "Paper"); break;
            case 2: strcpy(computer_choice, "Scissors"); break;
        }
        printf("The computer chose: %s\n", computer_choice);

        result = win_choice(player_choice, computer_choice);
        switch (result) {
            case 1: player_points++; break;
            case 0: computer_points++; break;
            default: break;
        } 
    }

    printf("Your Points: %d\n", player_points);
    printf("Computer Points: %d\n", computer_points);

    if (player_points == points_to_win) return 1;
    else if (computer_points == points_to_win) return 0;
}

int main() {
    int points_to_win;
    printf("Enter the number of points to win: ");
    scanf("%d", &points_to_win);

    srand(time(NULL));

    int result = play_game(points_to_win);
    switch (result) {
        case 1: printf("Congratulations you won the game!\n"); break;
        case 0: printf("Sorry! You lost the game!\n"); break;
    }

    char choice[10];
    loop:
        printf("Do you want to play again(Yes, No)? ");
        scanf("%s", choice);
        if (strcmp(choice, "yes") == 0) strcpy(choice, "Yes");
        else if (strcmp(choice, "no") == 0) strcpy(choice, "No");
        else {
            printf("Invalid Choice!\n");
            goto loop;
        }

    if (strcmp(choice, "Yes") == 0) {
        printf("Enter the number of points to win: ");
        scanf("%d", &points_to_win);

        result = play_game(points_to_win);
        switch (result) {
        case 1: printf("Congratulations you won the game!\n"); break;
        case 0: printf("Sorry! You lost the game!\n"); break;
        }
        goto loop;
    } else {
        printf("Thanks for playing!\n");
        return 0;
    }
}