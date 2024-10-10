#include <catch.hpp>
#include <iostream>

struct ListNode{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr) : value(value), prev(prev), next(next){
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List{
public:
    List() : m_head(new ListNode(static_cast<int>(0))), m_size(0), m_tail(new ListNode(0, m_head)) {}

    virtual ~List(){
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value){
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value){
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront(){
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack(){
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear(){
        auto current = m_head->next;
        while (current != m_tail){
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node){
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("Test push back") {
    INFO("Wrong push back method!");
    List non_empty_list;
    non_empty_list.PushBack(0);
    non_empty_list.PushBack(1);
    non_empty_list.PushBack(3);
    CHECK(non_empty_list.Size() == 3);
}

TEST_CASE("Test push front") {
    INFO("Wrong push front method!");
    List non_empty_list;
    non_empty_list.PushFront(0);
    non_empty_list.PushFront(1);
    non_empty_list.PushFront(3);
    CHECK(non_empty_list.Size() == 3);
}

TEST_CASE("Test pop back") {
    SECTION("Empty list") {
        INFO("Wrong pop back method for empty list!");
        CHECK_THROWS(List().PopBack());
    }
    SECTION("Non empty list") {
        INFO("Wrong pop back method for non empty list!");
        List non_empty_list;
        non_empty_list.PushBack(0);
        non_empty_list.PushBack(1);
        non_empty_list.PushBack(3);
        non_empty_list.PopBack();
        non_empty_list.PopBack();
        CHECK(non_empty_list.Size() == 1);
    }
}

TEST_CASE("Test pop front") {
    SECTION("Empty list") {
        INFO("Wrong pop front method for empty list!");
        CHECK_THROWS(List().PopFront());
    }
    SECTION("Non empty list") {
        INFO("Wrong pop front method for non empty list!");
        List non_empty_list;
        non_empty_list.PushBack(0);
        non_empty_list.PushBack(1);
        non_empty_list.PushBack(3);
        non_empty_list.PushBack(100);
        non_empty_list.PushBack(101);
        non_empty_list.PopFront();
        non_empty_list.PopFront();
        non_empty_list.PopFront();
        CHECK(non_empty_list.Size() == 2);
    }
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}