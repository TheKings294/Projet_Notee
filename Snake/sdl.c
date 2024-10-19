#include "snake.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


void display_game(SDL_Renderer* renderer, SDL_Texture* texture, TTF_Font *font,  char **tab, int lines, int score, int hightscore, int game) {
  int i = 0;
  int j = 0;
  char scoreText[20];
  char highScoreText[20];
  char gameText[20];


  SDL_Color color = {255, 255, 255, 255}; // Couleur du texte (blanc)
  snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
  snprintf(highScoreText, sizeof(highScoreText), "High score: %d", hightscore);
  snprintf(gameText, sizeof(gameText), "Partie: %d", game);
  SDL_Surface *scoreTextSurface = TTF_RenderText_Solid(font, scoreText, color);
  if (scoreTextSurface == NULL) {
    SDL_Log("Unable to render text surface: %s", TTF_GetError());
  }
  SDL_Surface *highScoreTextSurface = TTF_RenderText_Solid(font, highScoreText, color);
  if (highScoreTextSurface == NULL) {
    SDL_Log("Unable to render text surface: %s", TTF_GetError());
  }
  SDL_Surface *gameTextSurface = TTF_RenderText_Solid(font, gameText, color);
  if (gameTextSurface == NULL) {
    SDL_Log("Unable to render text surface: %s", TTF_GetError());
  }
  /*================================================================================*/
  SDL_Texture *scoreTextTexture = SDL_CreateTextureFromSurface(renderer, scoreTextSurface);
  SDL_FreeSurface(scoreTextSurface); // Libérer la surface après avoir créé la texture
  if (scoreTextTexture == NULL) {
    SDL_Log("Unable to create texture from surface: %s", SDL_GetError());
  }
  SDL_Texture *highScoreTextTexture = SDL_CreateTextureFromSurface(renderer, highScoreTextSurface);
  SDL_FreeSurface(highScoreTextSurface); // Libérer la surface après avoir créé la texture
  if (highScoreTextTexture == NULL) {
    SDL_Log("Unable to create texture from surface: %s", SDL_GetError());
  }
  SDL_Texture *gameTextTexture = SDL_CreateTextureFromSurface(renderer, gameTextSurface);
  SDL_FreeSurface(gameTextSurface); // Libérer la surface après avoir créé la texture
  if (gameTextTexture == NULL) {
    SDL_Log("Unable to create texture from surface: %s", SDL_GetError());
  }

  SDL_RenderClear(renderer);
  while(i < lines) {
    j = 0;
    while (j < 40) {
      if(tab[i][j] == '#') {
        SDL_Rect rect = {0, 0, 16, 16};
        SDL_Rect dist = {j * 16, i * 16, 16, 16};
        SDL_RenderCopy(renderer, texture, &rect, &dist);
      } else if(tab[i][j] == 'X') {
        SDL_Rect rect = {32, 0, 16, 16};
        SDL_Rect dist = {j * 16, i * 16, 16, 16};
        SDL_RenderCopy(renderer, texture, &rect, &dist);
      } else if(tab[i][j] == 'O') {
        SDL_Rect rect = {16, 0, 16, 16};
        SDL_Rect dist = {j * 16, i * 16, 16, 16};
        SDL_RenderCopy(renderer, texture, &rect, &dist);
      }
      else {

      }
      j++;

    }
    i++;
  }
  SDL_Rect scoreTextRect;
  scoreTextRect.x = 10; // Position x du texte
  scoreTextRect.y = 410; // Position y du texte
  SDL_QueryTexture(scoreTextTexture, NULL, NULL, &scoreTextRect.w, &scoreTextRect.h);
  SDL_Rect highScoreTextRect;
  highScoreTextRect.x = 200; // Position x du texte
  highScoreTextRect.y = 410; // Position y du texte
  SDL_QueryTexture(highScoreTextTexture, NULL, NULL, &highScoreTextRect.w, &highScoreTextRect.h);
  SDL_Rect gameTextRect;
  gameTextRect.x = 320; // Position x du texte
  gameTextRect.y = 410; // Position y du texte
  SDL_QueryTexture(gameTextTexture, NULL, NULL, &gameTextRect.w, &gameTextRect.h);

  SDL_RenderCopy(renderer, scoreTextTexture, NULL, &scoreTextRect);
  SDL_RenderCopy(renderer, highScoreTextTexture, NULL, &highScoreTextRect);
  SDL_RenderCopy(renderer, gameTextTexture, NULL, &gameTextRect);
  SDL_RenderPresent(renderer);
  SDL_DestroyTexture(scoreTextTexture);
  SDL_DestroyTexture(highScoreTextTexture);
  SDL_DestroyTexture(gameTextTexture);

}