#include <stdio.h>

int main(int argc, char **argv) {
    FILE *fp;
    void filecopy(FILE *, FILE *); // takes 2 file pointers
    char *prog = argv[0]; // program name
    // will use during error handling to help us get where the rror was made

    if (argc == 1){ // no arguments
        filecopy(stdin, stdout); // copy from input to output
        // stdin and stdout are objects, type FILE *, constants.
    } else {
        while (--argc > 0) { // if argc is larger than 1
            // e.g. ./a.out hi.txt
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                // e.g. ./a.out nonexistent prints "can't open nonexistent"
                // we print this out on stderr with fprintf bc otherwise it might
                    // write itself into a file which we don't want.
                    // stderr always prints on screen, we use fprintf to access that stream
                return 1;
            } else {
                filecopy(fp, stdout); // we copy everything inside to the screen
                fclose(fp); // the opposite of fopen
                // break the connection, free the pointer
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    // 2 types of error handling
    // exit is available to whatever process called this one so we can test it
    exit(0); // exit 0 means all is good, we can use other ints to signal different errors
}

void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF) putc(c, ofp);
    // putc (int char, FILE *stream);
    // while input stream isn't eof, print it out on the screen
}

