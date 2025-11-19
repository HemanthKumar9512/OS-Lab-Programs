#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int source, dest;
    char buffer[1024];
    int bytes;

    // Open source file (read-only)
    source = open("input.txt", O_RDONLY);

    if (source < 0) {
        printf("Cannot open source file\n");
        return 1;
    }

    // Open/create destination file (write-only | create if not exists | overwrite)
    dest = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest < 0) {
        printf("Cannot open/create destination file\n");
        close(source);
        return 1;
    }

    // Read from source and write to destination
    while ((bytes = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    // Close both files
    close(source);
    close(dest);

    printf("File copied successfully.\n");

    return 0;
}
