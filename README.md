# Student CGPA Calculator

A simple C program that reads student records (ID, name, and GPA in three courses) from an input text file, calculates each student's CGPA based on credit-weighted courses, and writes a formatted report to an output file.

## Features

- Reads student data (ID, name, and GPAs for CSE103, MAT101, ENG101) from a text file
- Calculates CGPA using credit-hour weighting:
  - CSE103 — 4.5 credits
  - MAT101 — 3 credits
  - ENG101 — 3 credits
- Validates that GPA values do not exceed 4.00
- Writes a neatly formatted, aligned report table to an output file

## Project Structure

```
Project_PC/
├── main.c              # Source code
├── student_input.txt   # Input data file
├── output.txt          # Generated report (created on run)
└── README.md
```

## Input File Format

`student_input.txt` should follow this format:

```
<number_of_students>
<student_id>
<student_name>
<cse103_gpa> <mat101_gpa> <eng101_gpa>
...
```

**Example:**

```
2
101
John Doe
3.8 3.5 4.0
102
Jane Smith
4.0 3.9 3.7
```

## Output

The program generates `output.txt` containing a formatted table:

```
---------------------------------------------------------------------------------------------------
ID          Name                 CSE103     MAT101     ENG101     CGPA
---------------------------------------------------------------------------------------------------
101         John Doe             3.80       3.50       4.00       3.78
102         Jane Smith           4.00       3.90       3.70       3.90
---------------------------------------------------------------------------------------------------
```

## CGPA Formula

```
CGPA = ((CSE103 × 4.5) + (MAT101 × 3) + (ENG101 × 3)) / (4.5 + 3 + 3)
```

## How to Build and Run

### Using GCC (command line)

```bash
gcc main.c -o main
./main
```

> **Note:** Make sure `student_input.txt` is in the same directory you run the executable from, since the program uses a relative file path. If you're running from a different working directory (e.g. via an IDE terminal), either `cd` into the project folder first or update the file path in `main.c`.

### Using VS Code

1. Open the project folder in VS Code.
2. Ensure a C/C++ compiler (e.g. MinGW/GCC) is installed and available on your `PATH`.
3. Run `main.c` using your preferred method (Run button, C/C++ Runner extension, or terminal).
4. Check the generated `output.txt` in the project folder.

## Requirements

- A C compiler (GCC recommended)
- `student_input.txt` present in the working directory before running

## Known Limitations

- Maximum of 100 student records (fixed-size array)
- Student names must fit within 50 characters
- GPA values above 4.00 are flagged as invalid but are still included in the output

## License

This project is open source and available for educational use.
