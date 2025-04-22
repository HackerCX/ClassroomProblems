#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t byte_count, size_t element_count)
{
	char *ptr = (char *)malloc(byte_count * element_count);
	if (ptr == NULL) {
		return NULL;
	}
	for (int i = 0; i < byte_count * element_count; ++i) {
		ptr[i] = 0;
	}              // memset(ptr, 0, byte_count * element_count);
	return ptr;
}

void *my_realloc(void *addr, int old_size, int new_size)
{
	char *old_addr = (char *)addr;
	if (old_size > new_size) {
		return addr;
	}
	char *ptr = (char *)malloc(new_size);
	if (ptr == NULL) {
		return NULL;
	}
	for (int i = 0; i < old_size; ++i) {
		ptr[i] = old_addr[i];   //addr[i] === *(addr + i)
	}
	free(old_addr); //free(addr)
	return ptr;
}

int main()
{
	
	return 0;
}
