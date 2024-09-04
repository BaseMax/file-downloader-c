# File Downloader in C

This repository contains a simple C program designed to download files over an HTTP connection. The program can handle both text and binary files, saving them to your local system.

## Features

- Supports HTTP: This program works with HTTP, connecting to the specified server to download the requested file.
- Binary and Text File Support: The downloader can handle both text and binary files, ensuring the contents are saved accurately to your local machine.
- Simple and Lightweight: With minimal dependencies and straightforward code, this program is easy to compile and use on various systems.

## Limitations

- No HTTPS Support: The program currently does not support HTTPS. It only works with plain HTTP connections.
- Basic Error Handling: While the program includes some basic error handling (e.g., for connection issues), it does not cover all edge cases.

## Requirements

- A C compiler (e.g., GCC)
- Basic knowledge of C programming
- A working network connection

## Building the Program

To compile the program, use the following command:

```bash
gcc -o file-downloader file-downloader.c
```

This command will generate an executable named file-downloader.

## Usage

To download a file, run the compiled program. It will download the file from the specified server and path and save it as downloaded_file.txt in the current directory.

By default, the program is set to download a file from example.com. You can modify the hostname and path variables in the code to download different files.

## Example

The program is configured by default to download `downloaded_file.txt` from `example.com`. After compiling the program, simply run:

```bash
./file-downloader
```

The downloaded file will be saved as downloaded_file.txt.

## Customization

To download different files or from different servers, change the following variables in the source code:

- `hostname`: The server's hostname (e.g., "example.com")
- `path`: The path to the file on the server (e.g., "/file.txt")

### Contributing

If you'd like to contribute to this project, feel free to open issues or submit pull requests. Contributions that improve error handling, add HTTPS support, or enhance other features are especially welcome.

### License

This project is open-source and available under the GPL-3.0 License. See the LICENSE file for more details.

Copyright 2024, Max Base
