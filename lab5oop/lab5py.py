import os

def main():
    tif = 0
    p = 0
    mp = [0]*10
    os.system('clear')
    ms = int(input("Enter the total memory available (in Bytes) -- "))
    bs = int(input("Enter the block size (in Bytes) -- "))
    nob = ms // bs
    ef = ms - nob * bs
    n = int(input("\nEnter the number of processes -- "))
    for i in range(n):
        mp[i] = int(input(f"Enter memory required for process {i+1} (in Bytes)-- "))
    print(f"\nNo. of Blocks available in memory--{nob}")
    print("\n\nPROCESS\tMEMORYREQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION")
    for i in range(n):
        if p < nob:
            print(f"\n {i+1}\t\t{mp[i]}", end="")
            if mp[i] > bs:
                print("\t\tNO\t\t---")
            else:
                print(f"\t\tYES\t{bs-mp[i]}")
                tif = tif + bs - mp[i]
                p += 1
    if i < n:
        print("\nMemory is Full, Remaining Processes cannot be accomodated")
    print(f"\n\nTotal Internal Fragmentation is {tif}")
    print(f"Total External Fragmentation is {ef}\n")
    input()

if __name__ == "__main__":
    main()