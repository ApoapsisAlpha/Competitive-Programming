class Computer:

    def __init__(self, args):
        self.name = args[0]
        self.value = 2*int(args[1]) + 3*int(args[2]) + int(args[3])

    def __str__(self):
        return self.name


n = int(input())
computers = [Computer(input().split()) for i in range(n)]

if len(computers) == 1:
    print(computers[0])

elif len(computers) > 1:
    computers.sort(key=lambda x: x.name)
    computers.sort(key=lambda x: x.value, reverse=True)

    print(computers[0])
    print(computers[1])