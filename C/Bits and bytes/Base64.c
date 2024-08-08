#include <stdio.h>
#include <string.h>

void encode (const char *input, char *output)
{
  char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

  int input_length = strlen(input);
  int output_length = 4 * ((input_length + 2) / 3);

  int i = 0;
  int j = 0;
  while(i<input_length)
    {
      unsigned int a = i<input_length? (unsigned char)input[i++] : 0 ;
      unsigned int b = i<input_length? (unsigned char)input[i++] : 0 ;
      unsigned int c = i<input_length? (unsigned char)input[i++] : 0 ;

      unsigned int n = (a<<16)|(b<<8)|(c);
      output[j++] = base64_table[((n>>18)&63)];
      output[j++] = base64_table[((n>>18)&63)];
      output[j++] = base64_table[((n>>18)&63)];
      output[j++] = base64_table[((n>>18)&63)];
    }
    int padding = (3-(input_length%3))%3;
    for(int i = 0; i < padding; i++)
      {
        output[j++] = '=';
      }
     output[output_length]=  '\0';
}

int main()
{
  char input[100];
  printf("Enter a string to encode in Base64: ");
  scanf("%s", input);

  int output_length = 4 * ((strlen(input) + 2) / 3);
  char output[output_length + 1];

  encode(input, output);

  printf("Base64 Encoded: %s\n", output);

}
