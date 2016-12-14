/* $Id$
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Wed Dec 14 10:01:17 EET 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/time.h>

#define F(x) __FILE__":%d:%s: " x, __LINE__, __func__

#define CONST_A           1
#define CONST_B           100
#define DEF_RANGE         (CONST_B - CONST_A + 1)
int random_seed = 1;
int n_numbers = 10;
int min = CONST_A;
int max = CONST_B;

int main(int argc, char **argv)
{
    int opt;
    int i, j;
    struct timeval now;

    gettimeofday(&now, NULL);
    random_seed = now.tv_sec ^ now.tv_usec;

    /* parse options */
    while ((opt = getopt(argc, argv, "n:m:M:s:")) != EOF) {
        switch(opt) {
        case 'n': n_numbers = atoi(optarg); break;
        case 'm': min = atoi(optarg); break;
        case 'M': max = atoi(optarg); break;
        case 's': random_seed = atoi(optarg); break;
        } /* switch */
    } /* while */

    if (max < min) max = min + DEF_RANGE;

    /* first collect all integer values */
    srandom(random_seed);
    fprintf(stderr, F("random_seed: %d\n"), random_seed);
    for (i = 0; i < n_numbers; i++) {
        printf("%ld\n", random() % (max - min + 1) + min);
    } /* for */

    return EXIT_SUCCESS;
} /* main */
