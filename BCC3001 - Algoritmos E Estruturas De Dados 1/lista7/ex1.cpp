#include <iostream>
#include <vector>
#include <forward_list>
#include <stack>
#include <algorithm>

using namespace std;

// Suporte
void print_vector(vector<int> v)
{
    printf("Vector = [ ");
    for (size_t i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

void print_vector(vector<string> v)
{
    printf("Vector = [ ");
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    printf("]\n");
}

// Suporte
void printFwdList(forward_list<int> &fl)
{
    printf("Forward List = [ ");
    for (auto i : fl)
        cout << i << " ";
    cout << "]\n";
}

// Suporte
void printStack(stack<int> &stk)
{
    stack<int> temp = stk;
    printf("Stack = [ ");
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "]\n";
}

void printStack(stack<float> &stk)
{
    stack<float> temp = stk;
    printf("Stack = [ ");
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "]\n";
}

// Suporte
void printStack(stack<char> &stk)
{
    stack<char> temp = stk;
    printf("Stack = | ");
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "|  \n";
}

vector<int> vet_to_vector(int *v, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(v[i]);
    }
    return temp;
}

forward_list<int> vet_to_flist(int *v, int n)
{
    forward_list<int> temp;
    auto it = temp.before_begin(); // Usar quando a lista esta vazia
    for (int i = 0; i < n; i++)
    {
        temp.insert_after(it, v[i]);
        advance(it, 1);
    }
    return temp;
}

stack<int> vet_to_stack(int *v, int n)
{
    stack<int> temp;
    for (int i = n - 1; i >= 0; i--)
    {
        temp.push(v[i]);
    }
    return temp;
}

vector<int> list_concat(forward_list<int> &list1, forward_list<int> &list2)
{
    vector<int> temp;
    auto it = list1.begin();
    while (it != list1.end())
    {
        temp.push_back(*it);
        advance(it, 1);
    }

    it = list2.begin();
    while (it != list2.end())
    {
        temp.push_back(*it);
        advance(it, 1);
    }
    return temp;
}

int indexOf(vector<char> v, char item)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == item)
            return i;
    }
    return -1;
}

bool check_brackets(string expression)
{
    char item;
    int index = -1;
    stack<char> temp;
    vector<char> operations = {'+', '-', '*', '/'};
    vector<char> opens = {'(', '[', '{'};
    vector<char> closes = {')', ']', '}'};
    for (size_t i = 0; i < expression.size(); i++)
    {
        // printStack(temp);
        //  cout << expression[i] << "\n";
        if (isdigit(expression[i]) || std::find(operations.begin(), operations.end(), expression[i]) != operations.end())
            continue;
        if (std::find(opens.begin(), opens.end(), expression[i]) != opens.end())
        {
            temp.push(expression[i]);
            continue;
        }
        if (std::find(closes.begin(), closes.end(), expression[i]) != closes.end())
        {
            if (temp.empty())
                return false;
            item = temp.top();
            index = indexOf(closes, expression[i]);
            if (item != opens[index])
            {
                return false;
            }
            temp.pop();
        }
    }
    return temp.empty();
}

vector<string> vectorize_expression(string expression)
{
    vector<string> newVector;
    string element = "";
    size_t stringTam = expression.size();
    for (size_t i = 0; i < stringTam; i++)
    {
        if (expression[i] == ' ')
        {
            newVector.push_back(element);
            element = "";
            continue;
        }
        element = element + expression[i];
    }
    if (!element.empty())
    {
        newVector.push_back(element);
    }
    return newVector;
}

