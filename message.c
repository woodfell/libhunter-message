#include <stdio.h>
#include <libhunter-message/message.h>

void hunter_message(const char *parent)
{
  printf("hunter_message v1.0.0 (%s)\n", parent ?: "(none)");
}
