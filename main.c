#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "libhydrogen/hydrogen.h"



#define MESSAGE_LEN 4096
#define CIPHERTEXT_LEN (hydro_secretbox_HEADERBYTES + MESSAGE_LEN)



char context[hydro_secretbox_CONTEXTBYTES] = {1};

char input[MESSAGE_LEN];


void *
thread(void * arg)
{
#if 1
  uint8_t ciphertext[CIPHERTEXT_LEN];
  uint8_t key[hydro_secretbox_KEYBYTES];
  hydro_secretbox_keygen(key);
  while(1) {
    hydro_secretbox_encrypt(ciphertext, input, MESSAGE_LEN, 0, context, key);
  }
#endif

  while(1) {
    asm volatile("nop");
  }
}


int
main(void)
{
  pthread_t tid;
  for(int i = 0; i < 12; i++) {
    pthread_create(&tid, NULL, thread, NULL);
  }
  pause();
  return 0;
}
