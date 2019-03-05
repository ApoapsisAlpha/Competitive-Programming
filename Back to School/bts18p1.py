first_sentence = input()
second_sentence = input()
k = int(input())


for i in range(len(first_sentence)):
    if first_sentence[i] == " " and second_sentence[i] != " " or first_sentence[i] != " " and second_sentence[i] == " ":
        k = -1
        break
    if first_sentence[i] != second_sentence[i]:
        k -= 1

if k >= 0:
    print("Plagiarized")
else:
    print("No plagiarism")