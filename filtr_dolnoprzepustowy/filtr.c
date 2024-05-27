#include "filtr.h"

void filter_lowpass_init(lowpass_filter_t *filter)
{
	//lowpass_filter_t filter = {0};
	filter->out = 0.0f;
	filter->alpha = LOW_PASS_ALPHA;
}

int16_t filter_lowpass(int16_t new_data,  lowpass_filter_t *filter)
{

	filter->out = filter->alpha * new_data + (1.0f-filter->alpha) * filter->out;

	return filter->out;
}
