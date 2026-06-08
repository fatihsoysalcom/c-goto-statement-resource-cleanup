#include <stdio.h>
#include <stdlib.h> // Not strictly needed for this example, but common for C programs

// A helper function to simulate acquiring a resource.
// It returns 0 on success and -1 on failure.
int acquire_resource(const char* resource_name, int should_fail) {
    printf("Attempting to acquire %s...\n", resource_name);
    if (should_fail) {
        printf("  %s acquisition FAILED!\n", resource_name);
        return -1; // Indicate failure
    }
    printf("  %s acquired successfully.\n", resource_name);
    return 0; // Indicate success
}

// A helper function to simulate releasing a resource.
void release_resource(const char* resource_name) {
    printf("  Releasing %s.\n", resource_name);
}

int main() {
    int res1_acquired = 0; // Flag to track if Resource 1 was acquired
    int res2_acquired = 0; // Flag to track if Resource 2 was acquired
    int status = 0;        // Overall program status: 0 for success, -1 for error

    printf("--- Program Start ---\n\n");

    // --- Operation 1: Acquire Resource 1 ---
    // Change the second argument of acquire_resource() to 1 to simulate a failure here.
    if (acquire_resource("Resource 1", 0) != 0) {
        status = -1;
        goto cleanup; // If Resource 1 acquisition fails, jump directly to cleanup
    }
    res1_acquired = 1; // Mark Resource 1 as acquired

    // --- Operation 2: Acquire Resource 2 ---
    // Change the second argument of acquire_resource() to 1 to simulate a failure here.
    if (acquire_resource("Resource 2", 0) != 0) {
        status = -1;
        goto cleanup; // If Resource 2 acquisition fails, jump directly to cleanup
    }
    res2_acquired = 1; // Mark Resource 2 as acquired

    // --- Main Task ---
    printf("\nAll resources acquired. Performing main task...\n");
    printf("Main task completed successfully.\n");
    printf("Proceeding to cleanup.\n\n");

cleanup: // This is the label that 'goto' statements jump to
    printf("--- Cleanup Section ---\n");
    // Resources are released in reverse order of acquisition to ensure proper dependency handling.
    if (res2_acquired) {
        release_resource("Resource 2"); // Clean up Resource 2 if it was acquired
    }
    if (res1_acquired) {
        release_resource("Resource 1"); // Clean up Resource 1 if it was acquired
    }

    printf("\n--- Program End ---\n");
    if (status == 0) {
        printf("Program finished successfully.\n");
    } else {
        printf("Program finished with errors.\n");
    }

    return status; // Return the overall program status
}
