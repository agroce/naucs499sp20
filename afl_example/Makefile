all: *.c *.h
	clang -o pbuffer pbuffer_afl.c pbuffer.c
	afl-clang -o pbuffer_afl pbuffer_afl.c pbuffer.c
	clang++ -o pbuffer_libfuzzer pbuffer_libfuzzer.cpp pbuffer.c -fsanitize=fuzzer
