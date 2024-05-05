#include <iostream>
#include <vector>
#include <termios.h>
#include <unistd.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

int main() {
    int ms, bs, nob, ef, n, tif = 0, p = 0, i = 0;
    std::vector<int> mp(10);
    system("clear");
    std::cout << "Enter the total memory available (in Bytes) -- ";
    std::cin >> ms;
    std::cout << "Enter the block size (in Bytes) -- ";
    std::cin >> bs;
    nob = ms/bs;
    ef = ms - nob*bs;
    std::cout << "\nEnter the number of processes -- ";
    std::cin >> n;
    for(i=0; i<n; i++) {
        std::cout << "Enter memory required for process " << i+1 << " (in Bytes)-- ";
        std::cin >> mp[i];
    }
    std::cout << "\nNo. of Blocks available in memory--" << nob;
    std::cout << "\n\nPROCESS\tMEMORYREQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION";
    for(i=0; i<n && p<nob; i++) {
        std::cout << "\n " << i+1 << "\t\t" << mp[i];
        if(mp[i] > bs)
            std::cout << "\t\tNO\t\t---";
        else {
            std::cout << "\t\tYES\t" << bs-mp[i];
            tif = tif + bs-mp[i];
            p++;
        }
    }
    if(i < n) {
        std::cout << "\nMemory is Full, Remaining Processes cannot be accomodated";
        std::cout << "\n\nTotal Internal Fragmentation is " << tif;
        std::cout << "\nTotal External Fragmentation is " << ef << "\n";
        getch();
    }
}