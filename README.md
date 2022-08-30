# Othello-Player
A C++ Othello game with a bot you can't beat

## Introduction
This is a small boarded version of the Othello board game. Feel free to look up the Othello game to familiarize yourself with the rules of the game and how it works. This program runs on a 4 x 4 board against the computer. The computer will always go first, and you second. The computer utilizes a minimax algorithm in order to optimize its decisions and always win. The board has to be smaller in order to support the performance of this algorithm and exploring all depths, although there are evaluation methods out there for determining favorable board states when not all decision depths are explored.

## What I Learned

### Minimax Algorithm
- consider each successor of the current game state (all possible next moves)
- iterate over each successor to calculate subsequent possible moves
- recur until leaf nodes are reached
- calculate and track the utility
- alternate between minimization and maximization for each level of the traversal's utility (representative of alternating player turns)
- make decision based off of best minimax utility for the original successors

## How to Use

### Compile
```
make
```

### Arguments and Running
The program takes two command line arguments: player 1 and player 2 types. For the purposes of demonstrating the minimax algorithm as a player against you, execute the following command

```
./othello human minimax
```

From there, the game is intuitive with instructions. Good luck winning!
