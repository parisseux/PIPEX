File Handling

    open: Opens a file and returns a file descriptor. It allows specifying read/write modes and file creation permissions.
    close: Closes an open file descriptor, freeing system resources.
    read: Reads data from a file descriptor into a buffer.

Error Handling

    perror: Prints an error message to stderr, followed by a description of the last encountered system error.
    strerror: Returns a string describing an error code (useful for custom error messages).

File Permissions

    access: Checks whether a file exists and if the calling process has the required permissions (e.g., read, write, execute).

File Descriptor Management

    dup: Duplicates a file descriptor, returning a new one pointing to the same file.
    dup2: Duplicates a file descriptor but allows specifying the destination descriptor.

Process Execution

    execve: Replaces the current process image with a new program. It does not return on success.

Process Control

    exit: Terminates the calling process and returns an exit status.
    fork: Creates a new child process by duplicating the current process.

Inter-Process Communication

    pipe: Creates a unidirectional communication channel between processes, returning two file descriptors (one for reading, one for writing).

File Removal

    unlink: Deletes a file from the filesystem.

Process Synchronization

    wait: Suspends execution until a child process terminates, preventing zombies.
    waitpid: Similar to wait, but allows specifying which child process to wait for and additional options.
