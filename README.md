# BSQ

## AUTHORIZED FUNCTIONS

The only system calls allowed are the following ones:

- open
- read
- write
- close
- malloc
- free
- stat

## THE PROJECT

You must find the largest possible square on a board while avoiding obstacles.
The board can be generated two ways. The first one is by reading a file passed as the program’s argument.
The file is valid if it is respecting those constraints:

- its first line contains the number of lines on the board (and only that),
- “.” (representing an empty place) and “o” (representing an obstacle) are the only two characters for the other lines,
- all of the lines are of the same length (except the first one),
- it contains at least one line,
- each line is terminated by ‘\n’.

You program must print the board, with some “.” replaced by “x” to represent the largest square you found.

```text
If ever there are several solutions, you have to represent only the highest square.
If they are still several solutions, choose the square to the left.
```

## EXAMPLES

```text
∼/B-CPE-110> cat -e example_file
9$
...........................$
....o......................$
............o..............$
...........................$
....o......................$
..............o............$
...........................$
......o..............o.....$
..o.......o................$
```

```text
∼/B-CPE-110> ./bsq example_file
.....xxxxxxx................
....oxxxxxxx................
.....xxxxxxxo...............
.....xxxxxxx................
....oxxxxxxx................
.....xxxxxxx...o............
.....xxxxxxx................
......o...............o.....
..o.......o.................
```

```text
It’s definitely a square, even if visually it doesn’t look like one.
```

```text
You only need to read from the given files.
Meaning that your program should work even
if you don’t have the permissions to write on the files.
```

## GENERATING YOUR OWN

The second way to obtain a board is to generate one based on given parameters. The parameters will be a number, representing the width and height of the board, and a pattern that will be repeated line by line along the board.
You will print the solved board.

```text
∼/B-CPE-110> ./bsq 10 “...ooo...”
...oooxxx.
..ooo.xxx.
.ooo..xxx.
ooo......o
oo......oo
o......ooo
......ooo.
.....ooo..
....ooo...
...ooo....
```

## FINAL MARK

### Mark: 81 / 81 (100.0%)

- Algorithm app. - Generating column (3 / 3)
- Algorithm app. - Generating edges (2 / 2)
- Algorithm app. - Generating line (3 / 3)
- Algorithm app. - Generating square (3 / 3)
- Algorithm app. - Opening column (3 / 3)
- Algorithm app. - Opening edges (2 / 2)
- Algorithm app. - Opening line (3 / 3)
- Algorithm app. - Opening rectangle (3 / 3)
- Basics (6 / 6)
- Data structure - Generating (3 / 3)
- Data structure - Opening (3 / 3)
- Optimization - Generating 100 to 500 (4 / 4)
- Optimization - Generating 1000 to 2000 (2 / 2)
- Optimization - Generating 5000 to 10000 (2 / 2)
- Optimization - Opening 100 to 500 (4 / 4)
- Optimization - Opening 1000 to 2000 (2 / 2)
- Optimization - Opening 5000 to 10000 (2 / 2)
- Parsing - Opening (3 / 3)
- Robustness - Generating empty map (4 / 4)
- Robustness - Generating filled map (2 / 2)
- Robustness - Generating valid board (5 / 5)
- Robustness - Opening empty map (6 / 6)
- Robustness - Opening filled map (6 / 6)
- Robustness - Opening valid file (5 / 5)
