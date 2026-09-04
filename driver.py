from iplfantasy import Player
from iplfantasy import FantasyPlayer

gill = FantasyPlayer("Chris Gayle", 22, 18, 0, 0, 0, 
        0, 0, 0, 1, 3, True, False)
gill.calcScore(gill)
gill.printFantasyScore()