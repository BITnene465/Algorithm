import sys
sys.set_int_max_str_digits(100000)
def find_index(n: int) -> int:
    a = 1
    b = 1
    idx = 1
    while b < n:
        b, a = a+b, b
        idx += 1
    return idx    
while True:
    try:
        data = eval(input())
        print(find_index(data))
    except:
        break
