#include "stdio.h"
#include "errno.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "pthread.h"
#include "time.h"

#define BUFFERSIZE 1024

void* pointer_example(void* args);
void array_example(void);
void struct_example(void);
