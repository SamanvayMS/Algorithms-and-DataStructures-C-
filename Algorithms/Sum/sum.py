class sum:
    def __init__(self):
        self.cansummemo = {}
        self.howsummemo = {}
        self.bestsummemo = {}
        
    def clear(self):
        self.cansummemo = {}
        self.howsummemo = {}
        self.bestsummemo = {}
        
    def cansum_memoised(self, target, numbers):
        if target in self.cansummemo:
            return self.cansummemo[target]
        if target == 0:
            return True
        if target < 0:
            return False
        for num in numbers:
            remainder = target - num
            if self.cansum(remainder, numbers):
                self.cansummemo[target] = True
                return True
        self.cansummemo[target] = False
        return False
    
    def cansum(self, target, numbers):
        if target == 0:
            return True
        if target < 0:
            return False
        for num in numbers:
            remainder = target - num
            if self.cansum(remainder, numbers):
                return True
        return False
    
    def howsum(self, target, numbers):
        if target == 0:
            return []
        if target < 0:
            return None
        for num in numbers:
            remainder = target - num
            result = self.howsum(remainder, numbers)
            if result != None:
                result.append(num)
                return result
        return None
    
    def howsum_memoised(self, target, numbers):
        if target in self.howsummemo:
            return self.howsummemo[target]
        if target == 0:
            return []
        if target < 0:
            return None
        for num in numbers:
            remainder = target - num
            result = self.howsum_memoised(remainder, numbers)
            if result != None:
                result.append(num)
                self.howsummemo[target] = result
                return result
        self.howsummemo[target] = None
        return None
    
    def bestsum(self, target, numbers):
        if target == 0:
            return []
        if target < 0:
            return None
        shortest = None
        for num in numbers:
            remainder = target - num
            result = self.bestsum(remainder, numbers)
            if result != None:
                result.append(num)
                if shortest == None or len(result) < len(shortest):
                    shortest = result
        return shortest
    
    def bestsum_memoised(self, target, numbers):
        if target in self.bestsummemo:
            return self.bestsummemo[target]
        if target == 0:
            return []
        if target < 0:
            return None
        shortest = None
        for num in numbers:
            remainder = target - num
            result = self.bestsum_memoised(remainder, numbers)
            if result != None:
                result.append(num)
                if shortest == None or len(result) < len(shortest):
                    shortest = result
        self.bestsummemo[target] = shortest
        return shortest
    
    
if __name__ == "__main__":
    sum = sum()
    print("cansum")
    print(sum.cansum(7, [2, 3])) # True
    print(sum.cansum(7, [5, 3, 4, 7])) # True
    sum.clear()
    print(sum.cansum_memoised(7, [2, 3])) # True
    sum.clear()
    print(sum.cansum_memoised(7, [5, 3, 4, 7])) # True
    print("howsum")
    print(sum.howsum(7, [2, 3])) # [3, 2, 2]
    print(sum.howsum(7, [5, 3, 4, 7])) # [4, 3]
    sum.clear()
    print(sum.howsum_memoised(30, [2, 3])) 
    sum.clear()
    print(sum.howsum_memoised(30, [7, 21])) # None
    print("bestsum")
    print(sum.bestsum(7, [5, 3, 4, 7])) # [7]
    print(sum.bestsum(8, [2, 3, 5])) # [5, 3]
    sum.clear()
    print(sum.bestsum(100, [1,2,5,25])) # [25, 25, 25, 25]
    sum.clear()
    print(sum.bestsum_memoised(8, [2, 3, 5]))