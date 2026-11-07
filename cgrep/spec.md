# cGrep spec

## Milestone 1

**Your program must:**

1. Accept a search term and filename as command-line arguments.
2. Open the specified file.
3. Read it line by line.
4. Search each line for the supplied term.
5. Print every matching line.
6. Handle missing arguments.
7. Handle files that don't exist.
8. Handle empty files and files with no matches.
   _Use case-sensitive matching for now._

**Expected usage:**
`./cgrep hello tests/search_data/simple.txt`

**Expected output:**

```
Hello world
Hello again
Another hello here
```

**Concepts to learn:**

- argc and argv
- fopen() and fclose()
- fgets()
- strstr()
- NULL
- Basic pointers
- File error handling

**Completion criteria:**

```
* Program compiles without warnings
* Correctly searches simple.txt
* Correctly handles empty.txt
* Correctly handles no_matches.txt
* Handles nonexistent files
* Handles missing command-line arguments
* No memory or resource leaks
```
