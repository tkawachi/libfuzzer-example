#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>


int FuzzMe(const char *Data, size_t DataSize) {
    const char * hello = "Hello, World!";
    size_t hello_len = strlen(hello);
    int i;
    for (i = 0; i < hello_len && i < DataSize; i++) {
        if (Data[i] != hello[i]) {
            return 1;
        }
    }
    if (hello_len == DataSize) {
        printf("%d\n", Data[DataSize]); // <- HERE!
    }
    return 0;
}

int LLVMFuzzerTestOneInput(const char *data, size_t size) {
  // ...
  // Use the data to call the library you are fuzzing.
  // ...
  return FuzzMe(data, size);
}
