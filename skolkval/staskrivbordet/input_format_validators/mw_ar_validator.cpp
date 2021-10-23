//Problem: ståskrivbordet
//Komplexitet: O(x^2*n^3)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*dp[currentBrick][leftFootHeight][rightFootHeight][leftNumberOfBricks][rightNumberOfBricks] == true om och
**endast om det är möjligt att med hjälp av de currentBrick första brickorna bygga den vänstra högen så att
**den får höjd leftFootHeight och består av leftNumberOfBricks brickor, och bygga den högra högen så att
**den får höjd rightFootHeight och består av rightNumberOfBricks brickor
**
**I början är hela arrayen initialiserad till false
*/
bool dp[21][101][101][21][21];
int targetHeight, brickNumber;
vector<int> brickHeight;

//Returns true if test data works
bool validateInput(int bestTotalNumberOfBricks, int bestLeftNumberOfBricks, int bestRightNumberOfBricks){
	for (int leftNumberOfBricks = 0; leftNumberOfBricks <= brickNumber; ++leftNumberOfBricks){
		for (int rightNumberOfBricks = 0; rightNumberOfBricks <= brickNumber; ++rightNumberOfBricks){
			if (dp[brickNumber][targetHeight][targetHeight][leftNumberOfBricks][rightNumberOfBricks]){
				int totalNumberOfBricks = leftNumberOfBricks + rightNumberOfBricks;
				if (totalNumberOfBricks == bestTotalNumberOfBricks){
					if (leftNumberOfBricks == bestLeftNumberOfBricks && rightNumberOfBricks == bestRightNumberOfBricks)
						continue;
					if (rightNumberOfBricks == bestLeftNumberOfBricks && leftNumberOfBricks == bestRightNumberOfBricks)
						continue;
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	cin >> targetHeight >> brickNumber;
	for (int i = 0; i < brickNumber; ++i){
		int h;
		cin >> h;
		brickHeight.push_back(h);
	}

	//Det är detta state vi startar på
	dp[0][0][0][0][0] = true;

	//Dynamisk Programmering
	for (int currentBrick = 0; currentBrick < brickNumber; ++currentBrick){
		for (int leftFootHeight = 0; leftFootHeight <= targetHeight; ++leftFootHeight){
			for (int rightFootHeight = 0; rightFootHeight <= targetHeight; ++rightFootHeight){
				for (int leftNumberOfBricks = 0; leftNumberOfBricks <= currentBrick; ++leftNumberOfBricks){
					for (int rightNumberOfBricks = 0; rightNumberOfBricks <= currentBrick; ++rightNumberOfBricks){
						if (!dp[currentBrick][leftFootHeight][rightFootHeight][leftNumberOfBricks][rightNumberOfBricks]){
							//Vi kan inte nå detta state och fortsätter därför till nästa
							continue;
						}
						if (leftFootHeight + brickHeight[currentBrick] <= targetHeight){
							//Lägg till brickan på vänstra högen
							dp[currentBrick + 1][leftFootHeight + brickHeight[currentBrick]][rightFootHeight]
								[leftNumberOfBricks + 1][rightNumberOfBricks] = true;
						}
						if (rightFootHeight + brickHeight[currentBrick] <= targetHeight){
							//Lägg till brickan på vänstra högen
							dp[currentBrick + 1][leftFootHeight][rightFootHeight + brickHeight[currentBrick]]
								[leftNumberOfBricks][rightNumberOfBricks + 1] = true;
						}
						//Lägg inte till brickan på någon hög
						dp[currentBrick + 1][leftFootHeight][rightFootHeight]
							[leftNumberOfBricks][rightNumberOfBricks] = true;
					}
				}
			}
		}
	}

	//Vilket svar som helst kommer vara bättre än detta
	int bestTotalNumberOfBricks = brickNumber + 1;
	int bestLeftNumberOfBricks, bestRightNumberOfBricks;

	//Hitta det bästa svaret
	for (int leftNumberOfBricks = 0; leftNumberOfBricks <= brickNumber; ++leftNumberOfBricks){
		for (int rightNumberOfBricks = 0; rightNumberOfBricks <= brickNumber; ++rightNumberOfBricks){
			if (dp[brickNumber][targetHeight][targetHeight][leftNumberOfBricks][rightNumberOfBricks]){
				//Det går att lösa problemet genom att lägga leftNumberOfBricks brickor i den vänstra högen
				//och rightNumberOfBricks i den högra högen
				int totalNumberOfBricks = leftNumberOfBricks + rightNumberOfBricks;
				if (totalNumberOfBricks < bestTotalNumberOfBricks){
					//Uppdatera bästa lösningen
					bestTotalNumberOfBricks = totalNumberOfBricks;
					bestLeftNumberOfBricks = leftNumberOfBricks;
					bestRightNumberOfBricks = rightNumberOfBricks;
				}
			}
		}
	}

	return validateInput(bestTotalNumberOfBricks, bestLeftNumberOfBricks, bestRightNumberOfBricks)*42;
}

