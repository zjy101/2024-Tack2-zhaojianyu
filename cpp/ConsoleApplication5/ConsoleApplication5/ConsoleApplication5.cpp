#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>

// 比较运算符优先级
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

// 执行运算
int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return a % b;
    }
    return 0;
}

// 计算表达式的值
int CalValue(char* s) {
    std::stack<int> values;
    std::stack<char> ops;

    for (int i = 0; i < strlen(s); i++) {
        // 如果是空格，跳过
        if (s[i] == ' ')
            continue;

        // 如果是数字，提取完整数字
        if (isdigit(s[i])) {
            int val = 0;
            while (i < strlen(s) && isdigit(s[i])) {
                val = (val * 10) + (s[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }
        // 如果是左括号，直接压入运算符栈
        else if (s[i] == '(') {
            ops.push(s[i]);
        }
        // 如果是右括号，计算括号内的表达式
        else if (s[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            // 弹出左括号
            if (!ops.empty())
                ops.pop();
        }
        // 如果是运算符
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            // 压入当前运算符
            ops.push(s[i]);
        }
    }

    // 处理剩余的运算符
    while (!ops.empty()) {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    // 最终结果在栈顶
    return values.top();
}

int main() {
    char s[] = "15+(3-5)*7";
    int result = CalValue(s);
    std::cout << result << std::endl;
    return 0;
}