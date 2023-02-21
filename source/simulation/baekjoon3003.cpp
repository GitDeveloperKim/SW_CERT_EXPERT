#include <iostream>

using namespace std;

int main() {
    int chess[] = {1, 1, 2, 2, 2, 8};
    int king = 1;
    int queen = 1;
    int rook = 2;
    int bishop = 2;
    int knight = 2;
    int pawn = 8;
    
    scanf("%d %d %d %d %d %d", &king, &queen, &rook, &bishop, &knight, &pawn);
    printf("%d %d %d %d %d %d", chess[0]-king, chess[1]-queen, chess[2]-rook, chess[3]-bishop, chess[4]-knight, chess[5]-pawn);
    
    return 0;
}