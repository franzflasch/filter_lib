#include <stdio.h>
#include <stdlib.h>
#include <lib_filter_fir1.h>


float coeffs[] = {
0.0006642371575763,
-0.0000817459540131,
-0.0009889492157501,
-0.0016239639185902,
-0.0013720470679763,
0.0001640761697523,
0.0025656868875400,
0.0043638820227005,
0.0036835225568181,
-0.0003363996973330,
-0.0062464116828806,
-0.0103214870670438,
-0.0084999042294149,
0.0005560859982891,
0.0132533530425832,
0.0217275524034229,
0.0179073618731208,
-0.0007687876167922,
-0.0273889475086314,
-0.0464769807638711,
-0.0404669623096757,
0.0009218850141372,
0.0733396084111554,
0.1570041193505493,
0.2237894638433736,
0.2492635046019078,
0.2237894638433736,
0.1570041193505493,
0.0733396084111554,
0.0009218850141372,
-0.0404669623096757,
-0.0464769807638711,
-0.0273889475086314,
-0.0007687876167922,
0.0179073618731208,
0.0217275524034230,
0.0132533530425832,
0.0005560859982891,
-0.0084999042294149,
-0.0103214870670438,
-0.0062464116828806,
-0.0003363996973330,
0.0036835225568181,
0.0043638820227005,
0.0025656868875400,
0.0001640761697523,
-0.0013720470679763,
-0.0016239639185902,
-0.0009889492157501,
-0.0000817459540131,
0.0006642371575763,
};

#define NR_TAPS 51


int main(void)
{
    int i = 0;

    filter_fir1_t fir_test;
    float buffer[NR_TAPS];

    printf("Step response: \n");
    filter_fir1_init(&fir_test, coeffs, buffer, NR_TAPS);
    for(i=0;i<150;i++)
    {
        printf("%d: %5.16f\n", i, filter_fir1_process(&fir_test, 1));
    }

    /* print impulse response */
    printf("Impulse response: \n");
    filter_fir1_init(&fir_test, coeffs, buffer, NR_TAPS);
    for(i=0;i<1;i++)
    {
        printf("%d: %5.16f\n", i, filter_fir1_process(&fir_test, 1));
    }
    for(i=0;i<(150-1);i++)
    {
        printf("%d: %5.16f\n", i, filter_fir1_process(&fir_test, 0));
    }

    return 0;
}
