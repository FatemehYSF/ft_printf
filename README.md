<div align="center">

# 📚 Libft

### *Your First Custom C Library*

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge)
![Build](https://img.shields.io/badge/Build-passing-success?style=for-the-badge)

*A custom implementation of essential C standard library functions*

---

</div>

## 🎯 About The Project

**Libft** is a foundational C library that reimplements essential functions from the standard C library (`libc`). This project builds a strong understanding of basic algorithms, memory management, and C programming fundamentals — the cornerstone of every 42 student's journey.

## ✨ Features

The library includes **43 functions** organized into four categories:

<table>
<tr>
<td width="50%">

### 🔤 Character & Conversion
```c
ft_isalpha    ft_isdigit
ft_isalnum    ft_isascii
ft_isprint    ft_toupper
ft_tolower
```

### 🧮 Conversion & Output
```c
ft_atoi       ft_itoa
ft_putchar_fd ft_putstr_fd
ft_putendl_fd ft_putnbr_fd
```

</td>
<td width="50%">

### 📝 String Manipulation
```c
ft_strlen     ft_strchr
ft_strrchr    ft_strncmp
ft_strlcpy    ft_strlcat
ft_strnstr    ft_strdup
ft_substr     ft_strjoin
ft_strtrim    ft_split
ft_strmapi    ft_striteri
```

### 🧠 Memory Operations
```c
ft_memset     ft_bzero
ft_memcpy     ft_memmove
ft_memchr     ft_memcmp
ft_calloc
```

</td>
</tr>
</table>

## 🚀 Getting Started

### Compilation

```bash
# Compile the library
make

# Remove object files
make clean

# Remove object files and library
make fclean

# Recompile from scratch
make re
```

### Usage

**1.** Include the header in your C files:
```c
#include "libft.h"
```

**2.** Compile with the library:
```bash
cc your_file.c -L. -lft -o your_program
```

**3.** Example:
```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, Libft!");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

## 🛠️ Technical Specifications

| Aspect | Detail |
|--------|--------|
| **Language** | C |
| **Compiler** | cc (gcc/clang) |
| **Compilation Flags** | `-Wall -Wextra -Werror` |
| **Norm** | 42 Norminette v3 |
| **Memory** | No leaks, proper allocation/deallocation |
| **Functions** | 43 core functions |

## 📂 Project Structure

```
libft/
├── 📄 Makefile
├── 📄 libft.h
├── 📁 ft_*.c (43 function implementations)
└── 📄 README.md
```

## 💡 Key Learnings

- ✅ Deep understanding of C string and memory manipulation
- ✅ Proper memory management and leak prevention
- ✅ Implementation of complex algorithms from scratch
- ✅ Makefile creation and library compilation
- ✅ Code organization and documentation

---

<div align="center">

**Made with ☕ and 💻 by Fatemeh Yousefi**

*Part of the 42 School Common Core*

</div>
