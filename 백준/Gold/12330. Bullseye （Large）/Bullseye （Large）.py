import sys
import math
from decimal import Decimal, getcontext
N = int(input())
getcontext().prec = 50
for i in range(N):
    r, t = map(Decimal,sys.stdin.readline().split())
    if(r % 2 != 0):
        r = (r + 1) / 2
        answer = (-Decimal(1) + (Decimal(1) + Decimal(8) * (t + Decimal(2) * r * r - Decimal(3) * r + Decimal(1))).sqrt()) / Decimal(4)
    else:
        r = r / Decimal(2)
        answer = (-Decimal(3) + (Decimal(9) + Decimal(8) * (t + Decimal(2) * r * r - r - Decimal(1))).sqrt()) / Decimal(4)
    answer = answer.__floor__()
    print("Case #"+str(i+1)+":", int(answer - r + 1))
	