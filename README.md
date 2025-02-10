# Operating Systems Tutorial 4 - mini-project

GROUP 15  
- Anuj Shukla (100895219)
- Nathaniel Kebere (100868890)
- Riyan Faroqui (100869339)
- Jun Bin Cheng (100872055)
- Iqra Zahid (100824901)

## Welcome to Jeopardy - A Commandline Game you can play with your Friends!
### Overview
This project uses the C programming language to create a command-line versiob of the famous game Jeopardy! . Up to 4 players can compete in the game by choosing questions from several categories, providing structured answers, and receiving points for accuracy. The application ues numerous source files for improved code structure and adheres to the principles of modular development. It also places a strong emphasis on teamwork and Synchronization through the use of GitHub for version control.

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
In order to download the project, open your terminal and run this:
'''sh
git clone < ADD REPO LINK > 
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



