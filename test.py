class Solution(object):
  def addToArrayForm(self, A, K):
    v = ''.join([str(x) for x in A])
    v = int(v)
    v += K
    return [int(d) for d in str(v)]
        