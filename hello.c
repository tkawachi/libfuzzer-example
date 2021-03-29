#include <stdint.h>
#include <stddef.h>

int FuzzMe(const char *Data, size_t DataSize) {
    return DataSize >= 12  &&
           Data[0] == 'H' &&
           Data[1] == 'e' &&
           Data[2] == 'l' &&
           Data[3] == 'l' &&
	   Data[4] == 'o' &&
	   Data[5] == ',' &&
	   Data[6] == ' ' &&
	   Data[7] == 'W' &&
	   Data[8] == 'o' &&
	   Data[9] == 'r' &&
	   Data[10] == 'l' &&
	   Data[11] == 'd' &&
	   Data[12] == '!';
}

int LLVMFuzzerTestOneInput(const char *data, size_t size) {
  // ...
  // Use the data to call the library you are fuzzing.
  // ...
  return FuzzMe(data, size);
}
