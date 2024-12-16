#include <stdio.h>

void taking_input(char *input, int size);
int calculate(int curpointer, char *input, int *string_length, char cur_operator);
void space_remover(char *input, int *string_length);
int str_length(const char *input);
int itsdigit(char checkme);
int itsspace(char checkme);
int string_to_integer(const char *input);
void integer_to_string(int num, char *str, int *index);

int main() {
    while (1) {
        char input[200]; 
        printf("Enter the expression: ");
        taking_input(input, sizeof(input));
        int string_length = str_length(input);
        if (string_length == 0 || (string_length == 1 && input[0] == '\n')) {
            printf("Empty expression.\n");
            continue;
        }
        if (input[string_length - 1] == '\n') {
            input[string_length - 1] = '\0';
            string_length--;
        }
        space_remover(input, &string_length);
        for (int curpointer = 0; curpointer < string_length; curpointer++) {
            if (input[curpointer] == '/' || input[curpointer] == '*') {
                int flag = calculate(curpointer, input, &string_length, input[curpointer]);
                if(!flag)
                    continue;
                curpointer = -1;
            }
        }
        for (int curpointer = 0; curpointer < string_length; curpointer++) {
            if (input[curpointer] == '+' || input[curpointer] == '-') {
                int flag = calculate(curpointer, input, &string_length, input[curpointer]);
                if(!flag)
                    continue;
                curpointer = -1; 
            }
        }
        printf("Result: %s\n", input);
    }
    return 0;
}

void taking_input(char *input, int size) {
    while (1) {
        if (!fgets(input, size, stdin)) {
            printf("Error reading input.\n");
            continue;
        }
        int valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!(itsdigit(input[i]) || itsspace(input[i]) || input[i] == '/' || input[i] == '*' || input[i] == '+' || input[i] == '-')) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            break;
        } else {
            printf("Invalid expression.\nPlease enter a valid expression: ");
        }
    }
}

int calculate(int curpointer, char *input, int *string_length, char cur_operator) {
    int left = 0, right = 0, leftpointer = curpointer - 1, rightpointer = curpointer + 1;
    while (leftpointer >= 0 && itsdigit(input[leftpointer])) {
        leftpointer--;
    }
    left = string_to_integer(&input[leftpointer + 1]);
    while (rightpointer < *string_length && itsdigit(input[rightpointer])) {
        rightpointer++;
    }
    right = string_to_integer(&input[curpointer + 1]);
    if (cur_operator == '/' && right == 0) {
        printf("Error: Division by zero.\n");
        return 0;  
    }
    int result = 0;
    if (cur_operator == '/') {
        result = left / right;
    } else if (cur_operator == '*') {
        result = left * right;
    } else if (cur_operator == '+') {
        result = left + right;
    } else if (cur_operator == '-') {
        result = left - right;
    }
    char updated[200];
    int updated_index = 0;
    for (int i = 0; i <= leftpointer; i++) {
        updated[updated_index++] = input[i];
    }
    integer_to_string(result, updated, &updated_index);  
    for (int i = rightpointer; i < *string_length; i++) {
        updated[updated_index++] = input[i];
    }
    updated[updated_index] = '\0';
    for (int i = 0; updated[i] != '\0'; i++) {
        input[i] = updated[i];
    }
    input[updated_index] = '\0';
    *string_length = str_length(input);
    return 1;
}

void space_remover(char *input, int *string_length) {
    int old_index = 0, new_index = 0;
    while (input[old_index]) {
        if (itsdigit(input[old_index]) || input[old_index] == '/' || input[old_index] == '*' || input[old_index] == '+' || input[old_index] == '-') {
            input[new_index++] = input[old_index];
        } else if (!itsspace(input[old_index])) {
            printf("Error: Invalid expression.\n");
            taking_input(input, 200);  
            return;
        }
        old_index++;
    }
    input[new_index] = '\0';
    *string_length = str_length(input);
}

int str_length(const char *input) {
    int length = 0;
    while (input[length]) {
        length++;
    }
    return length;
}

int itsdigit(char checkme) {
    return checkme >= '0' && checkme <= '9';
}

int itsspace(char checkme) {
    return checkme == ' ' || checkme == '\t' || checkme == '\n' || checkme == '\r';
}

int string_to_integer(const char *input) {
    int result = 0, pointer = 0, negative = 0;
    while (itsspace(input[pointer])) {
        pointer++;
    }
    if (input[pointer] == '-') {
        negative = 1;
        pointer++;
    }
    while (itsdigit(input[pointer])) {
        result = result * 10 + (input[pointer] - '0');
        pointer++;
    }
    if(negative)
        return -result;
    return result;
}

void integer_to_string(int num, char *str, int *index) {
    char temp[20];
    int temp_index = 0;
    int is_negative = 0;
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }
    if (num == 0) {
        temp[temp_index++] = '0';
    } else {
        while (num > 0) {
            temp[temp_index] = (num % 10) + '0';
            temp_index++;
            num /= 10;
        }
    }
    if (is_negative) {
        temp[temp_index] = '-';
        temp_index++;
    }
    for (int i = temp_index - 1; i >= 0; i--) {
        str[*index] = temp[i];
        (*index)++;
    }
}
