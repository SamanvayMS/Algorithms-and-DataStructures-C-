import sys
import time

class GridTraveller():
    def __init__(self):
        self.memo = {}
        
    def grid_traveller(self, m, n):
        if m == 1 and n == 1:
            return 1
        if m == 0 or n == 0:
            return 0
        return self.grid_traveller(m-1, n) + self.grid_traveller(m, n-1)
    
    def grid_traveller_memo(self, m, n):
        key = str(m) + ',' + str(n)
        if key in self.memo:
            return self.memo[key]
        if m == 1 and n == 1:
            return 1
        if m == 0 or n == 0:
            return 0
        self.memo[key] = self.grid_traveller_memo(m-1, n) + self.grid_traveller_memo(m, n-1)
        return self.memo[key]
    
if __name__ == "__main__":
    g = GridTraveller()
    m , n = sys.argv[1], sys.argv[2]
    if len(sys.argv) != 3:
        print("Usage: python gridtraveller.py <m> <n>")
        sys.exit(1)
    print("Grid Traveller without memoization")
    t1 = time.time()
    print(g.grid_traveller(int(m), int(n)))
    t2 = time.time()
    print("Time taken: ", t2-t1)
    print("Grid Traveller with memoization")
    t3 = time.time()
    print(g.grid_traveller_memo(int(m), int(n)))
    t4 = time.time()
    print("Time taken: ", t4-t3)