#include <stdio.h>

#define MAX_WORD_LENGTH 20
#define NUM_CHARS 128

void histogram(){
    int input, word_length = 0;
    int lengths[MAX_WORD_LENGTH + 1] = {0}; // array to store word count by length

    while ((input = getchar()) != EOF) {
        // check for whitespace
        if (input == ' ' || input == '\n' || input == '\t'){
            if (word_length > 0){ // process the word we completed
                if (word_length <= MAX_WORD_LENGTH){
                    lengths[word_length]++; // increment count for this length
                }
                word_length = 0; // reset for the next word
            }
        } else {
            word_length++; // count current word length
        }
    }

    // if input doesn't end with whitespace, handle the last word
    if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
        lengths[word_length]++;
    }

    //print the histogram
    printf("word length histogram:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++){
        if (lengths[i] > 0) { // don't print 0 counts
            printf("%2d: ", i); // print word length, right justified
            for (int j = 0; j < lengths[i]; j++) putchar('*');
            // print a * for every word of the same length
            putchar('\n'); // next line
        }
    }
    // ctrl+d after you finish inputting to get results
}

int main() {
    histogram();
}
