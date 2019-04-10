#include <bits/stdc++.h>
using namespace std;

unsigned long long duplicatebits(unsigned long long n) {
    n = (n|(n<<16))&0x0000ffff0000ffff;
    n = (n|(n<<8))&0x00ff00ff00ff00ff;
    n = (n|(n<<4))&0x0f0f0f0f0f0f0f0f;
    n = (n|(n<<2))&0x3333333333333333;
    n = (n|(n<<1))&0x5555555555555555;
    return n|(n<<1);
}