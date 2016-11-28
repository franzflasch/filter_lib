#ifndef LIB_FILTER_SOS_H
#define LIB_FILTER_SOS_H

typedef struct filter_sos_section_coeffs_s
{
    float coeff0;
    float coeff1;
    float coeff2;

}filter_sos_section_coeffs_t;

typedef struct filter_sos_dir_form2_s
{
    /* SOS relevant */
    filter_sos_section_coeffs_t *b; /* numerator coefficients */
    filter_sos_section_coeffs_t *a; /* denuminator coefficients */
    float w[3]; /* storages */

}filter_sos_dir_form2_t;

void filter_iir_dir_form2_get_coeffs(filter_sos_dir_form2_t *pFilter,
                                     filter_sos_section_coeffs_t *NUM,
                                     filter_sos_section_coeffs_t *DEN,
                                     unsigned int sectionNr);

void filter_iir_dir_form2_init_sections(filter_sos_dir_form2_t *pFilter,
                                        filter_sos_section_coeffs_t *numerator,
                                        filter_sos_section_coeffs_t *denominator,
                                        unsigned int nrSections);

float filter_iir_dir_form2_process_one_section(filter_sos_dir_form2_t *pFilter, 
                                               float input);

float filter_iir_dir_form2_process_combined_sections(filter_sos_dir_form2_t *pFilter, 
                                                     float input, 
                                                     unsigned int nrSections);

#endif  /* LIB_FILTER_SOS_H */
