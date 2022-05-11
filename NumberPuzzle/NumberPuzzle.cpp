#include <iostream>
#include <time.h>

#include <conio.h>

using namespace std;

int main()
{
    srand((unsigned int)time(0));

    int iNumber[25] = {};

    int iStarIndex = 24;

    for (int i = 0; i < 24; i++) {

        iNumber[i] = i + 1;

    }

    iNumber[24] = INT_MAX;

    int iTemp, idx1, idx2;

    for (int i = 0; i < 100; i++) {

        idx1 = rand() % 24;
        idx2 = rand() % 24;

        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;

    }

    while (true) {

        system("cls");

        for (int i = 0; i < 5; i++) {

            for (int j = 0; j < 5; j++) {

                if (iNumber[i * 5 + j] == INT_MAX) { cout << "\033[0;93m*\t"; }

                else { cout << "\033[0;33m" << iNumber[i * 5 + j] << "\t"; }

            }

            cout << endl << endl;

        }

        bool bWin = true;

        for (int i = 0; i < 24; ++i) {

            if (iNumber[i] != i + 1) {

                bWin = false;
                break;
            }

        }

        if (bWin == true) {

            cout << "\033[0;93m[!] 숫자를 모두 맞췄습니다!" << endl;
            break;

        }

        cout << "\033[0;97m[!] w : 위 | s : 아래 | a : 왼쪽 | d : 오른쪽 | q : 종료" << endl;

        char cInput = _getch();
        int iTemp;

        if (cInput == 'q' || cInput == 'Q') {

            break;

        }
        else if (cInput == 'w' || cInput == 'W') {

            if (iStarIndex > 4) {
            
                iTemp = iNumber[iStarIndex - 5];
                iNumber[iStarIndex - 5] = INT_MAX;
                iNumber[iStarIndex] = iTemp;

                iStarIndex = iStarIndex - 5;

            }

            continue;

        }
        else if (cInput == 's' || cInput == 'S') {

            if (iStarIndex < 20) {

                iTemp = iNumber[iStarIndex + 5];
                iNumber[iStarIndex + 5] = INT_MAX;
                iNumber[iStarIndex] = iTemp;

                iStarIndex = iStarIndex + 5;

            }

            continue;

        }
        else if (cInput == 'a' || cInput == 'A') {

            if (iStarIndex % 5 != 0) {

                iTemp = iNumber[iStarIndex - 1];
                iNumber[iStarIndex - 1] = INT_MAX;
                iNumber[iStarIndex] = iTemp;

                iStarIndex = iStarIndex - 1;

            }

            continue;

        }
        else if (cInput == 'd' || cInput == 'D') {

            if ((iStarIndex + 5) % 5 != 4) {

                iTemp = iNumber[iStarIndex + 1];
                iNumber[iStarIndex + 1] = INT_MAX;
                iNumber[iStarIndex] = iTemp;

                iStarIndex = iStarIndex + 1;

            }

            continue;

        }

    }

    cout << "\033[0;97m[!] 게임을 종료합니다." << endl;
    return 0;

}
