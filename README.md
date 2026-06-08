# C Goto Statement Resource Cleanup

This C example demonstrates the use of the `goto` statement for centralized error handling and resource cleanup. It simulates acquiring two resources sequentially. If any resource acquisition fails, `goto` is used to jump to a common cleanup section at the end of the `main` function, ensuring that any previously acquired resources are properly released.

## Language

`c`

## How to Run

1. Save the code as `main.c`.
2. Compile using a C compiler (e.g., GCC): `gcc main.c -o main`
3. Run the executable: `./main`

To observe error handling, modify the `acquire_resource` calls in `main.c` to pass `1` as the second argument (e.g., `acquire_resource("Resource 1", 1)`) to simulate a failure.

## Original Article

This example accompanies the Turkish article: [C/C++'ta Goto: Kontrol Akışının Gizli Silahı](https://fatihsoysal.com/blog/c-cta-goto-kontrol-akisinin-gizli-silahi/).

## License

MIT — see [LICENSE](LICENSE).
