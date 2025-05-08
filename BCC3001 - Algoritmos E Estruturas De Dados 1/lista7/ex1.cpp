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
    printf("Stack = [ ");
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
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
        printStack(temp);
        // cout << expression[i] << "\n";
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
    return 0;
}