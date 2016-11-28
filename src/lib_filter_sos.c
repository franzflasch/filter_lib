#include <lib_filter_sos.h>

void filter_iir_dir_form2_get_coeffs(filter_sos_dir_form2_t *pFilter,
                                     filter_sos_section_coeffs_t *NUM,
                                     filter_sos_section_coeffs_t *DEN,
                                     unsigned int sectionNr)
{
    /* Get the filter coefficients NUMERATOR */
    pFilter->b = &NUM[sectionNr];
    /* Get the filter coefficients DENUMINATOR */
    pFilter->a = &DEN[sectionNr];

    /* Now set the storages to zero */
    pFilter->w[0] = pFilter->w[1] = pFilter->w[2] = 0;
}

void filter_iir_dir_form2_init_sections(filter_sos_dir_form2_t *pFilter,
                                        filter_sos_section_coeffs_t *numerator,
                                        filter_sos_section_coeffs_t *denominator,
                                        unsigned int nrSections)
{
    unsigned int i = 0;

    for(i=0;i<nrSections;i++)
    {
        filter_iir_dir_form2_get_coeffs(&pFilter[i], &numerator[0], &denominator[0], i);
    }
}

float filter_iir_dir_form2_process_one_section(filter_sos_dir_form2_t *pFilter, 
                                               float input)
{
    /* Shift values */
    pFilter->w[2] = pFilter->w[1];
    pFilter->w[1] = pFilter->w[0];

    pFilter->w[0] = (input)-(pFilter->a->coeff1*(pFilter->w[1])) - (pFilter->a->coeff2*pFilter->w[2]);
    return ((pFilter->b->coeff0*pFilter->w[0]) + (pFilter->b->coeff1*pFilter->w[1]) + (pFilter->b->coeff2*pFilter->w[2]));
}

float filter_iir_dir_form2_process_combined_sections(filter_sos_dir_form2_t *pFilter, 
                                                     float input, 
                                                     unsigned int nrSections)
{
    float tmpValue = input;
    unsigned int i = 0;

    tmpValue = filter_iir_dir_form2_process_one_section(&pFilter[0], tmpValue);
    for(i=1;i<(nrSections);i++)
    {
        tmpValue = filter_iir_dir_form2_process_one_section(&pFilter[i], tmpValue);
    }

    return tmpValue;
}
