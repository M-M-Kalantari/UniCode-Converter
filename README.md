# Unicode Converter (C++)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-informational)
![App Type](https://img.shields.io/badge/App-Console-success)

---

## 📌 Overview

**Unicode Converter** is a console-based C++ application that converts text characters into their numeric representations using different encoding standards and output formats.

This project is designed for educational and practical purposes to help developers understand how characters are internally represented across various encoding systems.

---

## ✨ Features

- Language selection:
  - English
  - Persian (Unicode-based)
- Encoding standards:
  - ASCII
  - Extended ASCII
  - Unicode
- UTF encodings:
  - UTF-8
  - UTF-16
  - UTF-32
- Output formats:
  - Decimal
  - Binary
  - Hexadecimal
- Program modes:
  - Custom text input
  - All supported characters
  - Sample predefined text
- Rerun with same settings or full reselect

---

## 🛠 Requirements

- **Operating System:** Windows
- **Compiler:** `g++` (MinGW / MSYS2)

### Install MSYS2

Download and install from: 
https://www.msys2.org/

After installation, make sure `g++` is added to your system `PATH`.

You can verify by running:
```bash
g++ --version
```

## ▶️ How to Run

This project includes an automated build & run script.

### Steps

1. Install a C++ compiler (`g++`) as described above.
2. Open the project folder.
3. Double-click the following file:
cpp-run.bat


### What the Batch File Does

- Checks for the C++ compiler (`g++`)
- Compiles `main.cpp`
- Runs the generated executable automatically

✅ No manual compilation is required.

---

## 🔁 Program Flow

1. Display introduction and instructions.
2. User selects:
- Language
- Encoding standard
- UTF encoding
- Output format
- Program mode
3. Text is retrieved or generated based on user selection.
4. Characters are converted into numeric values.
5. Results are displayed in the selected format.
6. User can:
- Run again with the same options
- Reselect all options
- Exit the program safely

---

## License

This project is licensed under the MIT License.  
© 2025 Mohammad Matin Kalantari

## Contact

Connect with me on LinkedIn: [M-M-Kalantari](https://www.linkedin.com/in/m-m-kalantari)
