from cs50 import get_float

# Declarar os valores da variáveis que representarão as moedas
# Penny => 1¢ \ Nickel = 5¢ \ Dime = 10¢ \ Quarter = 25¢
Q = 25
D = 10
N = 5
P = 1

# Agora, devo pedir o valor a ser decomposto
while True:
    c = round(get_float("Change: "), 2)
    if c > 0:
        break
c *= 100
# Agora devo fazer um loop para decompor o valor 'c'
i = 0
while c > 0:
    if c >= Q:
        c -= Q
        i += 1

    elif c >= D:
        c -= D
        i += 1

    elif c >= N:
    
        c -= N
        i += 1

    elif c >= P:
        c -= P
        i += 1
    else:
        break
print(i)
