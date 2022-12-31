#ifndef PERSISTENT_LIST_HPP
#define PERSISTENT_LIST_HPP

template <typename T>
class PersistentList
{
  private:
    struct Node;
    using Link = std::shared_ptr<Node>;
    struct Node {
      T elem;
      Link next;
    };

    Link head;

  public:
    ~PersistentList();
    PersistentList<T> tail();
    PersistentList<T> prepend(T elem);
    T *get_head();
};
#endif // PERSISTENT_LIST_HPP
