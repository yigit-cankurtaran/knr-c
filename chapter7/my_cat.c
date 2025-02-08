#include <stdio.h>

int main(int argc, char **argv) {
    FILE *fp;
    void filecopy(FILE *, FILE *); // takes 2 file pointers

    if (argc == 1){ // no arguments
        filecopy(stdin, stdout); // copy from input to output
        // stdin and stdout are objects, type FILE *, constants.
    } else {
        while (--argc > 0) { // if argc is larger than 1
            // e.g. ./a.out hi.txt
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("my_cat: can't open %s\n", *argv);
                // e.g. ./a.out nonexistent prints "can't open nonexistent"
                return 1;
            } else {
                filecopy(fp, stdout); // we copy everything inside to the screen
                fclose(fp); // the opposite of fopen
                // break the connection, free the pointer
            }
        }
    }
    return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF) putc(c, ofp);
    // putc (int char, FILE *stream);
    // while input stream isn't eof, print it out on the screen
}

