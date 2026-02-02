<div align="center">

# 🖨️ ft_printf

### A custom implementation of the C standard library printf function

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge)](https://github.com/42School/norminette)

*Part of the 42 School common core curriculum*

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Function Reference](#-function-reference) • [Testing](#-testing)

</div>

---

## 📋 Table of Contents

- [About](#-about)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Supported Conversions](#-supported-conversions)
- [Function Reference](#-function-reference)
- [Project Structure](#-project-structure)
- [Implementation Details](#-implementation-details)
- [Testing](#-testing)
- [Makefile Commands](#-makefile-commands)
- [Author](#-author)

---

## 🎯 About

**ft_printf** is a recode of the standard C library function `printf()`. This project is part of the 42 School curriculum and aims to deepen understanding of variadic functions, type conversion, and formatted output in C.

The function reproduces the behavior of `printf()` with a subset of its conversion specifiers, maintaining strict compliance with 42's coding standards (Norminette).

### Why Recreate Printf?

- **Understand variadic functions**: Learn how `va_list`, `va_start`, `va_arg`, and `va_end` work
- **Master type conversions**: Handle different data types and their string representations
- **Improve C proficiency**: Write clean, efficient, and well-documented code
- **Error handling**: Manage edge cases and write return values

---

## ✨ Features

- ✅ Full implementation of core printf functionality
- ✅ Support for multiple conversion specifiers
- ✅ Proper error handling with return values
- ✅ Norminette compliant (42 coding standards)
- ✅ No memory leaks
- ✅ Handles edge cases (NULL pointers, negative numbers, etc.)
- ✅ Efficient character counting
- ✅ Modular code structure

---

## 🚀 Installation

### Prerequisites

- GCC or Clang compiler
- Make utility
- Unix-based operating system (Linux/macOS)

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/ft_printf.git
cd ft_printf

# Compile the library
make

# This creates libftprintf.a
```

---

## 💻 Usage

### Basic Example

```c
#include "ft_printf.h"

int main(void)
{
    int count;
    
    // Print a simple string
    count = ft_printf("Hello, World!\n");
    
    // Print with various conversions
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "42 School");
    ft_printf("Integer: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Pointer: %p\n", &count);
    
    return (0);
}
```

### Compilation with Your Project

```bash
# Compile your project with the library
gcc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program

# Run
./your_program
```

### Integration Example

```c
#include "ft_printf.h"

int main(void)
{
    int     number = 42;
    char    *str = "Success";
    void    *ptr = &number;
    
    ft_printf("Testing ft_printf:\n");
    ft_printf("================\n\n");
    
    // Characters
    ft_printf("Character: %c\n", 'X');
    ft_printf("Percent sign: %%\n\n");
    
    // Strings
    ft_printf("String: %s\n", str);
    ft_printf("NULL string: %s\n\n", NULL);
    
    // Integers
    ft_printf("Integer: %d\n", number);
    ft_printf("Integer (i): %i\n", number);
    ft_printf("Negative: %d\n\n", -42);
    
    // Unsigned
    ft_printf("Unsigned: %u\n", 123456);
    ft_printf("Unsigned (max): %u\n\n", -1);
    
    // Hexadecimal
    ft_printf("Hex (lowercase): %x\n", 255);
    ft_printf("Hex (uppercase): %X\n\n", 255);
    
    // Pointers
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("NULL pointer: %p\n", NULL);
    
    return (0);
}
```

---

## 🔧 Supported Conversions

| Specifier | Description | Example | Output |
|-----------|-------------|---------|--------|
| `%c` | Single character | `ft_printf("%c", 'A')` | `A` |
| `%s` | String of characters | `ft_printf("%s", "Hello")` | `Hello` |
| `%p` | Pointer address in hexadecimal | `ft_printf("%p", ptr)` | `0x7ffc1234abcd` |
| `%d` | Signed decimal integer | `ft_printf("%d", 42)` | `42` |
| `%i` | Signed decimal integer | `ft_printf("%i", -42)` | `-42` |
| `%u` | Unsigned decimal integer | `ft_printf("%u", 42)` | `42` |
| `%x` | Unsigned hexadecimal (lowercase) | `ft_printf("%x", 255)` | `ff` |
| `%X` | Unsigned hexadecimal (uppercase) | `ft_printf("%X", 255)` | `FF` |
| `%%` | Percent sign | `ft_printf("%%")` | `%` |

### Special Cases

- **NULL strings** (`%s`): Prints `(null)`
- **NULL pointers** (`%p`): Prints `(nil)`
- **Negative numbers**: Properly handled with `-` sign
- **Zero values**: Correctly displayed for all types

---

## 📚 Function Reference

### Main Function

```c
int ft_printf(const char *format, ...);
```

**Parameters:**
- `format`: Format string containing conversion specifiers

**Returns:**
- Number of characters printed (excluding null terminator)
- `-1` on error

**Description:**
Outputs a formatted string to stdout, similar to the standard `printf()` function.

---

### Utility Functions

#### Character Output
```c
int ft_putchar_count(char c);
```
Prints a single character and returns the number of characters printed.

#### String Output
```c
int ft_putstr_count(char *s);
```
Prints a string and returns the number of characters printed. Handles NULL by printing `(null)`.

#### Integer Output
```c
int ft_putnbr_int_count(long n);
```
Prints a signed integer and returns the number of characters printed.

#### Unsigned Integer Output
```c
int ft_print_unsigned(unsigned long int n);
```
Prints an unsigned integer and returns the number of characters printed.

#### Hexadecimal Output
```c
int ft_putnbr_xhex_count(unsigned long nbr, char up);
```
Prints a number in hexadecimal format. The `up` parameter determines case ('x' for lowercase, 'X' for uppercase).

#### Pointer Output
```c
int ft_print_pointer(void *p);
```
Prints a pointer address in hexadecimal format with `0x` prefix. Handles NULL pointers by printing `(nil)`.

---

## 📁 Project Structure

```
ft_printf/
│
├── ft_printf.c              # Main function and format parsing
├── ft_printf.h              # Header file with function prototypes
├── ft_printf_utils.c        # Character and string utilities
├── ft_printf_numbers.c      # Integer and unsigned number printing
├── ft_printf_hex.c          # Hexadecimal conversion
├── ft_printf_pointer.c      # Pointer address handling
├── Makefile                 # Build automation
└── README.md                # This file
```

### File Descriptions

| File | Purpose |
|------|---------|
| `ft_printf.c` | Core implementation with format string parsing |
| `ft_printf.h` | Header file with all function prototypes and includes |
| `ft_printf_utils.c` | Basic output functions for characters and strings |
| `ft_printf_numbers.c` | Handles signed and unsigned integer output |
| `ft_printf_hex.c` | Hexadecimal conversion and output |
| `ft_printf_pointer.c` | Pointer address formatting and output |
| `Makefile` | Compilation rules and project management |

---

## 🔍 Implementation Details

### Architecture

The implementation follows a modular approach:

1. **Format Parsing** (`ft_printf.c`):
   - Iterates through the format string
   - Identifies conversion specifiers
   - Dispatches to appropriate handler functions

2. **Type Handlers**:
   - Each conversion specifier has a dedicated function
   - Functions handle edge cases and return character count
   - Error handling through return values

3. **Utilities**:
   - Reusable functions for common operations
   - Character counting integrated into output functions

### Key Features

#### Variadic Arguments
```c
va_list args;
va_start(args, format);
// Extract arguments based on conversion specifier
va_end(args);
```

#### Error Handling
- All functions return `-1` on write errors
- NULL pointers handled gracefully
- Invalid format specifiers printed literally

#### Character Counting
- Every output function returns the number of characters written
- Total count accumulated and returned to caller
- Accurate count even with mixed conversion types

### Memory Management

- **No dynamic allocation**: Uses only stack variables
- **No memory leaks**: No malloc/free operations required
- **Buffer-free output**: Direct write to stdout

---

## 🧪 Testing

### Manual Testing

Create a test file `main.c`:

```c
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ft_ret, std_ret;
    
    printf("=== Testing ft_printf ===\n\n");
    
    // Test characters
    printf("--- Characters ---\n");
    ft_ret = ft_printf("ft : %c\n", 'A');
    std_ret = printf("std: %c\n", 'A');
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test strings
    printf("--- Strings ---\n");
    ft_ret = ft_printf("ft : %s\n", "Hello World");
    std_ret = printf("std: %s\n", "Hello World");
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test NULL string
    ft_ret = ft_printf("ft : %s\n", NULL);
    std_ret = printf("std: %s\n", NULL);
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test integers
    printf("--- Integers ---\n");
    ft_ret = ft_printf("ft : %d %i\n", 42, -42);
    std_ret = printf("std: %d %i\n", 42, -42);
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test limits
    ft_ret = ft_printf("ft : %d %d\n", INT_MAX, INT_MIN);
    std_ret = printf("std: %d %d\n", INT_MAX, INT_MIN);
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test unsigned
    printf("--- Unsigned ---\n");
    ft_ret = ft_printf("ft : %u\n", 4294967295U);
    std_ret = printf("std: %u\n", 4294967295U);
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test hexadecimal
    printf("--- Hexadecimal ---\n");
    ft_ret = ft_printf("ft : %x %X\n", 255, 255);
    std_ret = printf("std: %x %X\n", 255, 255);
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test pointers
    printf("--- Pointers ---\n");
    int n = 42;
    ft_ret = ft_printf("ft : %p\n", &n);
    std_ret = printf("std: %p\n", &n);
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test NULL pointer
    ft_ret = ft_printf("ft : %p\n", NULL);
    std_ret = printf("std: %p\n", NULL);
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    // Test mixed
    printf("--- Mixed ---\n");
    ft_ret = ft_printf("ft : %c %s %d %x %p %%\n", 'A', "test", 42, 255, &n);
    std_ret = printf("std: %c %s %d %x %p %%\n", 'A', "test", 42, 255, &n);
    printf("Chars: ft=%d, std=%d\n\n", ft_ret, std_ret);
    
    return (0);
}
```

Compile and run:
```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

### Automated Testing

You can use third-party testers:

- **[ft_printf_tester](https://github.com/Tripouille/printfTester)** by Tripouille
- **[printf_lover](https://github.com/charMstr/printf_lover_v2)** by charMstr
- **[francinette](https://github.com/xicodomingues/francinette)** (comprehensive 42 tester)

```bash
# Example with Tripouille's tester
git clone https://github.com/Tripouille/printfTester.git
cd printfTester
make a
```

---

## 🛠️ Makefile Commands

| Command | Description |
|---------|-------------|
| `make` | Compile the library (creates `libftprintf.a`) |
| `make all` | Same as `make` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and library |
| `make re` | Recompile everything from scratch |

### Usage Examples

```bash
# Initial compilation
make

# After modifications, recompile
make re

# Clean up build artifacts
make fclean

# Clean and rebuild
make re
```

---

## 📊 Evaluation Criteria (42 School)

- ✅ **Mandatory part**: All required conversions implemented
- ✅ **Norminette**: Code complies with 42 coding standards
- ✅ **Forbidden functions**: Only allowed functions used (`write`, `malloc`, `free`, `va_*`)
- ✅ **Memory**: No memory leaks or segmentation faults
- ✅ **Return value**: Correctly returns number of printed characters
- ✅ **Compilation**: No errors or warnings with `-Wall -Wextra -Werror`

---

## 📝 Learning Outcomes

Through this project, you will learn:

- **Variadic functions**: How to work with variable number of arguments
- **Type conversion**: Converting different data types to strings
- **String manipulation**: Building formatted output character by character
- **Low-level I/O**: Using the `write()` system call
- **Error handling**: Proper return value management
- **Code organization**: Modular programming and separation of concerns
- **Standard library internals**: How printf-like functions work under the hood

---

## 🐛 Known Limitations

This implementation covers the mandatory requirements of the 42 School project. It does **not** include:

- Field width modifiers (e.g., `%10d`)
- Precision modifiers (e.g., `%.2f`)
- Flags (e.g., `%-10s`, `%+d`, `%#x`)
- Length modifiers (e.g., `%ld`, `%hd`)
- Floating-point conversions (`%f`, `%e`, `%g`)
- Other advanced printf features

These features may be implemented in bonus sections or future versions.

---

## 🤝 Contributing

This is an educational project for 42 School. While external contributions are not accepted for the core project (as it must be individual work for evaluation), you're welcome to:

- Fork the repository for your own learning
- Report bugs or issues
- Share improvements or optimizations (after evaluation)

---

## 📄 License

This project is part of the 42 School curriculum. Feel free to use it for learning purposes, but please respect the 42 School's academic integrity policy if you're a current student.

---

## 🙏 Acknowledgments

- **42 School** for the project subject and curriculum
- **The C Programming Language** by Kernighan and Ritchie
- The 42 community for peer learning and support

---

<div align="center">

**Made with ☕ and 💻 by Fatemeh Yousefi**

*Part of the 42 School Common Core*

[↑ Back to Top](#-ft_printf)

</div>
