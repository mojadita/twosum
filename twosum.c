/* $Id$
 * Author: Luis Colorado <luiscoloradourcola@gmail.com>
 * Date: Wed Dec 14 10:01:17 EET 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include <stdarg.h>

#define F(x) __FILE__":%d:%s: " x, __LINE__, __func__
#define MAX         100000

int target = 0;
int verbose = 0;

int array[MAX];
int n_numbers = 0;

static void print_array(
        int array[], int nelem,
        int l, int r,
        const char *fmt, ...);

static int next_up(int array[], int nelem, int ix);
static int next_down(int array[], int ix);

static int fcomp(const void *_a, const void *_b);

int main(int argc, char **argv)
{
    int opt;
    int i, j, it = 0;

    /* parse options */
    while ((opt = getopt(argc, argv, "t:v")) != EOF) {
        switch(opt) {
        case 't': target = atoi(optarg); break;
        case 'v': verbose = 1; break;
        } /* switch */
    } /* while */

    while(n_numbers < MAX && scanf("%d", &array[n_numbers]) == 1)
        n_numbers++;

    if (verbose) {
        print_array(array, n_numbers, -1, -1, F("before qsort():\n"));
    }

    qsort(array, n_numbers, sizeof array[0], fcomp);

    if (verbose) {
        print_array(array, n_numbers, -1, -1, F("after qsort():\n"));
    }

    i = 0; j = n_numbers-1;
    while (i < j) {
        int sum = array[i] + array[j];
        if (verbose) {
            print_array(array, n_numbers,
                    i, j,
                    F("Iter#%03d: sum = %3d:"), ++it, sum);
        }
        if (sum < target)
            i = next_up(array, n_numbers, i);
        else if (sum > target)
            j = next_down(array, j);
        else {
            printf(F("solved for %d + %d = %d\n"),
                    array[i], array[j], sum);
            i = next_up(array, n_numbers, i);
            j = next_down(array, j);
        }
    } /* while */
} /* main */

static void print_array(
        int array[], int nelem,
        int l, int r,
        const char *fmt, ...)
{
    va_list args;
    int i;

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    for (i = 0; i < nelem; i++)
        fprintf(stderr,
                i == l ? "[%d]" : i == r ? "<%d>" : " %d ",
                array[i]);
    fprintf(stderr, "\n");
} /* print_array */

static int next_up(int array[], int nelem, int ix)
{
    int val = array[ix];
    while (ix < nelem && array[ix] == val) ix++;
    return ix;
} /* next_up */

static int next_down(int array[], int ix)
{
    int val = array[ix];
    while (ix >= 0 && array[ix] == val) ix--;
    return ix;
} /* next_down */

static int fcomp(const void *_a, const void *_b)
{
    const int *a = _a, *b = _b;
    return *a - *b;
} /* fcomp */
