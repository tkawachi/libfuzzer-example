.PHONY: all clean

TARGETS = mytarget hello hello2

all: $(TARGETS)

mytarget: mytarget.c
	clang -g -O1 -fsanitize=fuzzer,address -o mytarget mytarget.c

hello: hello.c
	clang -g -O1 -fsanitize=fuzzer,address -o hello hello.c

# try: -O3
# try: objdump -S -d hello2
hello2: hello2.c
	clang -g -O1 -fsanitize=fuzzer,address -o hello2 hello2.c

clean:
	rm -f $(TARGETS) crash-*
