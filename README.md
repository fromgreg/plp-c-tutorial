# C Tutorial: Pointers and the Consequences of Messing Up

PLP tutorial session, Wed 28.10.2026 · Gregory Frommelt

## Before the session

1. Install a C compiler, `make` and `git`. See the setup guide (PDF on Olat) for macOS, Linux and Windows (WSL).
2. Clone this repository and run the setup check:

   ```sh
   git clone https://github.com/fromgreg/plp-c-tutorial.git
   cd plp-c-tutorial
   make check
   ```

   Expected output:

   ```text
   Compiler works.
   SUMMARY: AddressSanitizer: heap-buffer-overflow check.c:16 in main
   Setup OK: compiler and AddressSanitizer work.
   ```

   The `SUMMARY` line is **good news**: `check.c` contains a deliberate bug, and the sanitizer caught it.

## Files

| File | What it is |
|------|------------|
| `login.c` | Warm-up: a tiny "login" with a suspicious `strcpy` |
| `vec.h`, `vec.c` | A growable array of ints (`Vec`), like `ArrayList` or Rust's `Vec` |
| `scores.c` | The main exercise, a high-score table built on `Vec` |
| `check.c` | Setup check only |

`make` builds every program twice:

- `build/<name>`: plain build, like most C code in the wild
- `build/<name>-asan`: the same code with AddressSanitizer and UndefinedBehaviorSanitizer, which check every memory access at runtime

## During the session

```sh
make                                   # rebuild after every change
./build/login Bob
./build/login AAAAAAAAA                # who is admin now?
./build/scores && ./build/scores-asan  # TODO 1
```

The TODOs are in `scores.c` and `vec.c`. `make clean` removes all builds.
