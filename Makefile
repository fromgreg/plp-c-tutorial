# macOS enables _FORTIFY_SOURCE by default, which aborts the strcpy overflow
# in login.c before we can see it. Turned off so plain C behaves the same
# everywhere.
CFLAGS = -std=c11 -Wall -Wextra -g -O0 -D_FORTIFY_SOURCE=0
ASAN   = -fsanitize=address,undefined -fno-omit-frame-pointer

PROGS = check login scores
BINS  = $(PROGS:%=build/%) $(PROGS:%=build/%-asan)

all: $(BINS)

build:
	mkdir -p build

# scores also needs vec.c
build/scores-asan: scores.c vec.c vec.h | build
	$(CC) $(CFLAGS) $(ASAN) -o $@ scores.c vec.c
build/scores: scores.c vec.c vec.h | build
	$(CC) $(CFLAGS) -o $@ scores.c vec.c

# -asan rule must come first: macOS ships GNU make 3.81, which takes the
# first matching pattern instead of the most specific one
build/%-asan: %.c | build
	$(CC) $(CFLAGS) $(ASAN) -o $@ $<
build/%: %.c | build
	$(CC) $(CFLAGS) -o $@ $<

# Verifies the setup: compiler + AddressSanitizer
check: build/check build/check-asan
	@./build/check
	@if ASAN_OPTIONS=abort_on_error=0 ./build/check-asan 2> build/check-asan.log; then \
		echo "PROBLEM: AddressSanitizer did not catch the bug. See the setup guide."; \
		exit 1; \
	else \
		grep -m1 'SUMMARY' build/check-asan.log; \
		echo "Setup OK: compiler and AddressSanitizer work."; \
	fi

clean:
	rm -rf build

.PHONY: all check clean
