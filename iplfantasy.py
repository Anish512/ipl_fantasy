class Player:
    def __init__(self, n, nr, nbf, nrb, nbb, nw, w, d, nb, nwf, mf, o, h):
        self.name = n
        self.numRuns = nr
        self.numBallsFaced = nbf
        self.strikeRate = self.calcStrikeRate()
        self.numRunsBowled = nrb
        self.numBallsBowled = nbb
        self.econ = self.calcEconomy()
        self.numWickets = nw
        self.wides = w
        self.dots = d
        self.noBalls = nb
        self.numWicketsField = nwf
        self.misfieldRuns = mf
        self.out = o
        self.hatTrick = h
    def addRuns(self, runs, ballsFaced):
        self.numRuns += runs
        self.numBallsFaced += ballsFaced
    def bowlWide(self, runs):
        self.numRunsBowled += runs
        self.wides += runs
    def bowlNoBall(self, runs):
        self.numRunsBowled += runs
        self.noBalls += 1
    def bowlDot(self):
        self.dot += 1
    def addWicket(self):
        self.numWickets += 1
        self.numBallsBowled += 1
    def addFieldWicket(self):
        self.numWicketsField += 1
    def getOut(self):
        self.numBallsFaced += 1
        self.out = True
    def getName(self):
        return self.name
    def calcStrikeRate(self):
        if(self.numBallsFaced == 0):
            strikeRate = 0
        else:
            strikeRate = (1.0 * self.numRuns / self.numBallsFaced) * 100
        return strikeRate
    def calcEconomy(self):
        econ = 0 if (self.numBallsBowled == 0) else (self.numRunsBowled / (self.numBallsBowled / 6.0))
        return econ
class FantasyPlayer(Player):
    def __init__(self, n, nr, nbf, nrb, nbb, nw, w, d, nb, nwf, mf, o, h):
        Player.__init__(self, n, nr, nbf, nrb, nbb, nw, w, d, nb, nwf, mf, o, h)
        self.batScore = 0
        self.fieldScore = 0
        self.bowlScore = 0
        self.totalScore = 0
    def calcScore(self, p):
        self.totalScore = self.calcBatScore(p.numRuns, p.out, p.strikeRate, p.numBallsFaced) + self.calcBowlScore(p.numBallsBowled, p.econ, p.numWickets, p.dots, p.wides, p.noBalls, p.hatTrick) + self.calcFieldScore(p.numWicketsField, p.misfieldRuns)
    def calcBatScore(self, runs, out, sr, numFaced):
            
             
            self.batScore = runs
            h = runs
            i = 0
            while(h > 50):
                h -= 50
                i += 1
                self.batScore += 25 * int(i)
            h = runs
            i = 0
            while(h >= 75):
                h -= 50
                i += 1
                self.batScore += 10 * int(i)
            if(numFaced > 6):
                h = sr
                if(sr > 200):
                    self.batScore += 15
                    while(h > 200):
                        h -= 50
                        self.batScore += 15
                elif(sr > 175):
                    self.batScore += 15
            if(out):   
                if(runs == 0):
                    self.batScore -= 50
                elif(runs <= 10):
                    self.batScore -= 30
                elif(runs < 20):
                    self.batScore -= 10
            return self.batScore
    def calcBowlScore(self, numBowled, e, numWick, d, w, nb, h):
            
            self.bowlScore = 10.0 * numBowled - (numBowled * (5 / 6.0)) * e

            if(h):
                self.bowlScore += 50 * numWick
            else:
                self.bowlScore += 25 * numWick        
            self.bowlScore += d
            self.bowlScore -= 3 * w
            self.bowlScore -= 10 * nb
            return self.bowlScore
    def calcFieldScore(self, numWick, mfruns):
        self.fieldScore = (25 * numWick) - (5 * mfruns)
        return self.fieldScore
    def printFantasyScore(self):
            print(f"Name: {self.name}")
            print(f"Fantasy Points: {self.batScore} + {self.bowlScore} + {self.fieldScore} = {self.totalScore}") 
