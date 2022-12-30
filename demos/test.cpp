/*
 * @Author: bigconvience jbp.130@163.com
 * @Date: 2022-12-25 17:16:40
 * @LastEditors: bigconvience jbp.130@163.com
 * @LastEditTime: 2022-12-25 22:53:17
 * @FilePath: \demos\test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <map>

typedef struct T1 {char a; int b; char c[3]; } T;

int main() {
    // Write C++ code here
    std::cout << "Hello world!" << sizeof(T) << std::endl; 
    char c[2];
    std::cout << sizeof(c) << std::endl; 
    return 0;
}