#include <iostream>
#include <array>

constexpr int width = 7;  // Largeur de la grille
constexpr int height = 6; // Hauteur de la grille

// Représente un état de la grille de jeu
using Grid = std::array<std::array<int, width>, height>;

// Affiche la grille de jeu à l'écran
void print_grid(const Grid& grid) {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      std::cout << grid[row][col] << " ";
    }
    std::cout << std::endl;
  }
}

// Vérifie si le joueur spécifié a gagné la partie
bool check_win(const Grid& grid, int player) {
  // Vérifie les lignes
  for (int row = 0; row < height; row++) {
    int count = 0;
    for (int col = 0; col < width; col++) {
      if (grid[row][col] == player) {
        count++;
        if (count == 4) {
          return true;
        }
      } else {
        count = 0;
      }
    }
  }

  // Vérifie les colonnes
  for (int col = 0; col < width; col++) {
    int count = 0;
    for (int row = 0; row < height; row++) {
      if (grid[row][col] == player) {
        count++;
        if (count == 4) {
          return true;
        }
      } else {
        count = 0;
      }
    }
  }

  // Vérifie les diagonales descendantes
  for (int row = 0; row < height - 3; row++) {
    for (int col = 0; col < width - 3; col++) {
      if (grid[row][col] == player &&
          grid[row + 1][col + 1] == player &&
          grid[row + 2][col + 2] == player &&
          grid[row + 3][col + 3] == player) {
        return true;
      }
    }
  }

  // Vérifie les diagonales montantes
  for (int row = 3; row < height; row++) {
    for (int col = 0; col < width - 3; col++) {
      if (grid[row][col] == player &&
          grid[row - 1][col + 1] == player &&
          grid[row - 2][col + 2] == player &&
          grid[row - 3][col + 3] == player) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  Grid grid{};  // Grille de jeu vide

  // Boucle principale du jeu
  while (true) {
    print_grid(grid);  // Affiche la grille

    // Demande au joueur
int main() {
  Grid grid{};  // Grille de jeu vide

  // Boucle principale du jeu
  while (true) {
    print_grid(grid);  // Affiche la grille

    // Demande au joueur où jouer son jeton
    int col;
    std::cout << "Entrez une colonne (0-" << width - 1 << ") : ";
    std::cin >> col;

    // Vérifie si la colonne est pleine
    if (grid[0][col] != 0) {
      std::cout << "Cette colonne est pleine, veuillez en choisir une autre." << std::endl;
      continue;
    }

    // Place le jeton dans la colonne choisie
    int row = height - 1;
    while (row >= 0 && grid[row][col] == 0) {
      row--;
    }
    grid[row + 1][col] = 1;

    // Vérifie si le joueur a gagné
    if (check_win(grid, 1)) {
      std::cout << "Le joueur 1 a gagné!" << std::endl;
      break;
    }

    // Si la grille est remplie, la partie est nulle
    bool grid_full = true;
    for (int col = 0; col < width; col++) {
      if (grid[0][col] == 0) {
        grid_full = false;
        break;
      }
    }
    if (grid_full) {
      std::cout << "Match nul!" << std::endl;
      break;
    }
  }

  return 0;
}
