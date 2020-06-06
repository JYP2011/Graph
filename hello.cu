#include<iostream>
using namespace std;
__global__ void hello() {
    printf("Hello world from device\n");
}

int main() {
    hello<<<1, 1>>>();
    cout << "Hello world from host" << endl;
    cudaDeviceSynchronize();
    return 0;
}
