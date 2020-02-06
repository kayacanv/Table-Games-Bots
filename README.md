# Table-Games-Bots
Let our bots challenge each other


# Hex-Game-Usage

Written in python3 using pygame:

open terminal and enter to download pygame:
~~~
python3 -m pip install -U pygame --user
~~~

Do not forget to compile checker.cpp

## Usage
~~~
g++ checker.cpp -o checker
python3 hex.py ./player1_app ./player2_app
~~~
## example:
~~~
g++ checker.cpp -o checker

g++ hex_random.cpp -o player1

g++ hex_random.cpp -o player2

python3 hex.py ./player1 ./player2
~~~

## How you should write your bots:

your code should get input from stdin , and stdout example input for your bot is:

First line is N , the table size.

N next line is NxN table. 

The last line is your color.

1 is RED and red needs to connect top to bottom and 

2 is BLUE and blue needs to connect left to right

~~~
11
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 2 1
0 0 0 0 1 2 2 1 1 2 1
0 0 1 2 2 1 2 2 2 0 0
0 0 2 1 1 0 0 0 0 0 0
0 1 2 0 1 0 0 0 0 0 0
1 2 0 0 0 1 0 0 0 0 0
2 0 0 0 0 0 0 0 0 0 0
2
~~~

you should print 2 number x and y
~~~
3 10
~~~

And Blue(2) wins the game




