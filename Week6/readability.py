from cs50 import get_string

def main():
    text = get_string("Text: ")
    W = words(text)
    L = letters(text) / W * 100
    S = sentences(text) / W * 100
    index = int(round(0.0588 * L - 0.296 * S - 15.8))
    if index >= 16:
        print('Grade 16+')
    elif index < 1:
        print('Before Grade 1')
    else:
        print(f'Grade {index}')

def letters(text: str):
    nL = 0
    for ch in text:
        if ch.isalpha():
           nL += 1
    return nL

def words(text: str):
    nW = 1
    for ch in text:
        if ch.isspace():
            nW += 1
    return nW

def sentences(text: str):
    nS = 0
    for ch in text:
        if ch == '.' or ch == '!' or ch == '?':
            nS += 1
    return nS

main()
