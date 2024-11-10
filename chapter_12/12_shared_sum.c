//动态链接库
// gcc -shared -fPIC -Wl,--out-implib,lib12_shared_sum.a 12_shared_sum.c -o lib12_shared_sum.dll
// objdump -t 12_shared_sum.dll | grep sum2
int sum2(int a, int b) {
    return a + b;
}