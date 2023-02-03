#include <iostream>

struct XOR_Node {
    int elem;
    XOR_Node* both;
};

XOR_Node* XOR_Node_create(int elem)
{
    XOR_Node* output = new XOR_Node();
    output->elem = elem;
    output->both = nullptr;
    return output;
}

XOR_Node* XOR_List_add(XOR_Node* first, XOR_Node* elem)
{
    XOR_Node* curr = first;
    XOR_Node* prev = nullptr;
    if(first == nullptr)
    {
        return elem;
    }
    while( (XOR_Node*)(((uintptr_t)curr->both ^ (uintptr_t)prev)) != nullptr)
    {
        XOR_Node* temp = prev;
        prev = curr;
        curr = (XOR_Node*)((uintptr_t)curr->both ^ (uintptr_t)temp);
    }
    elem->both = (XOR_Node*)((uintptr_t)curr ^ (uintptr_t)nullptr);
    curr->both = (XOR_Node*)((uintptr_t)prev ^ (uintptr_t)elem);
    return first;
}

XOR_Node* XOR_List_get(XOR_Node* first, int index)
{
    XOR_Node* curr = first;
    XOR_Node* prev = nullptr;
    if(first == nullptr)
    {
        return nullptr;
    }
    for(int i = 0; i < index; i++)
    {
        if( curr == nullptr )
        {
            return nullptr;
        }
        XOR_Node* temp = prev;
        prev = curr;
        curr = (XOR_Node*)((uintptr_t)curr->both ^ (uintptr_t)temp);
    }
    return curr;
}

int main(int argc, char const *argv[])
{
    XOR_Node* test = XOR_Node_create(1);
    XOR_Node* test2 = XOR_Node_create(2);
    test = XOR_List_add(test, test2);

    printf("%p\n", test);
    printf("%p\n", test2);

    printf("%p", XOR_List_get(test, 1));
    return 0;
}

