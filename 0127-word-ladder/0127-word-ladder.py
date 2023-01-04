class Solution:
    def ladderLength(self, begin: str, end: str, word_list: List[str]) -> int:
        if begin == end: return 1
        unvisited_words = set(word_list)
        if end not in word_list:
            return 0
        def get_neighbors(word):
            unvisited_neighbors = []
            for i in range(len(word)):
                # replace word[i] with every ascii letter
                for c in ascii_letters:
                    next_word = word[:i] + c + word[i + 1:]
                    if next_word in unvisited_words:  
                        unvisited_neighbors.append(next_word)
                        unvisited_words.remove(next_word) # mark next_word as visited
            return unvisited_neighbors

        queue = deque([begin])
        if begin in unvisited_words:
            unvisited_words.remove(begin) #set begin as visited, nocontain itself
        distance = 1
        while len(queue) > 0:   # if current level is non-empty
            n = len(queue)      # current level contains n nodes
            distance += 1
            for _ in range(n):  # only visit the nodes in the current level to keep track of distance
                word = queue.popleft()
                for w in get_neighbors(word):
                    if w == end: return distance
                    queue.append(w)
        return 0   # word ladder not found
