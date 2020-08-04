def isHappy(n):
    def get_next(number):
        return sum([int(d)**2 for d in str(number)])

    slow_runner = n
    fast_runner = get_next(n)
    while fast_runner != 1 and slow_runner != fast_runner:
        slow_runner = get_next(slow_runner)
        fast_runner = get_next(get_next(fast_runner))
    return fast_runner == 1
    
    

print(isHappy(19))