class TrieNode:
    def __init__(self):
        self.c = {}
        self.ct = 0
        self.e = 0
class Trie:
    def __init__(self):
        self.trie=TrieNode()

    def insert(self, w: str) -> None:
        t = self.trie
        for c in w:
            if c not in t.c:
                t.c[c]=TrieNode()
            t = t.c[c]
            t.ct+=1
        t.e+=1

    def countWordsEqualTo(self, w: str) -> int:
        t = self.trie
        for c in w:
            if c not in t.c:
                return 0
            t = t.c[c]
            # t.ct+=1
        return t.e
        

    def countWordsStartingWith(self, w: str) -> int:
        t = self.trie
        for c in w:
            if c not in t.c:
                return 0
            t = t.c[c]
            # t.ct+=1
        return t.ct
        

    def erase(self, w: str) -> None:
        t = self.trie
        for c in w:
            t = t.c[c]
            t.ct-=1
            # t.ct+=1
        t.e-=1
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.countWordsEqualTo(word)
# param_3 = obj.countWordsStartingWith(prefix)
# obj.erase(word)