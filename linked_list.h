#include <assert.h>
#include "linked_list_node.h"

template <typename T>
class linked_list {
  private:
  linked_list_node<T>* m_head_node;
  linked_list_node<T>* m_tail_node;
  uint32_t m_size;

  void assert_template_type() {
    static_assert(
      sizeof(T) == sizeof(int) ||
      sizeof(T) == sizeof(double) ||
      sizeof(T) == sizeof(float) ||
      sizeof(T) == sizeof(char),
      "Ony the following types are allowed: int, double, float, char"
    );
  }

  friend void run_tests();

  public:
  linked_list() {
    assert_template_type();
    m_head_node = nullptr;
    m_tail_node = nullptr;
    m_size = 0;
  }

  ~linked_list() {
    auto node = m_head_node;
    while (node) {
      auto next_node = node->m_next_node;
      delete node;
      node = next_node;
    }
  }

  linked_list<T>& add(T item) {
    auto new_node = new linked_list_node<T>(item);
    if (!m_head_node) {
      m_head_node = m_tail_node = new_node;
    } else {
      m_tail_node->m_next_node = new_node;
      new_node->m_prev_node = m_tail_node;
      m_tail_node = new_node;
    }
    m_size++;
    return *this;
  }

  linked_list_node<T>* at(uint32_t index) {
    auto node = m_head_node;
    uint32_t i = 0;
    while (i < index) {
      node = node->m_next_node;
      i++;
    }
    if (node == nullptr) {
      std::cerr << "Index " << index << " is out of range\n";
      throw;
    }
    return node;
  }

  linked_list<T>& remove(linked_list_node<T>* node) {
    if (m_size == 0) return *this;
    if (m_head_node == node) {
      m_head_node = node->m_next_node;
    }
    if (m_tail_node == node) {
      m_tail_node = node->m_prev_node;
    }
    if (node->m_prev_node) {
      node->m_prev_node->m_next_node = node->m_next_node;
    }
    if (node->m_next_node) {
      node->m_next_node->m_prev_node = node->m_prev_node;
    }
    delete node;
    m_size--;
    return *this;
  }

  auto operator [] (uint32_t index) {
    return at(index);
  }

  auto& operator << (T value) {
    return add(value);
  }

  auto size() {
    return m_size;
  }
};
