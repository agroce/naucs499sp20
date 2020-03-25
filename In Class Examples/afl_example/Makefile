all: *.c *.h
	clang -o pbuffer pbuffer_afl.c pbuffer.c
	clang -o hard_pbuffer pbuffer_afl.c hard_pbuffer.c
	afl-clang -o pbuffer_afl pbuffer_afl.c pbuffer.c
	afl-clang -o hard_pbuffer_afl pbuffer_afl.c hard_pbuffer.c
	clang++ -o pbuffer_libfuzzer pbuffer_libfuzzer.cpp pbuffer.c -fsanitize=fuzzer
	clang++ -o hard_pbuffer_libfuzzer pbuffer_libfuzzer.cpp hard_pbuffer.c -fsanitize=fuzzer
