import os

tph, howhung, cho = 0, 0, 0
philname, status, hu = [0]*20, [0]*20, [0]*20

def main():
    global tph, howhung, cho
    os.system('clear')
    print("\n\nDINING PHILOSOPHER PROBLEM")
    tph = int(input("\nEnter the total no. of philosophers: "))
    for i in range(tph):
        philname[i] = i+1
        status[i] = 1
    howhung = int(input("How many are hungry: "))
    if howhung == tph:
        print("\n All are hungry..\nDead lock stage will occur")
        print("\nExiting\n")
    else:
        for i in range(howhung):
            hu[i] = int(input(f"Enter philosopher {i+1} position: "))
            status[hu[i]] = 2
        while True:
            print("\n1. One can eat at a time \t2. Two can eat at a time \t3. Exit \n Enter your choice: ", end = " ")
            cho = int(input())
            if cho == 1:
                one()
            elif cho == 2:
                two()
            elif cho == 3:
                exit(0)
            else:
                print("\n Invalid option!")

def one():
    pos = 0
    print("\n Allow one philosopher to eat at any time")
    for i in range(howhung):
        print(f"P{philname[hu[pos]]} is granted to eat")
        for x in range(pos, howhung):
            print(f"P{philname[hu[x]]} is waiting")
        pos += 1

def two():
    s = 0
    print("\nAllow two philosophers to eat at same time")
    for i in range(howhung):
        for j in range(i+1, howhung):
            if abs(hu[i] - hu[j]) >= 1 and abs(hu[i] - hu[j]) != 4:
                print(f"Combination {s+1}")
                t, r = hu[i], hu[j]
                s += 1
                print(f" P{philname[hu[i]]} and P{philname[hu[j]]} are granted to eat")
                for x in range(howhung):
                    if hu[x] != t and hu[x] != r:
                        print(f" P{philname[hu[x]]} is waiting")

if __name__ == "__main__":
    main()