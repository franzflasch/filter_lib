#include <lib_filter_fir1.h>

void filter_fir1_init(filter_fir1_t *pFilter, 
                      float *coeffs, 
                      float *buffer, 
                      unsigned int nr_taps)
{
    unsigned i = 0;
    pFilter->coeffs = coeffs;
    pFilter->buffer = buffer;
    pFilter->nr_taps = nr_taps;
    pFilter->offset = 0;

    for(i=0;i<nr_taps;i++)
    {
        pFilter->buffer[i] = 0;
    }
}


/*
 * FIR Filter using efficient pointer arithmetic techniques
 * instead of memory shifting.
 * Thankfully borrowed from https://github.com/berndporr/fir1
 *
 * */
float filter_fir1_process(filter_fir1_t *pFilter, 
                          float input)
{
    float *coeff = pFilter->coeffs;
    float *coeff_end = pFilter->coeffs + pFilter->nr_taps;

    float *buf_val = pFilter->buffer + pFilter->offset;

    float output_ = 0;

    *buf_val = input;

    while(buf_val >= pFilter->buffer)
        output_ += *buf_val-- * *coeff++;

    buf_val = pFilter->buffer + pFilter->nr_taps-1;

    while(coeff < coeff_end)
            output_ += *buf_val-- * *coeff++;

    if(++pFilter->offset >= pFilter->nr_taps)
        pFilter->offset = 0;

    return output_;
}
