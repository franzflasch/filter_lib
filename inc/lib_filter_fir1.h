#ifndef LIB_FILTER_FIR1_H
#define LIB_FILTER_FIR1_H

typedef struct filter_fir1_s
{
    float *coeffs;
    float *buffer;
    unsigned int nr_taps;
    unsigned int offset;
}filter_fir1_t;

void filter_fir1_init(filter_fir1_t *pFilter, 
                      float *coeffs, 
                      float *buffer, 
                      unsigned int nr_taps);

float filter_fir1_process(filter_fir1_t *pFilter, 
                          float input);

#endif /* LIB_FILTER_FIR1_H */
