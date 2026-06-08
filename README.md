# c-goto-statement-resource-cleanup
This C example demonstrates the use of the `goto` statement for centralized error handling and resource cleanup. It simulates acquiring two resources sequentially. If any resource acquisition fails, `goto` is used to jump to a common cleanup section at the end of the `main` function, ensuring that any previously acquired resources are properly rele
