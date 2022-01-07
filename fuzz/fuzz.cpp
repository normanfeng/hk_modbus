
#include <stdio.h>
#include <string.h>

#include "modbus.h"

int main(int argc, char *argv[])
{
  char *data = NULL;
  int len;
  FILE *f;

  long siz_buf;
  //printf("start...");
  /*cout << "Hello, world!" << endl; */
  if (argc > 1)
  {
    //printf("argc > 1 \n");
    f = fopen(argv[1], "rb");
    if (f == NULL)
    {
      //fprintf(stderr, "error opening input file %s\n", argv[1]);
      return -1;
    }

    fseek(f, 0, SEEK_END);
    siz_buf = ftell(f);
    rewind(f);
    if (siz_buf < 1)
      return -1;
    data = (char *)malloc((size_t)siz_buf);
    //printf("read out file=%s, size=%d\n", argv[1], siz_buf);
    if (data == NULL)
    {
      //fprintf(stderr, "malloc() failed\n");
      return -1;
    }
    if (fread(data, (size_t)siz_buf, 1, f) != 1)
    {
      //fprintf(stderr, "fread() failed\n");
      return -1;
    }
  }
  else
  {
    data = (char *)malloc(strlen("ABCDEFGH"));
    memset(data, 0, strlen("ABCDEFGH"));
    strcpy(data, "ABCDEFGH");
    len = strlen("ABCDEFGH");
    //printf("argc <= 1\n");
  }
  auto ok = checkModbusProto((const char *)data, len);
  printf("checkModbusProto\n");
  /*
  if (ok)
  {
    json j;

    auto ok2 = ModbusDecode((const char *)data, len, j);
    printf("ModbusDecode\n");
    if (ok2)
    {
      return -1;
    }
    auto ok3 = ModbusResponseDecode((const char *)data, len, j);
    printf("ModbusResponseDecode\n");
    if (ok3)
    {
      return -1;
    }
  }
*/
  return 0;
}