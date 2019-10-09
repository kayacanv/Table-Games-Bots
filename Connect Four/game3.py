import pygame
from pygame.locals import *
import sys
import subprocess

if len(sys.argv) < 3:
    print "Kullanim: python game.py <1.oyuncu> <2.oyuncu>"
    sys.exit()
lookup = {
    K_1: 0,
    K_2: 1,
    K_3: 2,
    K_4: 3,
    K_5: 4,
    K_6: 5,
    K_7: 6,
}
p = []
p.append(sys.argv[1])
p.append(sys.argv[2])
red = (255, 0, 0)
blue = (0, 0, 255)
black = (0, 0, 0)
brown = (240,150,40)
darkBlue = (0,0,128)
magenta = (127,0,127)
white = (255, 255, 255)
purple = (75,0,130)
blueBg = (180,255,227)
maroon = (128,0,0)
redBg = (255,219,201)
purpleFg = (102,0,65)
purpleBg = (227,220,224)
pygame.init()
screen = pygame.display.set_mode((750, 750))
font =  pygame.font.SysFont("Calibri", 32)
piyon = ['A', 'B']
TURN = 0

board = []
for i in range(6):
    board.append([])
    for j in range(7):
        board[i].append('.')

def print_board(update):
    screen.fill(white)
    pygame.draw.rect(screen, brown, (0, 100, 850, 650))
    title = font.render("CONNECT FOUR", 1, black)
    screen.blit(title, (284, 6))
    text = font.render("{}".format(p[0]), 1, red)
    screen.blit(text, (70, 44))
    text = font.render("{}".format(p[1]), 1, blue)
    screen.blit(text, (570, 44))
    if TURN==0:
        pygame.draw.circle(screen,red,(52,60),12)
    else:
        pygame.draw.circle(screen,blue,(552,60),12)

    for i in range(6):
        for j in range(7):
            color = white
            x = i * 100 + 125 + 50
            y = j * 100 + 25 + 50
            if board[i][j] == "A":
                color = red
            if board[i][j] == "B":
                color = blue
            pygame.draw.circle(screen, color, (y, x), 45)

    if update:
        pygame.display.update()

def win_game(player_name):
    print_board(False)
    if player_name==0:
        pygame.draw.rect(screen, maroon, (244, 40, 260, 50))
        pygame.draw.rect(screen, redBg, (248,44,252,42))
        text = font.render("{} KAZANDI".format(p[player_name]), 1, red)
    else :
        pygame.draw.rect(screen, purple, (244, 40, 260, 50))
        pygame.draw.rect(screen, blueBg, (248,44,252,42))
        text = font.render("{} KAZANDI".format(p[player_name]), 1, blue)
    screen.blit(text, (272,50))
    pygame.display.update()
    while 1:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

def tie():
    print_board(False)
    pygame.draw.rect(screen, purpleFg, (244, 40, 260, 50))
    pygame.draw.rect(screen, purpleBg, (248,44,252,42))
    text = font.render("BERABERE", 1, magenta)
    screen.blit(text, (308, 50))
    pygame.display.update()
    while 1:
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                pygame.quit()
		sys.exit()

def get_board():
    change = {
        ".": ".",
        "A": "B",
        "B": "A"
    }
    res = ""
    for i in range(6):
        for j in range(7):
            if TURN == 1:
                res += change[board[i][j]]
            else:
                res += board[i][j]
        res += "\n"
    print res
    return res

def get_cli():
    proc = subprocess.Popen(["./{}".format(p[TURN])], stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.STDOUT)
    boardtext = "\n".join(get_board())
    get_stdout = proc.communicate(input=boardtext)
    return int(get_stdout[0])

def get_move():
    if '+' in p[TURN]:
        while 1:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                if event.type == KEYDOWN and event.key in lookup:
                    return lookup[event.key]
    else:
        return get_cli()

def add_board(m):
    print m
    if m < 0 or m > 6:
        win_game(1 - TURN)
    for i in range(6):
        if board[5-i][m] == '.':
            board[5-i][m] = piyon[TURN]
            return 5-i, m
    win_game(1-TURN)

def _check(x, y, yon):
    if board[x][y] == '.':
        return False
    sonx = x + yon[0] * 3
    sony = y + yon[1] * 3
    if sonx > 5 or sonx < 0:
        return False
    if sony > 6 or sony < 0:
        return False
    for i in range(4):
        if board[x + i * yon[0]][y + i * yon[1]] != board[x][y]:
            return False
    return True

def check():
    YON = [[0, 1], [1, 0], [1, 1], [-1, -1], [1, -1], [-1, 1], [-1, 0], [0, -1]]
    for i in range(6):
        for j in range(7):
            for yon in YON:
                if _check(i, j, yon):
                    return True
    return False

def checkTie():
    for i in range(6):
       for j in range(7):
          if board[i][j] == '.':
	      return False
    return True

def loop():
    global TURN
    print_board(True)
    x, y = add_board(get_move())
    TURN = 1 - TURN
    if check():
        win_game(1-TURN)
    if checkTie():
        tie()
    print_board(True)

def main():
    while 1:
        loop()

if __name__ == "__main__":
    main()
