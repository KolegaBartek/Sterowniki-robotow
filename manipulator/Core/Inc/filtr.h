#ifndef __filtr_H
#define __filtr_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stdint.h"
#include "filtr_struct.h"

#define LOW_PASS_ALPHA	(0.05f)

// lowpass_filter_t filter;

void filter_lowpass_init(lowpass_filter_t *filter);
int16_t filter_lowpass(int16_t new_data,  lowpass_filter_t *filter);

#ifdef __cplusplus
}
#endif
#endif /*__ tim_H */
