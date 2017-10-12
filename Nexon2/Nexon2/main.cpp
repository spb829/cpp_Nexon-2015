//
//  main.cpp
//  Nexon2
//
//  Created by Macbook Pro on 2017. 10. 12..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int computer(int n1, int n2, bool isSum){
    vector<int> v1, v2;
    
    while (n1 || n2) {
        int v1n = n1 % 10;
        n1 /= 10;
        int v2n = n2 % 10;
        n2 /= 10;
        v1.push_back(v1n);
        v2.push_back(v2n);
    }
    
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    
    int m = 1;
    int result = 0;
    
    for (;it1 != v1.end() || it2 != v2.end(); it1++, it2++){
        int number = *it1;
        if (number != *it2){
            if (isSum)
                number += *it2;
            else
                number -= *it2;
        }
        
        number = number % 10;
        number *= m;
        if (number < 0)
            number = -number;
        
        result += number;
        m *= 10;
    }
    
    return result;
}

int solution(int n){
    list<int> l;
    l.push_back(0);
    l.push_back(1);
    
    int x = 1;
    
    for (int i = 1; i < n; i++){
        int n1 = *(l.begin());
        int n2 = *(++l.begin());
        l.push_back(n1 + n2);
        l.pop_front();
        
        if (x >= l.back())
            x = computer(x, l.back(), false);
        else
            x = computer(x, l.back(), true);
    }
    
    return x;
}

int main(int argc, const char * argv[]) {
    cout << solution(1000) << endl;
    return 0;
}
