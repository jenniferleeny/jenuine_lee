#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define xres 500
#define yres 500
#define max_color 255

int main() {
  int i, j, x ,y; 
  char buffer[20] = "";
  int pic = open("colorful.ppm", O_CREAT | O_WRONLY, 0777);
  char header[256] = "P3 500 500 255 ";
  write(pic, header, strlen(header));
  
  int red = 100; int green = 150; int blue = 200;
  for (i = 0; i < xres ; i++) {
    for (j = 0 ; j < yres ; j++) {
      red++; green = green + i; blue = blue + j;
      red = red%max_color; green = green%max_color; blue = blue%max_color;
      sprintf(buffer, "%d %d %d ", red, green, blue);
      printf("buffer: %s\n", buffer);
      write(pic, buffer, strlen(buffer));
    }
  }
  int done = close(pic);
  if (done == -1)
    printf("ERROR!\n");
  return 0;
}
