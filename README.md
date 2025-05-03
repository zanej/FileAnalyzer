# FileAnalyzer
FileAnalyzer is a simple C++ command-line tool that reads a `.txt` file and provides the following analysis:

- Total number of lines
- Total number of words
- Total number of characters
- The most frequently occurring word

##  How to Compile and Run

1. **Compile** the code using g++:

```bash
g++ -o fileanalyzer main.cpp
```

2. **Run** the program and provide a `.txt` file:

```bash
./fileanalyzer
```

When prompted, enter a valid filename (e.g., `sample.txt`).

##  Example Input

Create a `sample.txt` file with the following:

```
Hello world!
This is a test.
Hello again.
```

##  Example Output

```
Total Lines: 3
Total Words: 8
Total Characters: 41
Most Common Word: 'hello' (2 times)
```
