import pygame
from pygame.locals import *
import sys
import subprocess
import time
if len(sys.argv) < 3:
    print ("Kullanim: python game.py <1.oyuncu> <2.oyuncu>")
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
p.append("P NIN ILKE ELAMANI APPENDLI")
p.append(sys.argv[1])
p.append(sys.argv[2])
p.append("./checker")
N  = 11
red = (255, 0, 0)
blue = (0, 0, 255)
black = (0, 0, 0)
brown = black
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
piyon = ['1', '2']
TURN = 1
circle_radius=25
board = []
for i in range(N):
    board.append([])
    for j in range(N):
        board[i].append('0')
def draw_hex(x,y,color):
    sq32 = 0.863
    pygame.draw.polygon(screen, color, [(x,y-circle_radius),(x-circle_radius*sq32,y-circle_radius/2),(x-circle_radius*sq32,y+circle_radius/2),(x,y+circle_radius),(x+circle_radius*sq32,y+circle_radius/2),(x+circle_radius*sq32,y-circle_radius/2)], 0)
    pass

def print_board(update):
    screen.fill(white)
    pygame.draw.rect(screen, brown, (0, 100, 850, 650))
    title = font.render("Hex ", 1, black)
    screen.blit(title, (284, 6))
    text = font.render("{}".format(p[1]), 1, red)
    screen.blit(text, (70, 44))
    text = font.render("{}".format(p[2]), 1, blue)
    screen.blit(text, (570, 44))
    if TURN==0:
        pygame.draw.circle(screen,red,(52,60),12)
    else:
        pygame.draw.circle(screen,blue,(552,60),12)

    sq32 = 0.8635
    pygame.draw.line(screen,red,(0,110),(500,110),10)
    pygame.draw.line(screen,red,(0 + N*(circle_radius*sq32)  ,140+N*(circle_radius*sq32+circle_radius)),(0 + N*(circle_radius*sq32) + N *(circle_radius)* sq32*2 ,140+N*(circle_radius*sq32+circle_radius)),10)
    pygame.draw.line(screen,blue,(0,110),(0 + N*(circle_radius*sq32)-20  ,140+N*(circle_radius*sq32+circle_radius)),10)
    pygame.draw.line(screen,blue,(500,110),(20 + N*(circle_radius*sq32) + N *(circle_radius)* sq32*2 ,140+N*(circle_radius*sq32+circle_radius)),10)
    for i in range(N):
        for j in range(N):
            color = white
            x = i * (circle_radius*sq32) + j *(circle_radius+2)* sq32*2  + 25
            y = i * (circle_radius*sq32+circle_radius)+ 150
            if board[i][j] == 1:
                color = red
            if board[i][j] == 2:
                color = blue            
            draw_hex(x,y,color)
    if update:
        pygame.display.update()

def win_game(player_name):
    print_board(False)
    if player_name==1:
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
        "0": "0",
        "2": "1",
        "1": "2"
    }
    res = str(N) +"\n"
    for i in range(N):
        for j in range(N):
            res += str(board[i][j])+" "
        res += "\n"
#    print (res)
    return res

def get_cli(turn):
    proc = subprocess.Popen(["./{}".format(p[TURN])], stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.STDOUT)
    boardtext = get_board()
    boardtext += (str(TURN)) + "\n" 
    boardtext = boardtext.encode('utf-8')    
    get_stdout = proc.communicate(input=boardtext)
#    print("get_cli returns: ",[int(n) for n in get_stdout[0].split()] )
    return [int(n) for n in get_stdout[0].split()] 


def get_checker(turn,x,y):
    proc = subprocess.Popen(["./{}".format(p[3])], stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.STDOUT)
    boardtext = get_board()
    boardtext += (str(TURN) + " " + str(x) + " " + str(y)) + "\n" 
    boardtext = boardtext.encode('utf-8')    
#    print("SEND BOARD : \n", boardtext)
    get_stdout = proc.communicate(input=boardtext)
#    print("HATA" ,  get_stdout[0])
    return int(get_stdout[0].split()[0])


def loop():
    global TURN
    print_board(True)
    while True:
        move=get_cli(TURN)
        print(get_board())
        print("move: " ,move)
        winner=get_checker(TURN,move[0],move[1])
        print("winner: ",winner)
        if winner==0:
            board[move[0]][move[1]]=TURN
            break
        else:
            board[move[0]][move[1]]=TURN
            print_board(True)
            win_game(winner)
            time.sleep(6000)
            break
    TURN = 3-TURN
    time.sleep(1)
    print_board(True)

def main():
    while 1:
        loop()

if __name__ == "__main__":
    main()