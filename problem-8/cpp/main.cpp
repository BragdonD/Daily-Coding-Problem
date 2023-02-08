#include <iostream>

class BT
{
    private:
        BT* left;
        BT* right;
        int value;
        
    public:
        BT();
        BT(int value);
        ~BT();
        BT* get_left();
        BT* get_right();
        int get_value();
        int get_subtree();
        void set_left(BT* left);
        void set_right(BT* right);
        bool check_universal();
};

BT::BT(): left(nullptr), right(nullptr), value(0){}
BT::BT(int value): left(nullptr), right(nullptr), value(value){}
BT::~BT() {}

BT* BT::get_left() {
    return left;
}

BT* BT::get_right() {
    return right;
}

int BT::get_value() {
    return value;
}

int BT::get_subtree()
{
    if(get_left() == nullptr && get_right() == nullptr)
    {
        return 1;
    }
    int subtree = 0;

    subtree += (int)(get_left()->get_subtree());
    subtree += (int)(get_right()->get_subtree());
    subtree += (int)(check_universal());

    return subtree;
}

bool BT::check_universal()
{
    if(get_left() == nullptr && get_right() == nullptr)
    {
        return true;
    }

    bool left = get_left()->check_universal();
    bool right = get_right()->check_universal();

    bool equal = (get_left()->get_value() == get_right()->get_value());

    return (left && right && equal);
}

void BT::set_left(BT* left) {
    this->left = left;
}

void BT::set_right(BT* right) {
    this->right = right;
}

int main(int argc, char const *argv[])
{
    BT* temp = new BT(0);
    temp->set_left(new BT(0));
    temp->set_right(new BT(0));
    temp->get_left()->set_right(new BT(0));
    temp->get_left()->set_left(new BT(1));
    std::cout << temp->get_subtree() << std::endl;
    return 0;
}