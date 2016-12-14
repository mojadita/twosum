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

int random_seed = 1;
int n_numbers = 10;
int min = 0;
int max = 100;

int main(int argc, char **argv)
{
    int opt;
    int i, j;
    struct timeval now;

    gettimeofday(&now, NULL);
    random_seed = now.tv_sec ^ now.tv_usec;

    /* parse options */
    while ((opt = getopt(argc, argv, "n:m:s:")) != EOF) {
        switch(opt) {
        case 'n': n_numbers = atoi(optarg); break;
        case 'm': min = atoi(optarg); break;
        case 'M': max = atoi(optarg); break;
        case 's': random_seed = atoi(optarg); break;
        } /* switch */
    } /* while */

    /* first collect all integer values */
    srandom(random_seed);
    fprintf(stderr, F("random_seed: %d\n"), random_seed);
    for (i = 0; i < n_numbers; i++) {
        printf("%ld\n", random() % (max - min) + min);
    } /* for */

    return EXIT_SUCCESS;
} /* main */
