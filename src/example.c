#include <lib_filter_sos.h>

#define FILTER_INPUT_GAIN 0.0012825810789607

static filter_sos_section_coeffs_t Bs[] = { 
{ 1.0000000000000000, 2.0015406924366763, 1.0015415987398109 },
{ 1.0000000000000000, 1.9994121525267059, 0.9994130598292462 },
{ 1.0000000000000000, 0.9990471550366238, -0.0000000000000000 }
};

static filter_sos_section_coeffs_t As[] = { 
 {1.0000000000000000, -1.0965794655679586, 0.3554467621723845 },
 {1.0000000000000000, -1.3693171946832838, 0.6925691353878609 },
 {1.0000000000000000, -0.5095254494944407, 0.0000000000000000 }
};

#define GET_FILTER_SOS_SECTION_SIZE (sizeof(Bs) / sizeof(Bs[0]))

int main(void)
{
	int i = 0;

	filter_sos_dir_form2_t test_filter[GET_FILTER_SOS_SECTION_SIZE];

	/* print step response */
	printf("Step response: \n");
	filter_iir_dir_form2_init_sections(test_filter, Bs, As, GET_FILTER_SOS_SECTION_SIZE);
	for(i=0;i<150;i++)
	{
		printf("%d: %5.16f\n", i, filter_iir_dir_form2_process_combined_sections(test_filter, (1*FILTER_INPUT_GAIN), GET_FILTER_SOS_SECTION_SIZE));
	}

	/* print impulse response */
	printf("Impulse response: \n");
	filter_iir_dir_form2_init_sections(test_filter, Bs, As, GET_FILTER_SOS_SECTION_SIZE);
	for(i=0;i<1;i++)
	{
		printf("%d: %5.16f\n", i, filter_iir_dir_form2_process_combined_sections(test_filter, (1*FILTER_INPUT_GAIN), GET_FILTER_SOS_SECTION_SIZE));
	}
	for(i=0;i<(150-1);i++)
	{
		printf("%d: %5.16f\n", i, filter_iir_dir_form2_process_combined_sections(test_filter, 0, GET_FILTER_SOS_SECTION_SIZE));
	}

	return EXIT_SUCCESS;
}
