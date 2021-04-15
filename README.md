# Fillit
Project in which we create a program that arranges the [tetrominos](https://en.wikipedia.org/wiki/Tetromino) given to it in a file in the smallest square possible. This project was our first touch with recursive programming. 

Pieces are to be placed as uppercase letters on the square in order they were in the file from `A` onwards. First piece will be placed as `A`'s next one as `B`'s and so on. Given tetrominos can't be rotated.

A simple `make` command in repository's root will compile the executable.

## Usage

```
./fillit test/test4
```

### Output

The command above would give following output:
```
A.BBD
AABBD
ACC.D
CC..D
.....
```

## Input

This is how the contents of the file that is passed to it looks like:
```
....
..#.
..##
..#.

....
.##.
.##.
....

....
....
..##
.##.

..#.
..#.
..#.
..#.

```

There are some rules the tetromino-file should obey in order for the program to accept it:

- There can be only one tetromino per square
- Squares in which the tetrominos are, has to be 4 by 4
- Squares has to consist of only dots (`.`) and pound signs (`#`)
- Tetromino must be exactly like one of the original tetrominos
- There has to be exactly one empty line after each tetromino

## The Program
The program takes a path of a file as it's only argument. After that it will extract the pieces from the file, trim excess dots away to speed up the fitting process and last but not least, finds arrangement that occupies the smallest square.

Our tetromino fitter uses recursion in fitting the pieces onto a square. It starts with smallest possible square and when it notices that the pieces won't fit, it resizes the square by 1 after which it starts to fit the pieces exactly like it did before. When the fillit places the tetromino it places them as uppercase letters corresponding their order in a file. The rest of the spots in the square that aren't filled with a piece will be dots (`.`).
