/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <string.h>   /* strlen  */
#include <unistd.h>   /* getopt */

/**
 * @file
 * @addtogroup  EULER_004  Euler_004_largetst_palindrome_product
 * @{
 */

void usage(void);
int check(unsigned long long int cur);

/**
 * @brief check() checks if cur is a palindrome.
 * @param cur a number to check
 * @return 1:is palindrome, or 0:not
 */
int check(unsigned long long int cur)
{
#define BUFF_SIZE   128
	
    char buff[BUFF_SIZE], reverse[BUFF_SIZE];
    size_t len;
    unsigned int i;

    snprintf(buff, BUFF_SIZE, "%llu", cur);
    len = strlen(buff);
    for ( i = 0 ; i < len ; i++ )
        reverse[i] = buff[len - i - 1];

    return (0 == strncmp(buff, reverse, len));
}

/**
 * @brief Largest palindrome product
 * 
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv)
{
    unsigned long long int max,min;
    unsigned long long int l,r;
    unsigned long long int answer = 0, l_answer, r_answer;
    int opt, all = 0;
    char *p;
    
    max = 999;
    min = 100;

    while ( -1 != (opt = getopt(argc, argv, "ahn:")) )
    {
        if('h' == opt)
        {
            usage();
            exit(EXIT_SUCCESS);
        }
        else if ('n' == opt)
        {
            max = strtoull(optarg, &p, 0);
        }
        else if ('a' == opt)
        {
            all = 1;
        }
    }
    
    printf("getting Largest palindrome product in %llu ...\n", max);

    for (l = max, r = max ; min < l ; l--)
    {
        if ( answer > (l*l) ) break;
        for ( r = l ; min <= r ; r--)
        {
            unsigned long long int cur = l*r;
            if (check(cur))
            {
                if (all) printf("cur: %llu = %llu x %llu\n", cur, l, r);
                if (answer < cur) 
                {
                    answer = cur;
                    l_answer = l;
                    r_answer = r;
                    printf("answer updated: %llu = %llu x %llu\n", cur, l, r);
                } 
            }
            else
            {
                if (all) printf("not: %llu = %llu x %llu\n", l*r, l, r);                     
            }
        }
    }
    
    printf("largest answer: %llu = %llu x %llu\n", answer, l_answer, r_answer);
    return EXIT_SUCCESS;
}


/**
 * @brief show help
 */
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
           "    -n <number>: solve this with max <number>\n");
    return;
}

/**
 * @}
 */

