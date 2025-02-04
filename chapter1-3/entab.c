#include <stdio.h>
#define TAB_WIDTH 4

/* Write a program entab that replaces strings of blanks by the
   minimum number of tabs and blanks to achieve the same spacing. Use the
   same tab stops as for detab. When either a tab or a single blank would suffice
   to reach a tab stop, which should be given preference?
   */

int main(void){
    int c, pos = 0, blankCount = 0;
    // pos = position counter
    // c is used for input
    // blankCount is used to keep track of spaces
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blankCount++;
            // if blanks reach tab stop use a tab instead
            if ((pos + blankCount) % TAB_WIDTH == 0) {
                putchar('\t');
                pos += blankCount; // append tab number to the position
                blankCount = 0; // reset blank count bc new word
            } else {
                // output remaining blanks as spaces
                while (blankCount > 0) {
                    putchar(' ');
                    pos++; // another position
                    blankCount--;
                }
                putchar(c);
                if (c == '\n') pos = 0; // new line goes back to 0
                else pos++; // otherwise increment position
            }
        }
    }
    return 0;
}