bool isStrDigit(string val)
{
    for (char c : val)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

float calc_posfix(string expression)
{
    vector<char> operations = {'+', '-', '*', '/'};
    vector<string> vecExp = vectorize_expression(expression);
    stack<float> pilha;
    float op1;
    float op2;
    for (size_t i = 0; i < vecExp.size(); i++)
    {
        if (isStrDigit(vecExp[i]))
        {
            pilha.push(stoi(vecExp[i]));
        }
        else
        {
            op2 = pilha.top();
            pilha.pop();
            op1 = pilha.top();
            pilha.pop();
            if (vecExp[i] == "+")
            {
                pilha.push(op1 + op2);
            }
            else if (vecExp[i] == "-")
            {
                pilha.push(op1 - op2);
            }
            else if (vecExp[i] == "*")
            {
                pilha.push(op1 * op2);
            }
            else if (vecExp[i] == "/")
            {
                pilha.push(op1 / op2);
            }
        }
    }
    return pilha.top();
}

bool check_posfix(string expression)
{
    vector<string> vecExp = vectorize_expression(expression);
    stack<float> pilha;
    for (size_t i = 0; i < vecExp.size(); i++)
    {
        if (isStrDigit(vecExp[i]))
        {
            pilha.push(stoi(vecExp[i]));
        }
        else
        {
            if (pilha.empty())
                return false;
            pilha.pop();
        }
    }
    if (pilha.empty())
        return false;
    pilha.pop();
    return pilha.empty();
}

float calc_infix(string expression)
{
    //"( ( ( 6 + 9 ) / 3 ) * ( 6 - 4 ) )"
    vector<char> operations = {'+', '-', '*', '/'};
    vector<string> vecExp = vectorize_expression(expression);
    stack<float> operands;
    stack<char> operators;
    float op1;
    float op2;
    char top;
    for (size_t i = 0; i < vecExp.size(); i++)
    {
        // cout<< "Processing: " << vecExp[i] << "\n";
        // printStack(operands);
        // printStack(operators);
        if (isStrDigit(vecExp[i]))
        {
            operands.push(stof(vecExp[i]));
        }
        else if (vecExp[i] == "(")
        {
            operators.push(vecExp[i][0]);
        }
        else if (std::find(operations.begin(), operations.end(), vecExp[i][0]) != operations.end())
        {
            operators.push(vecExp[i][0]);
        }
        else
        {
            while (operators.top() != '(')
            {
                op2 = operands.top();
                operands.pop();
                op1 = operands.top();
                operands.pop();
                top = operators.top();
                operators.pop();
                if (top == '+')
                {
                    operands.push(op1 + op2);
                }
                else if (top == '-')
                {
                    operands.push(op1 - op2);
                }
                else if (top == '*')
                {
                    operands.push(op1 * op2);
                }
                else if (top == '/')
                {
                    operands.push(op1 / op2);
                }
            }
            operators.pop();
        }
    }
    return operands.top();
}

string concatenate(string str1, string str2, string str3)
{
    return "( " + str1 + " " + str2 + " " + str3 + " )";
}

string posfix_to_infix(string expression)
{
    vector<char> operations = {'+', '-', '*', '/'};
    stack<string> pilha;
    vector<string> vecExp = vectorize_expression(expression);
    string op1;
    string op2;
    for (size_t i = 0; i < vecExp.size(); i++)
    {
        if (isStrDigit(vecExp[i]))
        {
            pilha.push(vecExp[i]);
        }
        else if (std::find(operations.begin(), operations.end(), vecExp[i][0]) != operations.end())
        {
            op2 = pilha.top();
            pilha.pop();
            op1 = pilha.top();
            pilha.pop();
            pilha.push(concatenate(op1, vecExp[i], op2));
        }
    }
    return pilha.top();
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vetor1 = vet_to_vector(arr1, 10);
    print_vector(vetor1);

    forward_list<int> forwardList = vet_to_flist(arr1, 10);
    printFwdList(forwardList);

    stack<int> stack = vet_to_stack(arr1, 10);
    printStack(stack);

    forward_list<int> fwl1 = {1, 2, 3, 4};
    forward_list<int> fwl2 = {5, 6, 7, 8};
    vector<int> vetorConcat = list_concat(fwl1, fwl2);
    print_vector(vetorConcat);

    string exp = "[(x + 8) * (9-2)]";
    bool valida = check_brackets(exp);
    cout << "A expressao e " << (valida ? "valida.\n" : "invalida.\n");

    string exp2 = "24 32 + 2 / 41 5 * +";
    vector<string> vectorized = vectorize_expression(exp2);
    print_vector(vectorized);

    float result = calc_posfix(exp2);
    cout << "Resultado: " << result << "\n";

    bool check = check_posfix(exp2);
    cout << "Valido?: " << (check ? "Sim" : "Nao") << "\n";

    string exp3 = "( ( ( 6 + 9 ) / 3 ) * ( 6 - 4 ) )";
    float result2 = calc_infix(exp3);
    cout << "Resultado: " << result2 << "\n";

    string exp4 = "24 32 + 2 / 41 5 * +";
    string result3 = posfix_to_infix(exp4);
    cout << exp4 << " -> |" << result3 << "|\n";
    return 0;
}