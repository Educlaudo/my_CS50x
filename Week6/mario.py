from cs50 import get_int
def main():
    while True:
        h = get_int('Height: ')
        if h > 0 and h < 9:
            break
    j = h - 1
    b = h - j

    while True:
        jump(j)
        hash(b)
        print("  ", end="")
        hash(b)
        j -= 1
        b += 1
        print()
        if (j < 0):
            break

def jump(j: int):
    for _ in range(j):
        print(" ", end="")

def hash(b: int ):
    for _ in range(b):
        print("#", end="")



main()
