[![42](https://img.shields.io/badge/-Project-black?logo=42&logoColor=white)](https://42.fr/)
![C](https://img.shields.io/badge/Language-%2300599C.svg?logo=c&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?logo=linux&logoColor=black)


# ft_ls - `ls` Command Reimplementation

Re-implementation of the Unix `ls` command in C as part of the 42 School curriculum.  
This project focuses on interacting with the file system at a low level by recreating the behavior of `ls` along with several of its common options.

## Project Overview

- **Language:** C
- **Purpose:** Rebuild the core functionality of the `ls` command, gaining experience in system calls, directory traversal, file metadata handling, and structured command-line tools.
- **Focus:**
  - Directory manipulation
  - File permissions, ownership, timestamps, and sizes
  - Command-line argument parsing
  - Recursive directory traversal
- [Original task (french)](static/ft_ls.fr.pdf)

## Features

### Supported Options:
- `-l` — Long format listing (detailed file info)
- `-R` — Recursive directory traversal
- `-a` — Show hidden files
- `-r` — Reverse order
- `-t` — Sort by modification time

### Requirements:
- Mimic the behavior of the system’s `ls` command as closely as possible within the scope of these options.
- Handle errors gracefully and without crashes.
- Ensure no memory leaks.
- Comply with 42 School’s coding standard (Norme).

## Allowed System Functions
- `write`, `opendir`, `readdir`, `closedir`, `stat`, `lstat`
- `getpwuid`, `getgrgid`, `listxattr`, `getxattr`, `time`, `ctime`
- `readlink`, `malloc`, `free`, `perror`, `strerror`, `exit`

## Compilation

```bash
make
```

### Makefile Targets

| Target   | Description                     |
|----------|---------------------------------|
| `all`    | Build the project                |
| `clean`  | Remove object files              |
| `fclean` | Remove object files and binary   |
| `re`     | Rebuild the project from scratch |

## Notes
- The project is designed to be a practical introduction to system-level file operations in C.
- Efficiency and structured design are key aspects of this project.
- Bonus options such as color output, additional flags, and optimization may also be implemented after completing mandatory requirements.

## License
This project is developed for educational purposes as part of the 42 School program.
