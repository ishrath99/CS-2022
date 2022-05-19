inp = list(map(int, input().split()))
m = inp[0]
n = inp[1]
magazine = list(input().split())
letter = list(input().split())

out = "Yes"
for i in range(len(letter)):
    if letter[i] in magazine:
        magazine.remove(letter[i])
    else:
        out = "No"
        break

print(out)