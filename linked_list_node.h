template <typename T>
class linked_list;

template <typename T>
class linked_list_node {
  private:
  T m_value;
  linked_list_node<T>* m_prev_node;
  linked_list_node<T>* m_next_node;

  ~linked_list_node() = default;

  friend class linked_list<T>;

  public:
  linked_list_node(
    T value,
    linked_list_node<T>* prev_node = nullptr,
    linked_list_node<T>* next_node = nullptr
  ) {
    m_value = value;
    m_prev_node = prev_node;
    m_next_node = next_node;
  }

  T value() {
    return m_value;
  }
};