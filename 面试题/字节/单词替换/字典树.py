class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = {}
        for word in dictionary:
            cur = trie
            for c in word:
                if c not in cur:
                    cur[c] = {}
                cur = cur[c]
            cur['#'] = {} #如果当前单词结束了，就在这一层字典树的节点中添加一个'#'

        words = sentence.split(' ')
        for i, word in enumerate(words):
            cur = trie
            for j, c in enumerate(word):
                if '#' in cur: #遍历时碰到#了，说明这一层对应一个前缀
                    words[i] = word[:j]
                    break
                if c not in cur:#如果搜索到这一层没有看到合适的匹配，说明前缀不存在
                    break
                cur = cur[c]
        return ' '.join(words)