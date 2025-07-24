# Operating Systems Tutorial 4 - mini-project

Group Members:
- Anuj Shukla
- Nathaniel Kebere
- Riyan Faroqui
- Jun Bin Cheng
- Iqra Zahid

## Welcome to Jeopardy - A Command line Game you can play with your Friends!
### Overview
This project uses the C programming language to create a command-line versiob of the famous game Jeopardy!  Up to 4 players can compete in the game by choosing questions from several categories, providing structured answers, and receiving points for accuracy.  It also places a strong emphasis on teamwork and Synchronization through the use of GitHub for version control.

### Features
- Up to 4 players are supported
- A command-line interface that is interactive
- Participants choose categories and respond using the 'What is' or 'Who is' formats
- Player scores are dynamically tracked
- Prevents the occurrence of potentially choosing duplicate questions
- At the end of the game, the final rankings as well as the winners are displayed
- Implementation in C thats modular and uses organized source files and headers.
- Makefile to facilitate compilation.
- Improved input validity and error handling
- Better layout and instructions for an enhanced user experience

## Setup and Installation
### Prerequisites
Please make sure the following are installed:
- Make (to use the given Makefile)
- Git (optional for version control)

### Step by Step Guide on How to Run Our Project
#### 1. Repository Cloning
In order to download the project, open your terminal and run the following lines:
'''sh
git clone https://github.com/jb-cheng/Jeopardy.git
cd Jeopardy-main
'''

#### 2. Compiling the Program
Use the given Makefile to compile our project:
'''sh
make
'''
A file named 'jeopardy' will be generated. Make sure your compiler is configured correctly in the Makefile ('CC=gcc') if you experience any problems.

#### 3. Running Jeopardy
After the compilation is successful, run the game:
'''sh
./jeopardy
'''

For window users, use this:
'''sh
jeopardy.exe
'''

#### 4. Lets Start Playing
- Each player will be prompted to enter their name by the game.
- Players alternately choose categories and respond to inquiries.
- The format of the responses must be 'What is' or 'Who is'.
- At the conclusion of the game, the winner is announced and scores are tracked.

#### 5. Clean Up
To remove the compiled file, use this:
'''sh
make clean
'''

## File Structure
The following File Structure shows what each file is for and its file placement:

Jeopardy-main/
- Makefile
- README.md
- jeopardy.c
- jeopardy.h
- players.c
- players.h
- questions.c
- questions.h
- hello.c
- jeopardy.exe

## Rules and How to Play
1. 4 players are prompted to provide their names at the beginning of the game.
2. Each player chooses a category and dollar value in turn.
3. The relevant question is shown by our software.
4. The player who answers must use the proper format:
  For Instance: 'Who is Albert Einstein?' or 'What is Canada?'
5. The Application verifies the answer:
- Right Responses: points are awarded to player.
- Wrong answer: no points are given, right response is disclosed.
6. Until every question is addressed, the game goes on.
7. The program selects a winner and shows the final scores. 

## License
The project is not connected to the official Jeopardy! game; rather, it is an educational endeavour. Feel free to alter and enhance it for educational reasons. 
