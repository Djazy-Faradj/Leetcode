from collections import deque

class RecentCounter:

    def __init__(self):
        self.q = deque()

    def ping(self, t: int) -> int:
        self.q.appendleft(t)
        x = self.q.pop()
        while (x < (t-3000)):
            x = self.q.pop()
        self.q.append(x)
        return len(self.q)



# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)