#include "extra_string.h"


void *memcpy(void *dest, const void *src, unsigned int count)
{
	char *tmp_dest = NULL;
	const char *tmp_src = NULL;
	if(dest == NULL || src == NULL)
		return NULL;
	tmp_dest= (char*) dest;
	tmp_src = (const char*) src;
	while(count--)
		*tmp_dest++ = *tmp_src++;
	
	return dest;
}
