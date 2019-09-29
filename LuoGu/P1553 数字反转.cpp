#include <iostream>
using namespace std;
#define MAXSIZE 30

struct Stacks {
  char data[MAXSIZE];
  int top;
};

void stackpop(Stacks* str, int end) {
  int flag = 1;
  int ends = -1;
  if (end) {  //去除结尾的0
    while (1) {
      if (str->data[++ends] != '0' ||
          ends - 1 > str->top) {  //记录结尾有多少个0
        break;
      }
    }
  }

  while (1) {
    if (str->top == -1) {
      break;
    }
    if (end) {
      if (str->top == ends - 1) {
        if (flag)
          cout << str->data[str->top];
        str->top = -1;
        break;
      }
    }

    if (str->data[str->top] != '0') {
      flag = 0;  //标记前方
      cout << str->data[str->top];
    } else {
      if (!flag || str->top == 0)
        cout << str->data[str->top];
    }
    str->top--;
  }
}

int main() {
  string sss;
  Stacks str;
  str.top = -1;

  getline(cin, sss);
  int i = 0;
  int x = 0;
  while (1) {
    str.data[++str.top] = sss[i];
    if (str.data[str.top] == '\0') {
      str.top--;
      stackpop(&str, x);
      break;
    } else if (str.data[str.top] == '/') {
      char tmp = str.data[str.top--];
      stackpop(&str, x);
      cout << tmp;
    } else if (str.data[str.top] > '9' || str.data[str.top] < '0') {
      char tmp = str.data[str.top--];
      stackpop(&str, x);
      x++;
      cout << tmp;
    }
    i++;
  }
  return 0;
}