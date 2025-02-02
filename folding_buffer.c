// complicated approach (with buffer)
int main(){
    int c, last_space = -1; // will use c as input and last_space to remember last space position
    int len = 0, pos = 0; // length and position
    char myString[10 * N]; // buffer approach.

    while((c = getchar()) != EOF){
        if (c != '\n' && c != '\0'){
            myString[pos] = c;
            if (myString[pos] == ' ' || myString[pos] == '\t'){
                last_space = pos;
            }
            len++;
            pos++;
            myString[pos] = '\0'; // adding null termination

            if (len > N) {
                if (last_space > 0) {
                    // print up to last space
                    myString[last_space] = '\0';
                    printf("%s\n", myString);

                    // move remaining chars to the start of buffer
                    int i, j;
                    for (i = last_space + 1, j = 0; i < pos; i++, j++){
                        // i starts right after the space
                        // j starts at the beginning of the buffer
                        // i < pos keeps going until we hit the end of text
                        // move both counters forward
                        myString[j] = myString[i];
                    }
                    myString[j] = '\0';
                    // this effectively prints the past chars
                    // and moves the chars after it to the beginning of buffer
                    // press ctrl+d to see the wrapped line

                    // resetting counters
                    pos = j;
                    len = j;
                    last_space = -1;
                } else {
                    // no space exists
                    myString[pos - 1] = '\0';
                    printf("%s\n", myString);
                    pos = 0;
                    len = 0;
                    last_space = -1;
                }
            } else if (c == '\n') {
                // print current buffer and reset
                myString[pos] = '\0';
                printf("%s\n", myString);
                pos = 0;
                len = 0;
                last_space = -1;
            }
        }
    }
    // if any text remains
    if (pos > 0) {
        myString[pos] = '\0';
        printf("%s", myString);
    }
    
    return 0;
}
