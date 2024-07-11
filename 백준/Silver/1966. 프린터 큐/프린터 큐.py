import sys
TC = int(sys.stdin.readline().rstrip())

for i in range(TC):
    N,M = map(int,sys.stdin.readline().split())
    doc = list(map(int,input().split()))
    dic = {}
    q = list(range(N))
    for i in range(N):
        dic[i] = doc[i]
    ret = 0
    while q:
        max_v = max(doc)
        if max_v == dic[q[0]]:
            ret += 1
            if q[0] == M:
                print(ret)
                break
            else:
                q.pop(0)
                doc.remove(max_v)
        else:
            q.append(q.pop(0))
