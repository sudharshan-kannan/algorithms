//
// Author           : skannan
// Timestamp        : 8/16/21, 2:20 PM
// Description      : A Linked List ADT
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_LINKEDLIST_H
#define ALGORITHMS_AND_DATA_STRUCTURES_LINKEDLIST_H

#include <memory>

namespace ADT {
    template <typename T> class LinkedList {
    public:
        typedef std::size_t size_type;
        typedef struct node_t{
            T val = T();
            std::shared_ptr<node_t> next;

            node_t() = default;
            explicit node_t(const T &item, std::shared_ptr<node_t> link):val(item),next(link){}
            ~node_t() = default;
        } Node;

        /* Constructors */
        LinkedList() = default;
        explicit LinkedList(const T &item) : first(std::make_shared<Node>(item, nullptr)), sz(1) {}

        /* Insert operations */
        void push_front(const T &item);
        void push_back(const T &item);
        void insert(const T &item, size_type pos);

        /* Remove operations */
        void erase_front();
        void erase_back();
        virtual T erase(size_type pos);

        /* Access APIs */
        virtual T &front() const;
        virtual T &back() const ;
        T &get(size_type pos) const;

        virtual size_type size() const{ return sz;}
        virtual bool empty() const { return sz == 0;}

        ~LinkedList() = default;
    protected:
        std::shared_ptr<Node> first;
        size_type sz{};

        void check(size_type pos, const std::string &msg) const{
            if(pos >= size())
                throw(std::out_of_range(msg));
        }
    };
}
#endif //ALGORITHMS_AND_DATA_STRUCTURES_LINKEDLIST_H
