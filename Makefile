fuzz-mytarget: mytarget.c
	clang -g -O1 -fsanitize=fuzzer,address -o fuzz-mytarget mytarget.c

clean:
	@rm fuzz-mytarget
