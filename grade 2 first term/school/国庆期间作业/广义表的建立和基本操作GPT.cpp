#include <iostream>
#include <cstring>
char s[1010];
int start = 0, end = -1;  // start - end 表示每次需要取的区间长度
void GetHead();  // Get the table head
void GetTail();  // Get the table tail
int main() {
    int ans = 0;
    memset(s, 0, sizeof(s));

    std::cin >> s; // 使用 std::cin 读取字符串
    std::cout << "generic list: " << s << std::endl;
    end = strlen(s) - 1;

    while (std::cin >> ans) { // 使用 std::cin 进行输入
        if (ans == 1) {  // 取表头
            GetHead();
        } else {  // 取表尾
            GetTail();
        }

        if (start == end) {  // 广义表仅剩原子，停止运行
            break;
        }
    }
    
    return 0;
}

void GetHead() {
    std::cout << "destroy tail\nfree list node\ngeneric list: ";
    int temp = -1;
    int i = start;  // 每次从上一次的位置开始取
    while (s[i] != '\0') {
        if (s[i] == '(') {
            temp++;
            if (temp == 0) {
                end = start = i + 1;
            }
            i++;
            continue;
        }
        if (s[i] == ')') {
            temp--;
            if (temp == 0) {  // 第一个左括号后面的第一对括号就是表头
                end = i;
                break;
            }
            i++;
            continue;
        }
        if (s[i] == ',' && temp == 0) { // 表中第一个逗号之前的，都是表头
            end = i - 1;
            break;
        }
        i++;
    }

    // 输出表头
    for (int j = start; j <= end; j++) {
        std::cout << s[j];
    }
    std::cout << std::endl;
}

void GetTail() {
    std::cout << "free head node\nfree list node\ngeneric list: ";
    int temp = -1;
    int vis = 0;
    int i = start;
    while (s[i] != '\0') {
        if (i == end) {  // 空表
            vis = 1;
            break;
        }
        if (s[i] == '(') temp++;
        if (s[i] == ')') temp--;
        if (s[i] == ',' && temp == 0) { // 表中的第一个逗号之后的，都是表尾
            s[i] = '(';
            start = i;
            break;
        }
        i++;
    }

    if (vis == 1) {  // 空表直接输出
        std::cout << "()\n";
        return;
    }

    // 输出表尾
    for (int j = start; j <= end; j++) {
        std::cout << s[j];
    }
    std::cout << std::endl;
}
