#include <pthread.h>
#include <stdio.h>

void *run_func(void *arg){
  char *t_name = arg;
  for (int i = 0; i < 5; i++) {
    printf("%s: %d\n", t_name, i);
  }
  return NULL;}

int main() {
  printf("Launching threads\n");

  pthread_t t1;
  pthread_t t2;
  pthread_create(&t1, NULL, run_func, "thread 1");
  pthread_create(&t2, NULL, run_func, "thread 2");
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Threads complete!\n");
}