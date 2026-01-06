s, a, b, x = map(int, input().split())

x
long = 0

#print(f"s: {s}, a: {a}, b: {b}, x: {x}")

while x >= 0:
    if x >= a:
        long += a*s
        x -= a
    
        #print(f"s: {s}, a: {a}, b: {b}, x: {x}")
    
    else:
        long += x*s
        #print(f"s: {s}, a: {a}, b: {b}, x: {x}")
        break
  
    if x >= b:
        x -= b
        #print(f"s: {s}, a: {a}, b: {b}, x: {x}")
    
    else:
        #print(f"s: {s}, a: {a}, b: {b}, x: {x}")
        break
  
print(long)