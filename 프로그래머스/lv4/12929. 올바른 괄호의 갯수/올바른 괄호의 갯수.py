import math

def solution(n):
    answer = 0
    return math.factorial(2*n) // (math.factorial(n)*math.factorial(n+1))