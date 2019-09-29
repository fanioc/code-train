// P1036 选数
#include <cstdio>
#include <cmath>

using namespace std;

int a[25];
int f[2098000];
//f数组用来存储每个状态，表示每个下标对应的01串的时候，这个总和是多少。
//在状压中一定要注意的一个问题：一般状压只能适用于n <= 20的数据，再大可能就MLE了
//本题中的数据是n <= 20，状态总共有2^20，是2,097,152，保险一点开大点。

int chk(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
//用来判断是否是质数的函数。

int main(){
    int n,k,ans = 0;
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    //读入
    int q = pow(2, n);
    //求出一共有多少种状态

    //以下代码请认真理解！是状压的核心代码部分
    for(int i = 1; i <= q; i++){ //遍历每个状态
        int tmp = i, cnt = 1, tem = 0;
        int hm = 0;
        while(tmp){  //tmp代表的是目前的状态
            if(tmp & 1){  //如果目前的状态的最后一位是1
                tem += a[cnt]; //将a[cnt]加入temp
                hm++;  //选中的位数+1
            }
            cnt++;  //总共的位数+1
            tmp >>= 1;  //tmp右移
        }
        if((chk(tem)) && (hm == k)){//如果这个总和是素数并且选中的数的个数等于k
            ans++;
        }
        tem = 0;
        cnt = 0;
    }

    printf("%d",ans);
    return 0;
}