# 📘 mtool.h

[Русская версия](README.ru.md)

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen?style=for-the-badge)](https://github.com/DevidCopperfild/mtool.h) [![License](https://img.shields.io/badge/license-MIT-blue?style=for-the-badge)](LICENSE)

**mtool.h** is an educational C library created as a lightweight alternative to standard libraries like `ctype.h`, `string.h`, `stdio.h`, and `math.h`.

This project was created for educational purposes: to show how you can **independently implement** basic functions for working with characters, strings, and input/output. It helps to deepen the understanding of the C language fundamentals and the principles of standard libraries.

---

## 📑 Table of Contents

- [✨ Features](#-features)
- [📦 Installation](#-installation)
- [🚀 Usage](#-usage)
- [🗺️ Roadmap](#️-roadmap)
- [🤝 Contributing](#-contributing)
- [📜 License](#-license)
- [👨‍💻 Author](#-author)

---

## ✨ Features

The following modules are currently implemented:

### 🔤 `ctype` Module
Character checking and conversion functions (a complete analog of `ctype.h`, but with the `m_` prefix):

- `m_isalnum(int c)` - checks if a character is alphanumeric
- `m_isalpha(int c)` - checks if a character is alphabetic
- `m_iscntrl(int c)` - checks if a character is a control character
- `m_isdigit(int c)` - checks if a character is a digit
- `m_isgraph(int c)` - checks if a character is a printable character except for space
- `m_islower(int c)` - checks if a character is a lowercase letter
- `m_isupper(int c)` - checks if a character is an uppercase letter
- `m_isprint(int c)` - checks if a character is a printable character (including space)
- `m_ispunct(int c)` - checks if a character is a punctuation mark
- `m_isspace(int c)` - checks if a character is a whitespace character
- `m_isxdigit(int c)` - checks if a character is a hexadecimal digit
- `m_tolower(int c)` - converts a character to lowercase
- `m_toupper(int c)` - converts a character to uppercase

### 🖨️ `printf` Module
- `m_mprintf(const char *fmt, ...)` - a custom implementation of a simplified `printf`.

### 📥 `input` Module
- `m_get_double()` - reads a floating-point number
- `m_get_string()` - reads a string with dynamic memory allocation
- `m_get_int()` - reads an integer
- `string` - a new data type, an analog of `char x[n]`, that automatically calculates the string length

---

## 📦 Installation

### macOS and Linux

For macOS and Linux, you can use the provided `Makefile` to easily build and install the library.

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/DevidCopperfild/mtool.h.git
    cd mtool.h
    ```

2.  **Build the library:**
    This command compiles the source code and creates both a static (`libmtool.a`) and a shared library (`libmtool.dylib` on macOS or `libmtool.so` on Linux).
    ```bash
    make
    ```

3.  **Install the library:**
    This command copies the header file and the libraries to a standard system location (`/usr/local/include` and `/usr/local/lib`). You may be prompted for your password.
    ```bash
    sudo make install
    ```

4.  **(Optional) Uninstall the library:**
    If you need to remove the library from your system, you can use:
    ```bash
    sudo make uninstall
    ```

### Windows

For Windows, it is recommended to use the **MinGW-w64** compiler to build the library.

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/DevidCopperfild/mtool.h.git
    cd mtool.h
    ```

2.  **Build the libraries:**
    Open a terminal (like Git Bash or Command Prompt) and run the following commands to create the object file, static library, and shared library (DLL).
    ```bash
    # Compile the source code into an object file
    gcc -c src/mtool.c -o mtool.o

    # Create the static library (.a)
    ar rcs libmtool.a mtool.o

    # Create the shared library (.dll)
    gcc -shared -o libmtool.dll mtool.o
    ```

3.  **Manual Installation:**
    After building, you need to place the files in a location where your compiler can find them.
    -   Copy `src/mtool.h` to your compiler's `include` directory (e.g., `C:\MinGW\include`).
    -   Copy `libmtool.a` and `libmtool.dll` to your compiler's `lib` directory (e.g., `C:\MinGW\lib`).

---

## 🚀 Usage

Here is an example program:

```c
#include <mtool.h>
#include <stdio.h>

int main(void) {
    printf("isupper(A) = %d\n", m_isupper('A'));
    printf("tolower(Z) = %c\n", m_tolower('Z'));
    return 0;
}
```

Compile and run:

```bash
gcc main.c -o main -lmtool
./main
```

Expected output:

```text
isupper(A) = 1
tolower(Z) = z
```

---

## 🗺️ Roadmap

- **Math functions**: Implementation of `m_sin`, `m_cos`, `m_pow`, `m_sqrt`.
- **Extend `m_mprintf`**: Add support for `%f`, `%x`, and other formats.
- **File operations**: Functions for reading and writing files.

---

## 🤝 Contributing

We welcome any contributions to the project! If you want to help, please read the [contribution guidelines](CONTRIBUTING.md). You can:

- Report a bug by creating an **Issue**.
- Suggest a new feature.
- Submit a **Pull Request** with improvements.

---

## 📜 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Author

- **Developer**: Devid Copperfild
- **GitHub**: [@DevidCopperfild](https://github.com/DevidCopperfild)

