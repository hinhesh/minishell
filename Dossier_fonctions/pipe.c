#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 /*
int main(void) {
  int pipefds[2];
 
  if(pipe(pipefds) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }
 
  printf("Read File Descriptor Value: %d\n", pipefds[0]);
  printf("Write File Descriptor Value: %d\n", pipefds[1]);
 
  return EXIT_SUCCESS;
}

// pipefds[0]read
//pipefds[1] write
int main(void) {
  int pipefds[2];
  char buffer[5];
 
  if(pipe(pipefds) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }
 
  char *pin = "4128\0";
 
  printf("Writing PIN to pipe...\n");
  write(pipefds[1], pin, 5);
  printf("Done.\n\n");
 
  printf("Reading PIN from pipe...\n");
  read(pipefds[0], buffer, 5);
  printf("Done.\n\n");
 
  printf("PIN from pipe: %s\n", buffer);
 
  return EXIT_SUCCESS;
}
int main(void) {
  int pipefds[2];
  char *pin;
  char buffer[5];
 
  if(pipe(pipefds) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }
 
  pid_t pid = fork();
 
  if(pid == 0) { // in child process
    pin = "4821\0"; // PIN to send
    close(pipefds[0]); // close read fd
    write(pipefds[1], pin, 5); // write PIN to pipe
 
    printf("Generating PIN in child and sending to parent...\n");
    sleep(2); // intentional delay
    exit(EXIT_SUCCESS);
  }
 
  if(pid > 0) { // in main process
    wait(NULL); // wait for child process to finish
    close(pipefds[1]); // close write fd
    read(pipefds[0], buffer, 5); // read PIN from pipe
    close(pipefds[0]); // close read fd
 
    printf("Parent received PIN '%s'\n", buffer);
  }
 
  return EXIT_SUCCESS;
}
*/
#define PIN_LENGTH 4
#define PIN_WAIT_INTERVAL 2
 
void getPIN(char pin[PIN_LENGTH + 1]) {
  srand(getpid() + getppid());
 
  pin[0] = 49 + rand() % 7;
 
  for(int i = 1; i < PIN_LENGTH; i++) {
    pin[i] = 48 + rand() % 7;
  }
 
  pin[PIN_LENGTH] = '\0';
}
 
 
int main(void) {
  while(1) {
    int pipefds[2];
    char pin[PIN_LENGTH + 1];
    char buffer[PIN_LENGTH + 1];
 
    pipe(pipefds);
 
    pid_t pid = fork();
 
    if(pid == 0) {
      getPIN(pin); // generate PIN
      close(pipefds[0]); // close read fd
      write(pipefds[1], pin, PIN_LENGTH + 1); // write PIN to pipe
 
      printf("Generating PIN in child and sending to parent...\n");
 
      sleep(PIN_WAIT_INTERVAL); // delaying PIN generation intentionally.
 
      exit(EXIT_SUCCESS);
    }
 
    if(pid > 0) {
      wait(NULL); // waiting for child to finish
 
      close(pipefds[1]); // close write fd
      read(pipefds[0], buffer, PIN_LENGTH + 1); // read PIN from pipe
      close(pipefds[0]); // close read fd
      printf("Parent received PIN '%s' from child.\n\n", buffer);
    }
  }
 
  return EXIT_SUCCESS;
}