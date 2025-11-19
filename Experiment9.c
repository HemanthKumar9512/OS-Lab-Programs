#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE hMapFile;
    char *data;

    // Create Shared Memory of size 1024 bytes
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,   // use paging file
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "MySharedMemory");      // shared memory name

    if (hMapFile == NULL) {
        printf("Could not create file mapping (%ld).\n", GetLastError());
        return 1;
    }

    // Map the shared memory into the process's address space
    data = (char *) MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        1024);

    if (data == NULL) {
        printf("Could not map view of file (%ld).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    // Simulate parent writing
    printf("Parent writing to shared memory...\n");
    sprintf(data, "Hello from Parent Process using Windows Shared Memory!");

    // Simulate child reading
    printf("Child reading from shared memory...\n");
    printf("Data: %s\n", data);

    // Cleanup
    UnmapViewOfFile(data);
    CloseHandle(hMapFile);

    return 0;
}
