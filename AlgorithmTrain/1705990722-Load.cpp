#include <iostream>
using namespace std;

int LoadGreedy(int w[], int c, int n, int* maxload) {
  int i = 1;
  int loadmax = 0, weight = 0, right = 0;
  int* x = new int[n + 1];

  for (int j = 1; j <= n; j++) {
    right += w[j];
  }
  while (true) {
    while (i <= n && weight + w[i] <= c) {
      right -= w[i];
      weight += w[i];
      x[i] = 1;
      i++;
    }
    if (i > n) {
      for (int j = 1; j <= n; j++) {
        *(maxload + j) = x[j];
      }
      loadmax = weight;
    } else

    {
      right -= w[i];
      x[i] = 0;
      i++;
    }
    while (weight + right <= loadmax) {
      i--;
      while (i > 0 && !x[i]) {
        right += w[i];
        i--;
      }

      if (i == 0) {
        delete[] x;
        return loadmax;
      }
      x[i] = 0;
      weight -= w[i];
      i++;
    }
  }
}

int main() {
  int n = 3, m;
  int c = 50, c2 = 50;
  int w[4] = {0, 10, 40, 40};
  int maxload[4];

  cout << "c1=" << c << ",c2=" << c2 << endl;
  cout << "wi=";
  for (int i = 1; i <= n; i++) {
    cout << w[i] << " ";
  }
  cout << endl;

  m = LoadGreedy(w, c, n, maxload);

  cout << "̰�Ļ��ݽ����" << endl;
  cout << "c1װ��������" << m << endl;
  cout << "  ѡ������";
  for (int i = 1; i <= n; i++) {
    cout << maxload[i] << " ";
  }

  cout << endl;
  int m2 = 0;
  for (int j = 1; j <= n; j++) {
    m2 = m2 + w[j] * (1 - maxload[j]);
  }
  cout << "c2װ��������" << m2 << endl;
  if (m2 > c2) {
    cout << "��Ϊc2��ת����������c2��װ������,���������޽⣡" << endl;
  }
  return 0;
}
