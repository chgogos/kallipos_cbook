#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

bool isPaused = false;
void togglePause(void) { isPaused = !isPaused; }

int main(int argc, char *argv[]) {
  if (argc > 2) {
    printf("Usage for 1 minute timer: %s\n", argv[0]);
    printf("Usage for <minutes> timer: %s <minutes>\n", argv[0]);
    return 1;
  }
  int duration = 60;
  if (argc == 2) {
    duration = atoi(argv[1]) * 60;
  }
  initscr(); // αρχικοποίηση της οθόνης
  cbreak();  // αρχικοποίηση της οθόνης
  noecho(); // απόκρυψη του χαρακτήρα που πληκτρολογεί ο χρήστης
  nodelay(stdscr, TRUE); // Κάνε τη getch() non-blocking

  time_t startTime = time(NULL); // Η ώρα έναρξης του timer
  int elapsed = 0;
  while (elapsed < duration) {
    int ch = getch();
    if (ch == 'p' || ch == 'P') {
      togglePause();
    } else if (ch == 'q' || ch == 'Q') {
      break;
    }
    if (!isPaused) {
      clear();
      printw("Timer: %d out of %d seconds remaining.", duration - elapsed,
             duration);
      printw("\nPress 'p' to pause/resume or 'q' to exit the timer.");
      refresh();
      napms(1000); // Περίμενε 1 δευτερόλεπτο
      elapsed = time(NULL) - startTime;
    }
  }
  endwin();
  return 0;
}
