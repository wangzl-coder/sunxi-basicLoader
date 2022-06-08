#ifndef __EXTRA_STRING_H__
#define __EXTRA_STRING_H__

#define NULL 0

void *memset(void *s, int val, unsigned int count);

void *memcpy(void *dest, const void *src, unsigned int count);

int strncmp(const char *src1, const char *src2, unsigned int count);

char *strcpy(char *dest, const char *src);

#endif
