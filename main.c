/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <unistd.h>   /* getopt */

void usage(void);
char *prog;

int main(int argc, char **argv)
{
    unsigned long long int digits = 3UL;
    unsigned long long int max,min;
    unsigned long long int l,r, cur;
    int opt;
    char *p;
    
    prog = argv[0];

    while ( -1 != (opt = getopt(argc, argv, "hn:")) )
    {
        if('h' == opt)
	{
            usage();
            exit(EXIT_SUCCESS);
	}
        else if ('n' == opt)
        {
            digits = strtoull(optarg, &p, 0);
        }
    }
    
    printf("getting Largest palindrome product in %llu digits...\n", digits);

    max = 10 ^ digits -1;


solved:
    printf("largest cur: %llu = %llu x %llu\n", cur, l,r);

    return EXIT_SUCCESS;
}



void usage(void)
{
    printf("    http://projecteuler.net/problem=4\n");
    printf("    [Problem 4] Largest palindrome product\n");
    printf("    A palindromic number reads the same both ways.\n"
           "    The largest palindrome made from the product of\n\n"
           "    two 2-digit numbers is 9009 = 91 × 99.\n"
           "    Find the largest palindrome made from \n"
           "    the product of two 3-digit numbers.\n\n");
    printf("    -h: show this help\n"
           "    -n <number>: solve this with <number>\n");
    return;
}


