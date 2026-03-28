# Push Swap

## Overview

Push Swap is a sorting program that takes a list of integers as command-line arguments and sorts them using two stacks (A and B) and a limited set of stack operations. It is based on the 42 school Push_swap project, with an extended, configurable architecture and an optional benchmarking mode.

The goal is to produce a correct, stable sort while minimizing the number of operations. This implementation provides multiple strategies (simple, medium, complex, and adaptive) and gathers detailed statistics about the operations performed.

## Features

- Two-stack sorting engine using the mandatory Push_swap operations
- Multiple strategies:
	- `--simple`  – basic small-input strategy (O(n²))
	- `--medium`  – chunk-based strategy (approximately O(n√n))
	- `--complex` – normalized radix sort (O(n log n))
	- `--adaptive` – automatically picks a strategy based on input disorder
- Input parsing with validation and integer range checking
- Index compression and normalization for efficient radix sorting
- Optional benchmarking mode with detailed operation counts and complexity hints

## Project Structure

The project is organized into a simple, professional C layout:

- `include/`
	- `push_swap.h` – main public header, containing data structures, function prototypes, and configuration/benchmark types.

- `src/`
	- `push_swap.c` – program entry point, CLI flag parsing, strategy selection, and high-level control flow.

- `src/parse/`
	- `parser.c`             – argument parsing, validation, and stack construction
	- `ft_atol.c`            – robust ASCII-to-long conversion with overflow detection
	- `ft_split.c`           – string splitting helper
	- `ft_strncmp.c`         – string comparison helper
	- `index_compression.c`  – compresses integer values into dense indices for efficient sorting

- `src/ops/`
	- `push.c`          – `pa`/`pb` operations
	- `swap.c`          – `sa`/`sb`/`ss` operations
	- `rotate.c`        – `ra`/`rb`/`rr` operations
	- `reverserotate.c` – `rra`/`rrb`/`rrr` operations
	- `stack_utils.c`   – stack creation, destruction, and helper utilities

- `src/algo/`
	- `algo_simple.c`          – simple strategy for small or almost-sorted inputs
	- `algo_medium.c`          – medium complexity strategy (typically chunk-based)
	- `algo_complex.c`         – complex strategy based on radix sort
	- `adaptive.c`             – chooses strategy dynamically based on measured disorder
	- `medium_utils.c`         – helpers used by the medium strategy
	- `complex_index.c`        – helpers for index calculations in complex strategy
	- `sort_one_three_five.c`  – specialized routines for very small stack sizes (1, 3, 5)
	- `disorder.c`             – computes a normalized “disorder” metric of stack A

- `src/bench/`
	- `benchmark.c`        – prints high-level benchmark results and complexity hints
	- `benchmark_utils.c`  – initializes and updates operation counters

## Building

Requirements:

- A C compiler (tested with `gcc`)

To build the main executable:

```sh
make
```

This produces the `push_swap` binary in the project root and object files under `obj/`.

For a debug build with debug symbols and no optimization:

```sh
make debug
```

To clean object files:

```sh
make clean
```

To remove binaries and object files:

```sh
make fclean
```

To rebuild from scratch:

```sh
make re
```

## Usage

Basic usage (auto strategy, no benchmarking):

```sh
./push_swap 2 1 3 6 5 8
```

The program writes a sequence of operations to standard output that, when applied to the initial stack A, produce a sorted ascending sequence.

### Strategies

You can explicitly select a strategy with flags before the numeric arguments:

- `--simple`  – use the simple strategy
- `--medium`  – use the medium strategy
- `--complex` – use the complex strategy
- `--adaptive` – (default) choose a strategy automatically based on the input disorder

Examples:

```sh
./push_swap --simple 4 3 2 1
./push_swap --complex 3 2 5 1 4 0
./push_swap --adaptive 3 2 5 1 4 0
```

### Benchmark Mode

The `--bench` flag enables benchmarking. When enabled, the program prints a detailed summary of the run to standard output after sorting:

- total number of operations
- per-operation counts (sa, sb, pa, pb, ra, rb, etc.)
- measured input disorder
- chosen strategy and an indicative time complexity

Example:

```sh
./push_swap --bench --adaptive 3 2 5 1 4 0
```

## Error Handling

The program validates input and will exit with an error in cases such as:

- non-integer arguments
- integer overflow/underflow
- duplicate values

On invalid input, it writes `Error` to standard error and stops without printing any operations.

## Notes

- The project is written in C and follows the constraints of the 42 Push_swap project while adding a richer architecture and benchmarking tools.
- The layout is designed to be easy to navigate and extend: parsing, operations, algorithms, and benchmarking are clearly separated.
