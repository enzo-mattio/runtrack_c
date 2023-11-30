// #include <stdio.h>

// Fonction principale pour résoudre le Sudoku
int solve_sudoku(int board[9][9]);

// Fonction pour trouver une case vide
int find_empty_location(int board[9][9], int *row, int *col);

// Fonction pour vérifier si un chiffre peut être placé dans une case
int is_safe(int board[9][9], int row, int col, int num);

// Fonction pour afficher le Sudoku
void print_sudoku(int board[9][9]);

//int main() {
//  int sudoku_board[9][9] = {
//          {5, 3, 0, 0, 7, 0, 0, 0, 0},
//          {6, 0, 0, 1, 9, 5, 0, 0, 0},
//          {0, 9, 8, 0, 0, 0, 0, 6, 0},
//          {8, 0, 0, 0, 6, 0, 0, 0, 3},
//          {4, 0, 0, 8, 0, 3, 0, 0, 1},
//          {7, 0, 0, 0, 2, 0, 0, 0, 6},
//          {0, 6, 0, 0, 0, 0, 2, 8, 0},
//          {0, 0, 0, 4, 1, 9, 0, 0, 5},
//          {0, 0, 0, 0, 8, 0, 0, 7, 9}
//  };
//
//  if (solve_sudoku(sudoku_board)) {
//    printf("Solution trouve :\n");
//    print_sudoku(sudoku_board);
//  } else {
//    printf("Aucune solution trouve.\n");
//  }
//
//  return 0;
//}

// Fonction principale pour résoudre le Sudoku
int solve_sudoku(int board[9][9]) {
  int row, col;

  if (!find_empty_location(board, &row, &col)) {
    return 1;  // Solution trouvée
  }

  for (int num = 1; num <= 9; num++) {
    if (is_safe(board, row, col, num)) {
      board[row][col] = num;

      if (solve_sudoku(board)) {
        return 1;  // Solution trouvée
      }

      board[row][col] = 0;  // Annuler le dernier placement s'il ne mène pas à une solution
    }
  }

  return 0;  // Aucune solution trouvée
}

// Fonction pour trouver une case vide
int find_empty_location(int board[9][9], int *row, int *col) {
  for (*row = 0; *row < 9; (*row)++) {
    for (*col = 0; *col < 9; (*col)++) {
      if (board[*row][*col] == 0) {
        return 1;  // Case vide trouvée
      }
    }
  }

  return 0;  // Aucune case vide trouvée
}

// Fonction pour vérifier si un chiffre peut être placé dans une case
int is_safe(int board[9][9], int row, int col, int num) {
  // Vérifie la ligne
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num) {
      return 0;  // Chiffre déjà présent dans la ligne
    }
  }

  // Vérifie la colonne
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == num) {
      return 0;  // Chiffre déjà présent dans la colonne
    }
  }

  // Vérifie la région 3x3
  int start_row = 3 * (row / 3);
  int start_col = 3 * (col / 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[start_row + i][start_col + j] == num) {
        return 0;  // Chiffre déjà présent dans la région 3x3
      }
    }
  }

  return 1;  // Chiffre peut être placé
}

// Fonction pour afficher le Sudoku
//void print_sudoku(int board[9][9]) {
//for (int i = 0; i < 9; i++) {
//  for (int j = 0; j < 9; j++) {
//     printf("%d ", board[i][j]);
//    }
//    printf("\n");
//  }
//}
