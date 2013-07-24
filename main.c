/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <unistd.h>   /* getopt */

void usage(void);
char *prog;

int main(int argc, char **argv)
{
    int not_exceed = 4000000;
    int n,n_1 = 2, n_2 = 1;
    int sum = 0;
    int opt;

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
	    not_exceed = atoi(optarg);
	}
    }

    while ( 1 )
    {
        /* solve here */
    }
    return EXIT_SUCCESS;
}



void usage(void)
{
    printf("    http://projecteuler.net/problem=i\n");
    printf("    [Problem <i>] xxxxxxxx \n");
    printf("    \n"
           "    \n"
           "    \n\n"
    printf("    -h: show this help\n"
           "    -n <number>: solve this between 1 and not exceeding <number>\n");
    return;
}


