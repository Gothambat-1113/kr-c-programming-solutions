#include <stdio.h>
#define OUT     0
#define IN      1
#define MAXHIST 15      /* max length of histogram bar      */
#define MAXWORD 11      /* longest word length tracked + 1  */

int main(void)
{
    int c, i, nc, state;
    int len;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];

    state = OUT;
    nc = 0;
    ovflow = 0;

    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;

    /* count word lengths */
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nc > 0) {                /* a word just ended */
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            }
            nc = 0;
        } else if (state == OUT) {       /* first char of a new word */
            state = IN;
            nc = 1;
        } else {                         /* still inside the word */
            ++nc;
        }
    }

    /* find the tallest bucket */
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];

    /* draw the scaled horizontal histogram */
    for (i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0) {
 if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        } else {
            len = 0;
        }
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    }

    if (ovflow > 0)
        printf("there are %d words >= %d\n", ovflow, MAXWORD);

    return 0;
}
