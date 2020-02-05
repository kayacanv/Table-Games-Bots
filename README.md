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
