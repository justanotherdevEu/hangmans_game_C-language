#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Array of words
char *words[] = {
    "Abuhado",
    "Acecinar",
    "Agigolado",
    "Álveo",
    "Arrebol",
    "Bahorrina",
    "Bonhomía",
    "Burdégano",
    "Cagaprisas",
    "Supercalifragilisticoespialidoso"
};

// Function to generate a random number
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is already guessed
int isGuessed(char c, char *guessedLetters) {
    int i;
    for (i = 0; i < strlen(guessedLetters); i++) {
        if (c == guessedLetters[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to update the guessed word
void updateGuessedWord(char *guessedWord, char *word, char c) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (word[i] == c) {
            guessedWord[i] = c;
        }
    }
}

// Main function
int main() {
    // Initialize variables
    int lives = 10;
    char guessedLetters[26] = {0};
    char guessedWord[100] = {0};
    int wordIndex = generateRandomNumber(0, 9);
    char *word = words[wordIndex];
    int wordLength = strlen(word);
    int i;

    // Game loop
    while (lives > 0 && strcmp(guessedWord, word) != 0) {
        // Display the guessed word
        printf("Palabra: %s\n", guessedWord);

        // Get the user's guess
        char guess;
        printf("Introduce una letra: ");
        scanf(" %c", &guess);

        // Check if the guess is valid
        if (!isLetter(guess)) {
            printf("La letra debe ser una letra del alfabeto.\n");
            continue;
        }

        // Check if the guess is already guessed
        if (isGuessed(guess, guessedLetters)) {
            printf("La letra ya ha sido adivinada.\n");
            continue;
        }

        // Update the guessed letters
        guessedLetters[strlen(guessedLetters)] = guess;

        // Check if the guess is correct
        if (strchr(word, guess) != NULL) {
            // Update the guessed word
            updateGuessedWord(guessedWord, word, guess);
        } else {
            // Decrease the number of lives
            lives--;
            printf("¡Has fallado! Te quedan %d vidas.\n", lives);
        }
    }

    // Display the result
    if (lives > 0) {
        printf("¡Felicidades! Has adivinado la palabra.\n");
    } else {
        printf("¡Has perdido! La palabra era %s.\n", word);
    }

    return 0;
}
